// ─────────────────────────────────────────────
// View/EditorAppuntamento.h
// ─────────────────────────────────────────────
#ifndef VIEW_EDITOR_APPUNTAMENTO_H
#define VIEW_EDITOR_APPUNTAMENTO_H

#include <QTimeEdit>
#include <QLineEdit>

#include "AbstractEditorAttivita.h"
#include "../Model/Appuntamento.h"

namespace View{

class EditorAppuntamento: public AbstractEditorAttivita {
    Q_OBJECT
  private:
    QTimeEdit* orarioEdit;
    QLineEdit* luogoEdit;

  public:
    EditorAppuntamento(QWidget* parent = nullptr) ;

    virtual Model::Attivita* crea( const QString& descrizione, const QDate& data ) const;
    void setValues(const Model::Appuntamento& appuntamento) ;   
} ;
}

#endif // VIEW_EDITOR_APPUNTAMENTO_H