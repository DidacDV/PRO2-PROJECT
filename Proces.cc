/** @file Proces.cc
    @brief Implementació de la classe Proces
*/
#include "Proces.hh"
#include <iostream>
Proces::Proces() {

}


int Proces::consultar_mem_neces() const {
return mem_neces;
}

int Proces::consultar_temps_exec() const {
    return temps_exec;
}

int Proces::consultar_id_proces() const {
    return id_job; 
}



void Proces::llegir_proces() {
    cin >> id_job >> mem_neces >> temps_exec;
}

void Proces::escriure_proces() const {
    cout << id_job << " " << mem_neces << " " << temps_exec << endl;
}


void Proces::modificar_temps(int t) {
    temps_exec -= t;
    if (temps_exec < 0) temps_exec = 0;
}
