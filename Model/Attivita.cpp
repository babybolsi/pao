// ─────────────────────────────────────────────
// Model/Attivita.cpp
// ─────────────────────────────────────────────
#include "Attivita.h"

namespace Model{

    Attivita::Attivita(const QString descrizione, const QDate data)
        : descrizione(descrizione),
        data(data)
    {
}

Attivita::~Attivita(){
}
const QString& Attivita::getDescrizione() const  {
    return  descrizione ; 
 }
Attivita& Attivita::setDescrizione(const QString descrizione) {
    this->descrizione= descrizione;
    return *this ;
}

const QDate& Attivita::getData( ) const {
    return  data ;
}

Attivita& Attivita::setData(const QDate data ) {
    this->data = data;
    return  *this ;
}

}