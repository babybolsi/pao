// ─────────────────────────────────────────────
// Model/Attivita.h
// ─────────────────────────────────────────────
#ifndef MODEL_ATTIVITA_H
#define MODEL_ATTIVITA_H

#include <QString>
#include <QDate>

#include "VisitorAttivita.h"

namespace Model {

class Attivita {
  private:
    QString descrizione;
    QDate data;

  protected:

    Attivita(const QString descrizione, const QDate data);

  public:
    virtual ~Attivita();

    const QString& getDescrizione() const ;
    Attivita& setDescrizione(const QString descrizione) ;
    const QDate& getData() const;
    Attivita& setData(const QDate data ) ;

    // Metodi virtuali pure da definire
    virtual bool isScaduta() const = 0;
    virtual QString getInfo() const = 0 ;
    virtual void accetta( VisitorAttivita& visitor) const = 0;
};

}

#endif // MODEL_ATTIVITA_H
