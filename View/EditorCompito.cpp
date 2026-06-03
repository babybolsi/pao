// ─────────────────────────────────────────────
// View/EditorCompito.cpp
// ─────────────────────────────────────────────
#include "EditorCompito.h"

#include <QFormLayout>

namespace View {

EditorCompito::EditorCompito(QWidget* parent)
    : AbstractEditorAttivita(parent),
    completatoCheck(new QCheckBox("Completato", this) )
{
    QFormLayout* layout = new QFormLayout(this);
    layout->addRow(completatoCheck);
}

Model::Attivita* EditorCompito::crea(const QString& descrizione, const QDate& data) const {
    return new Model::Compito(descrizione, data, completatoCheck->isChecked());
}

void EditorCompito::setValues(const Model::Compito& compito) {
    completatoCheck->setChecked(compito.isCompletato());
}
}