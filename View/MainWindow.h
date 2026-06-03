// ─────────────────────────────────────────────
// View/MainWindow.h
// ─────────────────────────────────────────────
#ifndef VIEW_MAIN_WINDOW_H
#define VIEW_MAIN_WINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QDateEdit>
#include <QListWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QTextBrowser>
#include <QLabel>

#include "../Model/Registro.h"
#include "EditorAppuntamento.h"
#include "EditorCompito.h"
#include "EditorPromemoria.h"

namespace View {

class MainWindow: public QMainWindow{
    Q_OBJECT
  private:
    Model::Registro registro;

    // parte sinistra
    QLineEdit* searchEdit;
    QComboBox* filtroTipoCombo ;
    QComboBox* filtroStatoCombo;
    QCheckBox* filtroRangeCheck;
    QDateEdit* filtroDataDa;
    QDateEdit* filtroDataA;
    QListWidget* listWidget;
    QPushButton* btnAggiungi;
    QPushButton* btnModifica ;
    QPushButton* btnElimina;

    // parte destra
    QStackedWidget* stackedWidget;   // 0=dettaglio, 1=form
    QTextBrowser* detailBrowser;

    // campi in comune del form
    QLineEdit* descEdit;
    QDateEdit* dateEdit;
    QLabel* tipoLabel ;
    QComboBox* tipoCombo;

    // form in base alla tipologia
    QStackedWidget* editorStack;
    EditorAppuntamento* editorAppuntamento;
    EditorCompito* editorCompito;
    EditorPromemoria* editorPromemoria ;

    QPushButton* btnSalvaForm;
    QPushButton* btnAnnulla;

    bool inCreazione;
    int indiceInModifica;   // -1 se nessuno

    void setupUI();
    void setupMenu();
    void aggiornaLista(const QString& filtro = QString() ) ;
    void mostraDettaglio(const int indice);
    void mostraFormCreazione();
    void mostraFormModifica(const int indice);
    void setListaAbilitata(const bool abilitata);

  private slots:
    void onItemSelezionato(QListWidgetItem* item ) ;
    void onRicerca(const QString& testo);
    void onAggiungi();
    void onModifica();
    void onElimina();
    void onTipoChanged(int index);
    void onSalvaForm();
    void onAnnulla() ;
    void onApriFile();
    void onSalvaFile();
    void onFiltroCambiato() ;

  public:
    MainWindow(QWidget* parent = nullptr);
};
}

#endif // VIEW_MAIN_WINDOW_H