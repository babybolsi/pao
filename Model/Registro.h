// ─────────────────────────────────────────────
// Model/Registro.h
// ─────────────────────────────────────────────
#ifndef MODEL_REGISTRO_H
#define MODEL_REGISTRO_H

#include <vector>
#include <QString>

#include "Attivita.h"

namespace Model {

class Registro{
  private:
    std::vector<Attivita*> attivita ;  //il Registro possiede e si distrugge i suoi puntatori

  public:
    Registro();
    ~Registro();
    // Copia e assegnazione disabilitate
    Registro(const Registro& other)= delete;
    Registro& operator=(const Registro& other) = delete;

    Registro& aggiungi(Attivita* attivita) ;   

    Registro& rimuovi( const int indice);  

    Attivita* get(const int indice ) const ;

    int size() const;

    // Ritornano true se l'operazione riesce, false su errore o JSON non valido.                                                 
    bool salva(const QString& nomeFile ) const;                                         
    bool carica(const QString& nomeFile) ;         
};
}

#endif // MODEL_REGISTRO_H