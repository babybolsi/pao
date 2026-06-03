// ─────────────────────────────────────────────
// Model/VisitorFiltroTipo.cpp
// ─────────────────────────────────────────────
#include "VisitorFiltroTipo.h"

namespace Model{

VisitorFiltroTipo::VisitorFiltroTipo(const int tipoCercato)
    : tipoCercato(tipoCercato) ,
    trovato(false)
{
}
bool VisitorFiltroTipo::isTrovato() const{
    return trovato ;

}

void VisitorFiltroTipo::visit( const Appuntamento& ) {

    trovato=(tipoCercato == 0 ) ;
}

void VisitorFiltroTipo::visit(const Compito&){
    trovato = ( tipoCercato == 1 );
}
void VisitorFiltroTipo::visit(const Promemoria&){ 

    trovato =(tipoCercato==2) ;
}
}