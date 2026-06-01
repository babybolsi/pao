// ─────────────────────────────────────────────
// Model/VisitorAttivita.h
// ─────────────────────────────────────────────
#ifndef MODEL_VISITOR_ATTIVITA_H
#define MODEL_VISITOR_ATTIVITA_H

namespace Model {


class Appuntamento ;
class Compito ;
class Promemoria ;

class VisitorAttivita {
  public:
    virtual ~VisitorAttivita(){};
    virtual void visit( const Appuntamento& appuntamento) = 0;
    virtual void visit(const Compito& compito )=0;
    virtual void visit(const Promemoria& promemoria)= 0 ;
} ;

}

#endif // MODEL_VISITOR_ATTIVITA_H