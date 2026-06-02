// ─────────────────────────────────────────────
// Model/Appuntamento.cpp
// ─────────────────────────────────────────────
#include "Appuntamento.h"

#include <QDateTime>

#include "VisitorAttivita.h"  

namespace Model{

Appuntamento::Appuntamento(const QString descrizione,const QDate data, const QTime orario, const QString luogo)
    : Attivita(descrizione, data),
    orario(orario),
    luogo(luogo)
{
}

const QTime& Appuntamento::getOrario() const {
    return orario;
}

Appuntamento& Appuntamento::setOrario(const QTime orario){
    this->orario = orario;
    return *this;
}

const QString& Appuntamento::getLuogo() const{
    return luogo;
}

Appuntamento& Appuntamento::setLuogo(const QString luogo) {
    this->luogo= luogo;
    return *this ;
}

bool Appuntamento::isScaduta() const {
    return QDateTime(getData(), orario) < QDateTime::currentDateTime() ;
}

QString Appuntamento::getInfo() const {
    return QString("Appuntamento: %1\nData: %2\nOrario: %3\nLuogo: %4")
        .arg(getDescrizione())
        .arg(getData().toString("dd/MM/yyyy"))
        .arg(orario.toString("HH:mm"))
        .arg(luogo);
}


void Appuntamento::accetta(VisitorAttivita& visitor) const {
    visitor.visit(*this);
}

}