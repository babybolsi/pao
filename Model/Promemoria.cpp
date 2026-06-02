// ─────────────────────────────────────────────
// Model/Promemoria.cpp
// ─────────────────────────────────────────────
#include "Promemoria.h"

#include "VisitorAttivita.h"  

namespace Model {

Promemoria::Promemoria( const QString descrizione, const QDate data, const int priorita)
    : Attivita(descrizione, data) ,
    priorita(priorita)
{
}

int Promemoria::getPriorita() const{
    return priorita;
}

Promemoria& Promemoria::setPriorita(const int priorita) {
    this->priorita =priorita;
    return *this;
}

// Un promemoria non scade mai
bool Promemoria::isScaduta() const {
    return false;
}

QString Promemoria::getInfo() const{
    return QString("Promemoria: %1\nData: %2\nPriorità: %3/3")
        .arg(getDescrizione())
        .arg(getData().toString("dd/MM/yyyy"))
        .arg(priorita) ;
}
void Promemoria::accetta(VisitorAttivita& visitor) const {
    visitor.visit(*this ) ;
}
}
