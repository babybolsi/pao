// ─────────────────────────────────────────────
// Model/Compito.cpp
// ─────────────────────────────────────────────
#include "Compito.h"

#include "VisitorAttivita.h"  

namespace Model {

Compito::Compito( const QString descrizione, const QDate data , const bool completato )
    : Attivita(descrizione, data) ,
    completato(completato)
{
}

bool Compito::isCompletato() const{
    return completato;
}

Compito& Compito::setCompletato(const bool completato) {
    this->completato= completato;
    return *this;
}

// Scaduto se la scadenza e' passata E non è ancora stato completato
bool Compito::isScaduta() const {
    return getData() < QDate::currentDate() && !completato;
}

QString Compito::getInfo() const {
    return QString("Compito: %1\nScadenza: %2\nCompletato: %3")
        .arg(getDescrizione())
        .arg(getData().toString("dd/MM/yyyy"))
        .arg(completato ? "Sì" : "No") ;
}

void Compito::accetta(VisitorAttivita& visitor) const{
    visitor.visit(*this);
}
}
