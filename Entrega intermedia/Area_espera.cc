#include "Area_espera.hh"

Area_espera::Area_espera() {

}

Prioritat Area_espera::consultar_prioritat(string id_prioritat) {
    return cjt_prioritats[id_prioritat];
}

bool Area_espera::existeix_prio(string id_prioritat) {
    map<string, Prioritat>::const_iterator it = cjt_prioritats.find(id_prioritat);
    return (it != cjt_prioritats.end());
}

bool Area_espera::te_processos_pendents(string id_prioritat) const {
    return id_prioritat < "hola";
}

int Area_espera::consultar_n_enviats(string id_prioritat) const {
    if (id_prioritat < "!") return 1;
    else return 2;
}


int Area_espera::consultar_n_rebutjats(string id_prioritat) const {
    if (id_prioritat < "!") return 1;
    else return 2;
}

void Area_espera::llegir() {
    int n;
    cin >> n;
    string id_prio;
    for (int i = 0; i < n; ++i) {
        cin >> id_prio;
        alta_prioritat(id_prio);
    }
}

void Area_espera::imprimir_prioritat(string id_prioritat) {
    if (existeix_prio(id_prioritat)) {
        cjt_prioritats[id_prioritat].imprimir_prioritat_prio();
    }
    else cout << "error: no existe prioridad" << endl;
}

void Area_espera::imprimir_area_espera() const {
    map<string,Prioritat>::const_iterator it = cjt_prioritats.begin();
    for (it = cjt_prioritats.begin(); it != cjt_prioritats.end(); ++it) {
        cout << (*it).first << endl;
        (*it).second.imprimir_prioritat_prio();  
    }
}

void Area_espera::alta_proces_espera(Proces job, string id_prioritat) {
    if (existeix_prio(id_prioritat)) {
        cjt_prioritats[id_prioritat].alta_proces_espera_prio(job);
    }
    else cout << "error: no existe prioridad" << endl;
}

void Area_espera::baixa_proces_espera(int id_job, string id_prioritat) {
    if (existeix_prio(id_prioritat)) {
        cjt_prioritats[id_prioritat].baixa_proces_espera_prio(id_job);
    }
    else cout << "error: no existe prioridad" << endl;
}


void Area_espera::augmentar_n_enviats(string id_prioritat) {
    cjt_prioritats[id_prioritat].augmentar_n_enviats_prio();
}

void Area_espera::augmentar_n_rebutjats(string id_prioritat) {
    cjt_prioritats[id_prioritat].augmentar_n_rebutjats_prio();
}


void Area_espera::alta_prioritat(string id_prioritat) {
    if (not existeix_prio(id_prioritat)) {
        cjt_prioritats[id_prioritat];
    }
    else cout << "error: ya existe prioridad" << endl;
}


void Area_espera::baixa_prioritat(string id_prioritat) {
    if (existeix_prio(id_prioritat)) {
        if (not cjt_prioritats[id_prioritat].te_processos_pendents_prio()) {
            cjt_prioritats.erase(id_prioritat);
        }
        else cout << "error: prioridad con procesos" << endl;
    }
    else cout << "error: no existe prioridad" << endl;
}

void Area_espera::enviar_processos_cluster(int n) {

    while (n > 0) {
        
    }
}


