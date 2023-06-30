/** @file Prioritat.cc
    @brief Implementació de la classe Prioritat
*/
#include "Prioritat.hh"

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

void Prioritat::imprimir_prioritat_prio() const {
    list<Proces>::const_iterator it = list_proc_pendent.begin();
    while (it != list_proc_pendent.end()) {
    (*it).escriure_proces();                    // ja fa el endl;
    ++it;
    }
    cout << n_acceptats << " " << n_rebutjats << endl;
}

void Prioritat::alta_proces_espera_prio(const Proces &job) {
    list<Proces>::iterator it_prio = list_proc_pendent.end();
    int id = job.consultar_id_proces();
    if (not existeix_proces(id)) {
        proc_pend.insert(make_pair(id, job));
        list_proc_pendent.insert(it_prio,job);
    }
    else cout << "error: ya existe proceso" << endl;
}

void Prioritat::enviar_cluster(Cluster &clust, int &n) {
    list<Proces>::iterator it = list_proc_pendent.begin();
    int size = list_proc_pendent.size();
    bool afegit;
    while (n > 0 and size > 0) {
        afegit = false;
        Proces job = *it;
        clust.afegir_proces_cond(job, afegit);
        if (not afegit){
            ++n_rebutjats;
            it = list_proc_pendent.erase(it);
            list_proc_pendent.push_back(job);
        }
        else {
            proc_pend.erase(job.consultar_id_proces());
            it = list_proc_pendent.erase(it);
            ++n_acceptats;
            --n;
        }
        --size; 
    }
}