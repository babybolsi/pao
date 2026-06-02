// ─────────────────────────────────────────────
// Model/Registro.cpp
// ─────────────────────────────────────────────
#include "Registro.h"

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

Attivita* Registro::get(const int indice) const{
    return attivita[indice];
}
int Registro::size() const {
    return static_cast<int>(attivita.size()) ;
}
}
