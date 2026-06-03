// ─────────────────────────────────────────────
// View/AbstractEditorAttivita.h
// ─────────────────────────────────────────────
#ifndef VIEW_ABSTRACT_EDITOR_ATTIVITA_H
#define VIEW_ABSTRACT_EDITOR_ATTIVITA_H

#include <QWidget>
#include <QString>
#include <QDate>

#include "../Model/Attivita.h"

namespace View {

class AbstractEditorAttivita: public QWidget{
    Q_OBJECT
  public:
    AbstractEditorAttivita(QWidget* parent = nullptr);
    virtual ~AbstractEditorAttivita() ;

    virtual Model::Attivita* crea( const QString& descrizione, const QDate& data) const =0 ;
} ;
}

#endif // VIEW_ABSTRACT_EDITOR_ATTIVITA_H