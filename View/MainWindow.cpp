// ─────────────────────────────────────────────
// View/MainWindow.cpp
// ─────────────────────────────────────────────
#include "MainWindow.h"

#include <QTime>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QMenuBar>
#include <QMenu>
#include <QFileDialog>
#include <QMessageBox>

#include "../Model/Attivita.h"
#include "../Model/Appuntamento.h"
#include "../Model/Compito.h"
#include "../Model/Promemoria.h"
#include "../Model/VisitorFiltroTipo.h"
#include "AbstractEditorAttivita.h"
#include "VisitorFormEdit.h"

namespace View {

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    inCreazione(false),
    indiceInModifica(-1)
{
    setupUI() ;
    setupMenu() ;
}

void MainWindow::setListaAbilitata(const bool abilitata){ 

    searchEdit->setEnabled(abilitata);

    filtroTipoCombo->setEnabled(abilitata);
    filtroStatoCombo->setEnabled(abilitata);
    filtroRangeCheck->setEnabled(abilitata);
    
    listWidget->setEnabled(abilitata);
    btnAggiungi->setEnabled(abilitata) ;
    btnModifica->setEnabled(abilitata);
    btnElimina->setEnabled(abilitata);
}

void MainWindow::setupUI() {
    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    QHBoxLayout* mainLayout = new QHBoxLayout(central) ;


    // parte sinistra
    QWidget* leftPanel = new QWidget(this) ;
    QVBoxLayout* leftLayout = new QVBoxLayout(leftPanel) ;

    searchEdit = new QLineEdit(this);
    searchEdit->setPlaceholderText("Cerca una attività...") ;

    filtroTipoCombo = new QComboBox(this);
    filtroTipoCombo->addItem("Tutti");
    filtroTipoCombo->addItem("Appuntamento") ;
    filtroTipoCombo->addItem("Compito");
    filtroTipoCombo->addItem( "Promemoria" );

    filtroStatoCombo = new QComboBox(this);
    filtroStatoCombo->addItem("Tutti");
    filtroStatoCombo->addItem("Solo scaduti");
    filtroStatoCombo->addItem("Solo non scaduti");

    filtroRangeCheck = new QCheckBox("Filtra con intervallo data", this) ;
    
    filtroDataDa = new QDateEdit(QDate::currentDate() , this) ;
    filtroDataDa->setCalendarPopup(true);
    filtroDataDa->setEnabled(false);
    
    filtroDataA = new QDateEdit( QDate::currentDate().addYears(1), this ) ;
    filtroDataA->setCalendarPopup(true);
    filtroDataA->setEnabled(false);

    QGroupBox* filtriBox = new QGroupBox("Filtri avanzati", this);
    QFormLayout* filtriLayout = new QFormLayout(filtriBox);
    
    filtriLayout->addRow("Tipo:", filtroTipoCombo);
    filtriLayout->addRow("Stato:", filtroStatoCombo);
    filtriLayout->addRow(filtroRangeCheck);
    filtriLayout->addRow("Da:", filtroDataDa);
    filtriLayout->addRow("A:", filtroDataA);

    listWidget = new QListWidget(this);
    btnAggiungi = new QPushButton( "Aggiungi", this) ;
    btnModifica = new QPushButton("Modifica",  this);
    btnElimina = new QPushButton("Elimina", this ) ;

    QHBoxLayout* btnLayout = new QHBoxLayout ;
    btnLayout->addWidget(btnAggiungi);
    btnLayout->addWidget(btnModifica);
    btnLayout->addWidget(btnElimina);

    leftLayout->addWidget(searchEdit);
    leftLayout->addWidget( filtriBox);
    leftLayout->addWidget(listWidget);
    leftLayout->addLayout(btnLayout) ;

    // parte destra
    stackedWidget= new QStackedWidget(this);

    // pagina 0: dettaglio
    detailBrowser = new QTextBrowser(this);
    stackedWidget->addWidget(detailBrowser);


    // pagina 1: form
    QWidget* formWidget = new QWidget(this);
    QVBoxLayout* formLayout = new QVBoxLayout(formWidget);
    QFormLayout* baseForm = new QFormLayout;

    descEdit = new QLineEdit(this);
    dateEdit = new QDateEdit(QDate::currentDate(), this);
    dateEdit->setCalendarPopup(true);
    tipoLabel = new QLabel("Tipo:", this);
    tipoCombo = new QComboBox(this);
    tipoCombo->addItem("Appuntamento");
    tipoCombo->addItem("Compito");
    tipoCombo->addItem("Promemoria");

    baseForm->addRow("Descrizione:", descEdit);
    baseForm->addRow("Data:", dateEdit);
    baseForm->addRow(tipoLabel, tipoCombo);

    // editor per tipo (ordine = ordine tipoCombo: 0 App, 1 Comp, 2 Prom)
    editorStack = new QStackedWidget(this);
    editorAppuntamento = new EditorAppuntamento(this);
    editorCompito = new EditorCompito(this);
    editorPromemoria = new EditorPromemoria(this);
    editorStack->addWidget(editorAppuntamento);   // indice 0
    editorStack->addWidget(editorCompito );        // indice 1
    editorStack->addWidget(editorPromemoria) ;     // indice 2

    btnSalvaForm = new QPushButton("Salva", this);
    btnAnnulla = new QPushButton("Annulla", this) ;
    QHBoxLayout* formBtnLayout = new QHBoxLayout;
    formBtnLayout->addWidget(btnSalvaForm);
    formBtnLayout->addWidget(btnAnnulla);

    formLayout->addLayout(baseForm);
    formLayout->addWidget(editorStack);
    formLayout->addLayout(formBtnLayout);
    formLayout->addStretch();

    stackedWidget->addWidget(formWidget);   // pagina 1

    mainLayout->addWidget(leftPanel, 1);
    mainLayout->addWidget(stackedWidget, 2) ;

    editorStack->setCurrentIndex(0);

    // connessioni 
    connect(searchEdit, &QLineEdit::textChanged, this, &MainWindow::onRicerca);
    connect(listWidget, &QListWidget::itemClicked, this, &MainWindow::onItemSelezionato);
    connect(btnAggiungi, &QPushButton::clicked, this, &MainWindow::onAggiungi);
    connect(btnModifica, &QPushButton::clicked, this, &MainWindow::onModifica);
    connect(btnElimina, &QPushButton::clicked, this, &MainWindow::onElimina);
    connect(tipoCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onTipoChanged);
    connect(btnSalvaForm, &QPushButton::clicked, this, &MainWindow::onSalvaForm);
    connect(btnAnnulla, &QPushButton::clicked, this, &MainWindow::onAnnulla);
    connect(filtroTipoCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onFiltroCambiato);
    connect(filtroStatoCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onFiltroCambiato);
    connect(filtroRangeCheck, &QCheckBox::toggled, this, &MainWindow::onFiltroCambiato);
    connect(filtroDataDa, &QDateEdit::dateChanged, this, &MainWindow::onFiltroCambiato);
    connect(filtroDataA, &QDateEdit::dateChanged, this, &MainWindow::onFiltroCambiato);

    setWindowTitle("Gestore Attività");
    resize(800, 500);
}

void MainWindow::setupMenu() {
    QMenu* fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction("Apri...", this, &MainWindow::onApriFile);
    fileMenu->addAction("Salva...", this, &MainWindow::onSalvaFile);
}

void MainWindow::aggiornaLista(const QString& filtro) {
    listWidget->clear();

    int tipoFiltro = filtroTipoCombo->currentIndex();    // 0=tutti,1=App,2=Comp,3=Prom

    int statoFiltro = filtroStatoCombo->currentIndex();  //0=tutti,1=scaduti,2=non scaduti
    bool rangeAttivo = filtroRangeCheck->isChecked();
    QDate dataDa = filtroDataDa->date();
    QDate dataA = filtroDataA->date();

    for (int i = 0; i < registro.size(); ++i) {
        Model::Attivita* a = registro.get(i);

        // filtro testo (case-insensitive)
        if (!filtro.isEmpty() && !a->getDescrizione().contains(filtro, Qt::CaseInsensitive)) {
            continue;
        }
        // filtro tipo via Visitor (no getType/dynamic_cast)
        if (tipoFiltro > 0) {
            Model::VisitorFiltroTipo v(tipoFiltro - 1);
            a->accetta(v);
            if (!v.isTrovato()) {
                continue;
            }
        }
        // filtro stato via polimorfismo isScaduta
        if (statoFiltro == 1 && !a->isScaduta()) {
            continue;
        }
        if (statoFiltro == 2 && a->isScaduta()) {
            continue;
        }
        // filtro intervallo data
        if (rangeAttivo) {
            QDate d = a->getData();
            if (d < dataDa || d > dataA) {
                continue;
            }
        }

        QListWidgetItem* item = new QListWidgetItem(a->getDescrizione());
        item->setData(Qt::UserRole, i);
        if (a->isScaduta()) {
            item->setForeground(Qt::red);
        }
        listWidget->addItem(item);
    }
}

void MainWindow::onFiltroCambiato() {
    filtroDataDa->setEnabled(filtroRangeCheck->isChecked());
    filtroDataA->setEnabled(filtroRangeCheck->isChecked());
    aggiornaLista(searchEdit->text());
}

void MainWindow::mostraDettaglio(const int indice) {

    detailBrowser->setText(registro.get(indice)->getInfo());
    stackedWidget->setCurrentIndex(0);

}
void MainWindow::mostraFormCreazione(){

    inCreazione = true;
    indiceInModifica = -1;
    descEdit->clear();
    dateEdit->setDate(QDate::currentDate());
    tipoLabel->setVisible(true);
    tipoCombo->setVisible(true);
    tipoCombo->setCurrentIndex(0);
    editorStack->setCurrentIndex(0);

    // reset campi degli editor riusando setValues con valori di default
    editorAppuntamento->setValues(Model::Appuntamento("", QDate::currentDate(), QTime::currentTime(), ""));
    editorCompito->setValues(Model::Compito("", QDate::currentDate(), false));
    editorPromemoria->setValues(Model::Promemoria("", QDate::currentDate(), 1));
    setListaAbilitata(false);
    stackedWidget->setCurrentIndex(1);
}
void MainWindow::mostraFormModifica(const int indice) {
    inCreazione = false;
    indiceInModifica = indice;
    descEdit->setText(registro.get(indice)->getDescrizione());
    dateEdit->setDate(registro.get(indice)->getData());
    tipoLabel->setVisible(false);
    tipoCombo->setVisible(false);

    // inserimento widget e selezione pagina
    VisitorFormEdit injector(*editorStack, *editorAppuntamento, *editorCompito, *editorPromemoria) ;
    registro.get(indice)->accetta(injector);
    setListaAbilitata(false);
    stackedWidget->setCurrentIndex(1);
}

void MainWindow::onItemSelezionato(QListWidgetItem* item) {
    int indice = item->data(Qt::UserRole).toInt();
    mostraDettaglio(indice);
}

void MainWindow::onRicerca(const QString& testo) {
    aggiornaLista(testo);
}

void MainWindow::onAggiungi() {
    mostraFormCreazione();
}

void MainWindow::onModifica() {
    QListWidgetItem* selected = listWidget->currentItem();
    if (selected == nullptr) {
        return;
    }
    int indice = selected->data(Qt::UserRole).toInt();
    mostraFormModifica(indice);
}

void MainWindow::onElimina() {
    QListWidgetItem* selected = listWidget->currentItem();
    if (selected == nullptr) {
        return;
    }

    int indice = selected->data(Qt::UserRole).toInt();

    QMessageBox::StandardButton risposta = QMessageBox::question(this, "Conferma",
        "Eliminare l'attività selezionata?");
    if (risposta != QMessageBox::Yes) {
        return;
    }
    registro.rimuovi(indice);
    detailBrowser->clear();
    stackedWidget->setCurrentIndex(0);
    aggiornaLista(searchEdit->text());
}

void MainWindow::onTipoChanged(int index) {
    editorStack->setCurrentIndex(index);
}

void MainWindow::onSalvaForm() {
    QString descrizione = descEdit->text().trimmed();
    if (descrizione.isEmpty()) {
        QMessageBox::warning(this, "Errore", "La descrizione non può essere vuota.");
        return;
    }
    QDate data = dateEdit->date();

    AbstractEditorAttivita* editor = static_cast<AbstractEditorAttivita*>(editorStack->currentWidget());

    if (inCreazione) {
        registro.aggiungi(editor->crea(descrizione, data));
    } else {
        if (indiceInModifica < 0 || indiceInModifica >= registro.size()) {
            return;
        }
        registro.sostituisci(indiceInModifica, editor->crea(descrizione, data));
    }

    indiceInModifica = -1;
    setListaAbilitata(true);
    aggiornaLista(searchEdit->text() );
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::onAnnulla() {
    indiceInModifica = -1;
    setListaAbilitata(true);
    stackedWidget->setCurrentIndex(0);
}

void MainWindow::onApriFile() {
    QString percorso = QFileDialog::getOpenFileName(this, "Apri file", QString(), "File JSON (*.json)");
    if (percorso.isEmpty()) {
        return;
    }
    if (!registro.carica(percorso)) {
        QMessageBox::warning(this, "Errore", "Impossibile aprire il file: mancante o JSON non valido.");
        return;
    }
    detailBrowser->clear();
    stackedWidget->setCurrentIndex(0);
    aggiornaLista();
}

void MainWindow::onSalvaFile() {
    QString percorso = QFileDialog::getSaveFileName(this, "Salva file", QString(), "File JSON (*.json)");
    if (percorso.isEmpty()) {
        return;
    }
    if (!registro.salva(percorso)) {
        QMessageBox::warning(this, "Errore", "Impossibile salvare il file.") ;
    }
}

}