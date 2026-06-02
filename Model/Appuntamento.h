// ─────────────────────────────────────────────
// Model/Appuntamento.h
// ─────────────────────────────────────────────
#ifndef MODEL_APPUNTAMENTO_H
#define MODEL_APPUNTAMENTO_H
#include <QString>
#include <QDate>
#include <QTime>
#include "Attivita.h"

namespace Model {

class Appuntamento: public Attivita{
  private:
    QTime orario ;
    QString luogo;

  public:
    Appuntamento( const QString descrizione,const QDate data, const QTime orario , const QString luogo);

    const QTime& getOrario( ) const ;
    Appuntamento& setOrario(const QTime orario ); 

    const QString& getLuogo() const ;
    Appuntamento& setLuogo(const QString luogo) ; 

    virtual bool isScaduta() const ;

    virtual QString getInfo() const;
    
    virtual void accetta( VisitorAttivita& visitor ) const;
} ;

}

#endif // MODEL_APPUNTAMENTO_H