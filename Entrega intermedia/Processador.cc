#include "Processador.hh"
Processador::Processador() {
    
}

Processador::Processador(string id_proc, int mem) {
    proc.first = id_proc;
    proc.second = mem;
    cjt_buits[proc.second].insert(0);             //Al inicialitzar, posició més gran es la mem total a l'index 0
}

bool Processador::existeix_proces(int id_job) const {
    map<int, int>::const_iterator it = cjt_job_mem.find(id_job);
    return it != cjt_job_mem.end();
}


string Processador::consultar_id_proc() {
return proc.first;
}

bool Processador::te_processos() const {
    return (not cjt_job.empty());
}

bool Processador::te_processadors_aux() const {
return true;
}

void Processador::escriure_processador() {
    map<int,Proces>::iterator it;
    for (it = cjt_job.begin(); it != cjt_job.end(); ++it) {
        cout << it->first << " ";
        it->second.escriure_proces();
    }
}

void Processador::baixa_proces(int id_job) {
    if (existeix_proces(id_job)) {
        map<int,int>::iterator it = cjt_job_mem.find(id_job);
        int pos = it->second;
        map<int,Proces>::iterator it_job = cjt_job.find(pos);
        eliminar_proces(id_job, it_job);
    }
    else cout << "error: no existe proceso" << endl;
}

void Processador::eliminar_proces(int id_job, map<int,Proces>::iterator &it) {
    map<int,Proces>::iterator it_aux = it;
    cjt_job_mem.erase(id_job);
    if (cjt_job_mem.empty()) {
        cjt_buits.clear();
        cjt_buits[proc.second].insert(0);       // Si no hi ha cap altra procès, tornem al cas base (l'únic buit es tota la mem)
    }
    else {
        int pos_seguent;                        
        int pos_anterior;                       // No les inicialitzem encara, no sabem si el borrat estava al principi/final
        int pos_borrat = it_aux->first;
        int buit_seg;
        int buit;
        int mem_proces = consultar_memoria_proces(pos_borrat);
        int pos_def = pos_borrat + mem_proces;
        ++it_aux;
        if (it_aux == cjt_job.end()) {                                      // El borrat era l'ultim procès
            pos_seguent = proc.second;
            if (pos_def < pos_seguent) {
                buit_seg = pos_seguent - pos_def;
            }
            --it_aux;
        }
        else {              // El borrat NO era l'ultim procès
            pos_seguent = it_aux->first;
            if (pos_seguent > pos_def) {
                buit_seg = pos_seguent - pos_def;
            }
            --it_aux;
        }

        if (it_aux == cjt_job.begin()) {                                                          // El borrat era el primer
            if (pos_borrat > 0) {
                cjt_buits[pos_borrat].erase(0);
                if(cjt_buits[pos_borrat].empty()) cjt_buits.erase(pos_borrat);
            }
            pos_anterior = 0;
        }

        else {                                // El borrat NO era el primer
            --it_aux;
            pos_anterior = it_aux->first + it_aux->second.consultar_mem_neces();
            if (pos_anterior < pos_def) {
                buit = pos_borrat - pos_anterior;
                cjt_buits[buit].erase(pos_anterior);
                if (cjt_buits[buit].empty()) cjt_buits.erase(buit);                             
            }
        }
        cjt_buits[buit_seg].erase(pos_def);
        if (cjt_buits[buit_seg].empty()) cjt_buits.erase(buit_seg);          // Ja no queden posicions amb aquest buit, el borrem
        cjt_buits[pos_seguent - pos_anterior].insert(pos_anterior);         //Afegim buit de tamany (pos seg - pos ant) a la pos ant
    }
    it = cjt_job.erase(it);

}


void Processador::avanzar_temps_processador(int t) {
    if (not cjt_job.empty()) {
        map <int,Proces>::iterator it = cjt_job.begin();
        while (it != cjt_job.end()) {
            it->second.modificar_temps(t);
            int temps = it->second.consultar_temps_exec();
            if (temps == 0) {
                int id = it->second.consultar_id_proces();
                eliminar_proces(id, it);
            }
            else ++it;
        }
    }
}

void Processador::alta_proces(Proces &job) {
    int id = job.consultar_id_proces();
    if (not existeix_proces(id)) {
        int mem_proces = job.consultar_mem_neces();        
        map<int,set<int>>::iterator it;
        it = cjt_buits.lower_bound(mem_proces);
        if (it != cjt_buits.end()) {
            int tamany = it->first;
            int pos = *it->second.begin();
            cjt_job.insert(make_pair(pos,job));
            cjt_job_mem.insert(make_pair(id,pos));
            if ((tamany - mem_proces) != 0) cjt_buits[tamany-mem_proces].insert(pos + mem_proces);      // Si el proces ocupa menys del tamany del buit, creem un nou buit
            it->second.erase(pos);
            if (it->second.empty()) cjt_buits.erase(tamany);
        }
        else cout << "error: no cabe proceso" << endl;
    }
    else cout << "error: ya existe proceso" << endl;
}

int Processador::consultar_memoria_proces(int pos) {
    return cjt_job[pos].consultar_mem_neces();
}

void Processador::compactar_memoria_processador() {
    
}