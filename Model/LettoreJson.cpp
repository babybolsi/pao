// ─────────────────────────────────────────────
// Model/LettoreJson.cpp
// ─────────────────────────────────────────────
#include "LettoreJson.h"

namespace Model {

Attivita* LettoreJson::leggi( const QJsonObject& object) const {

    QString tipo= object.value("tipo").toString();
    QString descrizione= object.value("descrizione").toString();
    QDate data = QDate::fromString(object.value("data").toString(), Qt::ISODate) ;

    if (tipo =="Appuntamento" ) {

        QTime orario = QTime::fromString(object.value("orario").toString(), Qt::ISODate);
        QString luogo = object.value("luogo").toString() ;

        return new Appuntamento(descrizione, data, orario, luogo);

    }
    else if (tipo == "Compito"){
        bool completato = object.value("completato").toBool();

        return new Compito(descrizione, data, completato) ;

    }
    else if ( tipo == "Promemoria"){

        int priorita = object.value("priorita").toInt();

        return new Promemoria(descrizione, data, priorita) ;
    }
    return nullptr ;   // tipo mancante o sconosciuto
}
}
