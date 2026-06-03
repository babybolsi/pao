// ─────────────────────────────────────────────
// View/EditorPromemoria.h
// ─────────────────────────────────────────────
#ifndef VIEW_EDITOR_PROMEMORIA_H
#define VIEW_EDITOR_PROMEMORIA_H

#include <QSpinBox>

#include "AbstractEditorAttivita.h"
#include "../Model/Promemoria.h"

namespace View{

class EditorPromemoria: public AbstractEditorAttivita{
    Q_OBJECT
  private:
    QSpinBox* prioritaSpin ;

  public:
    EditorPromemoria(QWidget* parent = nullptr) ;

    virtual Model::Attivita* crea( const QString& descrizione, const QDate& data ) const ;
    void setValues(const Model::Promemoria& promemoria);
} ;
}

#endif // VIEW_EDITOR_PROMEMORIA_H