#include "Prioritat.hh"
#include "Proces.hh"
#include <iostream>

Prioritat::Prioritat() {

}

bool Prioritat::existeix_proces(int id_job) const {
    map<int, Proces>::const_iterator it = proc_pend.find(id_job);
    return (it != proc_pend.end());
}

bool Prioritat::te_processos_pendents_prio() const {
    if (list_proc_pendent.empty()) return false;
    return true;
}

int Prioritat::consultar_n_enviats_prio() const {
    return n_acceptats;
}

int Prioritat::consultar_n_rebutjats_prio() const {
    return n_rebutjats;
}

void Prioritat::imprimir_prioritat_prio() const {
    list<Proces>::const_iterator it = list_proc_pendent.begin();
    while (it != list_proc_pendent.end()) {
    (*it).escriure_proces();                    // ja fa el endl;
    ++it;
    }
    cout << n_acceptats << " " << n_rebutjats << endl;
}

void Prioritat::augmentar_n_enviats_prio() {
    ++n_acceptats;
}

void Prioritat::augmentar_n_rebutjats_prio() {
    ++n_rebutjats;
}

void Prioritat::alta_proces_espera_prio(Proces job) {
    list<Proces>::iterator it_prio = list_proc_pendent.end();
    int id = job.consultar_id_proces();
    if (not existeix_proces(id)) {
        proc_pend.insert(make_pair(id, job));
        list_proc_pendent.insert(it_prio,job);
    }
    else cout << "error: ya existe proceso" << endl;
}

void Prioritat::baixa_proces_espera_prio(int id_job) {
    if (existeix_proces(id_job)) {
        proc_pend.erase(id_job);
    }
    else cout << "error: no existe proceso" << endl;
}
