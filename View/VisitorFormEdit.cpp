// ─────────────────────────────────────────────
// View/VisitorFormEdit.cpp
// ─────────────────────────────────────────────
#include "VisitorFormEdit.h"

namespace View{

VisitorFormEdit::VisitorFormEdit(
    QStackedWidget& editorStack,
    EditorAppuntamento& editorAppuntamento,
    EditorCompito& editorCompito,
    EditorPromemoria& editorPromemoria
)
    : editorStack(editorStack),
    editorAppuntamento(editorAppuntamento),
    editorCompito(editorCompito) ,
    editorPromemoria(editorPromemoria)
{
}
void VisitorFormEdit::visit(const Model::Appuntamento& appuntamento){
    editorAppuntamento.setValues(appuntamento);
    editorStack.setCurrentWidget( &editorAppuntamento ) ;
}

void VisitorFormEdit::visit(const Model::Compito& compito) {
    editorCompito.setValues(compito);
    editorStack.setCurrentWidget(&editorCompito );
}
void VisitorFormEdit::visit(const Model::Promemoria& promemoria) {
    editorPromemoria.setValues(promemoria);
    editorStack.setCurrentWidget(&editorPromemoria);
}

}