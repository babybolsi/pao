// ─────────────────────────────────────────────
// View/VisitorFormEdit.h
// ─────────────────────────────────────────────
#ifndef VIEW_VISITOR_FORM_EDIT_H
#define VIEW_VISITOR_FORM_EDIT_H

#include <QStackedWidget>

#include "../Model/VisitorAttivita.h"
#include "EditorAppuntamento.h"
#include "EditorCompito.h"
#include "EditorPromemoria.h"

namespace View {

class VisitorFormEdit: public Model::VisitorAttivita{

  private:

    QStackedWidget& editorStack;
    EditorAppuntamento& editorAppuntamento ;
    EditorCompito& editorCompito;
    EditorPromemoria& editorPromemoria;

  public:
    VisitorFormEdit(
        QStackedWidget& editorStack ,
        EditorAppuntamento& editorAppuntamento,
        EditorCompito& editorCompito ,
        EditorPromemoria& editorPromemoria 

    ) ;

    virtual void visit(const Model::Appuntamento& appuntamento);

    virtual void visit(const Model::Compito& compito );
    virtual void visit(const Model::Promemoria& promemoria) ;
} ; 
}

#endif // VIEW_VISITOR_FORM_EDIT_H