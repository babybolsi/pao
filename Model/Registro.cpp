// ─────────────────────────────────────────────
// Model/Registro.cpp
// ─────────────────────────────────────────────
#include "Registro.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

#include "VisitorJson.h"
#include "LettoreJson.h"

namespace Model {

Registro::Registro() {
}

Registro::~Registro() {
    for (std::vector<Attivita*>::iterator it = attivita.begin(); it != attivita.end(); ++it) {
        delete *it ;
    }
}

Registro& Registro::aggiungi(Attivita* attivita){
    this->attivita.push_back(attivita);
    return *this ;
}

Registro& Registro::rimuovi(const int indice) {
    delete attivita[indice];
    attivita.erase(attivita.begin() + indice);
    return *this;
}
Registro& Registro::sostituisci(const int indice, Attivita* attivita ){
    delete this->attivita[indice];
    this->attivita[indice]= attivita ;
    
    return *this;
}

Attivita* Registro::get(const int indice) const{
    return attivita[indice];
}
int Registro::size() const {
    return static_cast<int>(attivita.size()) ;
}
bool Registro::salva(const QString& nomeFile) const{
    QJsonArray array;
    VisitorJson visitor ;
    for (std::vector<Attivita*>::const_iterator it = attivita.begin(); it != attivita.end() ; ++it ){

        (*it)->accetta(visitor);           
        array.push_back(visitor.getObject()) ;

    }

    QFile file(nomeFile) ;
    if (!file.open(QIODevice::WriteOnly) ){
        return false;
    }
    file.write(QJsonDocument(array).toJson()) ;
    file.close();

    return true;
}
bool Registro::carica(const QString& nomeFile){
    QFile file(nomeFile) ;
    if (!file.open(QIODevice::ReadOnly) ){
        return false;
    }
    QJsonParseError errore;
    QJsonDocument documento= QJsonDocument::fromJson(file.readAll() , &errore) ;
    file.close(); 
    if (errore.error != QJsonParseError::NoError || !documento.isArray() ){ 

        return false;
    }

    // Svuota SOLO dopo aver validato il file: se il parse fallisce non perdo i dati gia' presenti.
    for (std::vector<Attivita*>::iterator it = attivita.begin(); it != attivita.end(); ++it) {
        delete *it;
    }
    attivita.clear();

    LettoreJson lettore;
    QJsonArray array= documento.array() ;
    for ( const QJsonValue& valore : array) {
        Attivita* attivita_letta = lettore.leggi(valore.toObject() );
        if (attivita_letta != nullptr){
            attivita.push_back(attivita_letta) ;
        }
    }
    return true;
}
}
