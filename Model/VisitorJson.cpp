// ─────────────────────────────────────────────
// Model/VisitorJson.cpp
// ─────────────────────────────────────────────
#include "VisitorJson.h"

namespace Model {

QJsonObject VisitorJson::getObject() const{
    return object;
}

void VisitorJson::visit(const Appuntamento& appuntamento ) {
    QJsonObject o;
    o.insert("tipo",QJsonValue::fromVariant("Appuntamento")) ;
    o.insert("descrizione", QJsonValue::fromVariant(appuntamento.getDescrizione()));
    o.insert("data" , QJsonValue::fromVariant(appuntamento.getData().toString(Qt::ISODate)));
    o.insert("orario", QJsonValue::fromVariant(appuntamento.getOrario().toString(Qt::ISODate)));
    o.insert("luogo", QJsonValue::fromVariant(appuntamento.getLuogo()));
    object = o;
}

void VisitorJson::visit(const Compito& compito){

    QJsonObject o;
    o.insert("tipo", QJsonValue::fromVariant("Compito"));
    o.insert("descrizione", QJsonValue::fromVariant(compito.getDescrizione()));
    o.insert("data",QJsonValue::fromVariant(compito.getData().toString(Qt::ISODate)));
    o.insert("completato",QJsonValue::fromVariant(compito.isCompletato())) ;
    object = o;
}
void VisitorJson::visit(const Promemoria& promemoria){
    QJsonObject o ;

    o.insert("tipo", QJsonValue::fromVariant("Promemoria"));
    o.insert("descrizione", QJsonValue::fromVariant(promemoria.getDescrizione()));
    o.insert("data",QJsonValue::fromVariant(promemoria.getData().toString(Qt::ISODate)));
    o.insert("priorita", QJsonValue::fromVariant(promemoria.getPriorita())) ;
    object = o; 
}
}