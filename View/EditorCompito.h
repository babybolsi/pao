// ─────────────────────────────────────────────
// View/EditorCompito.h
// ─────────────────────────────────────────────
#ifndef VIEW_EDITOR_COMPITO_H
#define VIEW_EDITOR_COMPITO_H

#include <QCheckBox>

#include "AbstractEditorAttivita.h"
#include "../Model/Compito.h"

namespace View {

class EditorCompito: public AbstractEditorAttivita{
    Q_OBJECT
  private:
    QCheckBox* completatoCheck ;

  public:
    EditorCompito(QWidget* parent =nullptr);

    virtual Model::Attivita* crea(const QString& descrizione, const QDate& data ) const;
    void setValues(const Model::Compito& compito) ;
};

}

#endif // VIEW_EDITOR_COMPITO_H