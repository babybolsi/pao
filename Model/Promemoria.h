// ─────────────────────────────────────────────
// Model/Promemoria.h
// ─────────────────────────────────────────────
#ifndef MODEL_PROMEMORIA_H
#define MODEL_PROMEMORIA_H

#include <QString>
#include <QDate>

#include "Attivita.h"

namespace Model{

class Promemoria: public Attivita {
  private:
    int priorita ; //1 = bassa, 2=media , 3=alta

  public:
    Promemoria(const QString descrizione , const QDate data, const int priorita) ;

    int getPriorita() const;
    Promemoria& setPriorita(const int priorita); 

    //Override dei virtuali puri di Attivita
    virtual bool isScaduta() const ;

    virtual QString getInfo() const;

    virtual void accetta( VisitorAttivita& visitor ) const ;
};
}
#endif // MODEL_PROMEMORIA_H
