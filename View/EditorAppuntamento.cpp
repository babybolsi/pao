// ─────────────────────────────────────────────
// View/EditorAppuntamento.cpp
// ─────────────────────────────────────────────
#include "EditorAppuntamento.h"

#include <QFormLayout>

namespace View {

EditorAppuntamento::EditorAppuntamento(QWidget* parent)
    : AbstractEditorAttivita(parent),
    orarioEdit(new QTimeEdit(QTime::currentTime(), this) ),
    luogoEdit(new QLineEdit(this))
{
    QFormLayout* layout = new QFormLayout(this) ;
    layout->addRow("Orario:",orarioEdit);
    layout->addRow("Luogo:", luogoEdit) ;
}

Model::Attivita* EditorAppuntamento::crea(const QString& descrizione, const QDate& data) const{
    return new Model::Appuntamento(descrizione, data, orarioEdit->time() , luogoEdit->text() ) ;
}

void EditorAppuntamento::setValues(const Model::Appuntamento& appuntamento) {
    orarioEdit->setTime(appuntamento.getOrario() );
    luogoEdit->setText(appuntamento.getLuogo() ) ;
}
}