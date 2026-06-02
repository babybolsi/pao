// ─────────────────────────────────────────────
// Model/VisitorJson.h
// ─────────────────────────────────────────────
#ifndef MODEL_VISITOR_JSON_H
#define MODEL_VISITOR_JSON_H

#include <QJsonObject>

#include "VisitorAttivita.h"
#include "Appuntamento.h"
#include "Compito.h"
#include "Promemoria.h"

namespace Model {

class VisitorJson: public VisitorAttivita {
  private:
    QJsonObject object ; // risultato: riempito dall'ultimo visit() chiamato

  public:
    QJsonObject getObject() const ;

    virtual void visit(const Appuntamento& appuntamento);
    virtual void visit(const Compito& compito);
    virtual void visit(const Promemoria& promemoria);
} ;
}

#endif // MODEL_VISITOR_JSON_H