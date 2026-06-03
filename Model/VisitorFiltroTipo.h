// ─────────────────────────────────────────────
// Model/VisitorFiltroTipo.h
// ─────────────────────────────────────────────
#ifndef MODEL_VISITOR_FILTRO_TIPO_H
#define MODEL_VISITOR_FILTRO_TIPO_H

#include "VisitorAttivita.h"  

namespace Model {

class VisitorFiltroTipo: public VisitorAttivita{

  private:
    int tipoCercato ;   // 0=Appuntamento, 1=Compito,2=Promemoria
    bool trovato;

  public:

    VisitorFiltroTipo(const int tipoCercato ) ;

    bool isTrovato() const;

    virtual void visit(const Appuntamento& appuntamento) ;
    virtual void visit( const Compito& compito);
    virtual void visit(const Promemoria& promemoria );

} ;
}
#endif // MODEL_VISITOR_FILTRO_TIPO_H