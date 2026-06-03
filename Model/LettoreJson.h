// ─────────────────────────────────────────────
// Model/LettoreJson.h
// ─────────────────────────────────────────────
#ifndef MODEL_LETTORE_JSON_H
#define MODEL_LETTORE_JSON_H

#include <QJsonObject>

#include "Attivita.h"
#include "Appuntamento.h"
#include "Compito.h"
#include "Promemoria.h"

namespace Model {

class LettoreJson{
  public:
    // Ritorna un nuovo Attivita* (chi chiama diventa il proprietario)
    // Ritorna nullptr se "tipo" manca o e' sconosciuto
    Attivita* leggi(const QJsonObject& object) const;
} ;
}

#endif // MODEL_LETTORE_JSON_H