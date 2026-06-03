// ─────────────────────────────────────────────
// View/EditorPromemoria.cpp
// ─────────────────────────────────────────────
#include "EditorPromemoria.h"

#include <QFormLayout>

namespace View {

EditorPromemoria::EditorPromemoria(QWidget* parent )
    : AbstractEditorAttivita(parent) ,
    prioritaSpin(new QSpinBox(this) )
{
    prioritaSpin->setRange(1, 3) ;
    QFormLayout* layout =new QFormLayout(this);
    layout->addRow("Priorità (1-3):", prioritaSpin) ;
}

Model::Attivita* EditorPromemoria::crea(const QString& descrizione, const QDate& data) const{
    return new Model::Promemoria(descrizione, data, prioritaSpin->value());
}

void EditorPromemoria::setValues( const Model::Promemoria& promemoria){
    prioritaSpin->setValue(promemoria.getPriorita() ) ;
}
}
