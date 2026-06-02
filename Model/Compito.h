// ─────────────────────────────────────────────
// Model/Compito.h
// ─────────────────────────────────────────────
#ifndef MODEL_COMPITO_H
#define MODEL_COMPITO_H

#include <QString>
#include <QDate>

#include "Attivita.h"

namespace Model {

class Compito: public Attivita{
  private:
    bool completato ;

  public:
    Compito( const QString descrizione, const QDate data , const bool completato);

    bool isCompletato() const;
    Compito& setCompletato(const bool completato);  

    // Override dei virtuali puri di Attivita
    virtual bool isScaduta() const ;

    virtual QString getInfo() const;

    virtual void accetta(VisitorAttivita& visitor) const;
} ;

}

#endif // MODEL_COMPITO_H