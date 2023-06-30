/** @file Cluster.cc
    @brief Implementació de la classe Cluster
*/
#include "Cluster.hh"

void Cluster::llegir_arbre_clust(BinTree<string> &btp) {
    BinTree<string> l;
    BinTree<string> r;
    string id;
    cin >> id;
    if (id != "*") {
        int mem;
        cin >> mem;
        Processador p(id, mem);
        cjt_processadors.insert(make_pair(id, p));
        llegir_arbre_clust(l);
        llegir_arbre_clust(r);
        btp = BinTree<string>(id, l, r);
    }
    else btp = BinTree<string>();
}

void Cluster::escriure_arbre_clust(const BinTree<string> &btp) {
    if (not btp.empty()) {
        cout << '(';
        cout << btp.value();
        escriure_arbre_clust(btp.left());
        escriure_arbre_clust(btp.right());
        cout << ')';
    }
    else
        cout << " ";
}

void Cluster::configurar_cluster() {
    cjt_processadors.clear();
    llegir_arbre_clust(arbre_id_clust);
}

void Cluster::imprimir_processador(string id_proc) {
    if (existeix_processador(id_proc)){
        cjt_processadors[id_proc].escriure_processador();
    }
    else
        cout << "error: no existe procesador" << endl;
}

void Cluster::imprimir_processadors_cluster() {
    if (not cjt_processadors.empty()) {
        map<string, Processador>::iterator it;
        for (it = cjt_processadors.begin(); it != cjt_processadors.end(); ++it) {
            cout << it->second.consultar_id_proc() << endl;
            it->second.escriure_processador();
        }
    }
}

void Cluster::imprimir_estructura_cluster() const {
    escriure_arbre_clust(arbre_id_clust);
    cout << endl;
}

Cluster::Cluster() {
}

bool Cluster::existeix_processador(string p) const {
    map<string, Processador>::const_iterator it = cjt_processadors.find(p);
    return it != cjt_processadors.end();
}

map<string, Processador> Cluster::consultar_mapa() const{
    return cjt_processadors;
}

BinTree<string> Cluster::consultar_arbre() const{
    return arbre_id_clust;
}

void Cluster::alta_proces_processador(string id_proc, const Proces &job) {
    if (not existeix_processador(id_proc)) cout << "error: no existe procesador" << endl;
    else cjt_processadors[id_proc].alta_proces(job);
}

void Cluster::baixa_proces_processador(string id_proc, int id_job) {
    map<string, Processador>::iterator it = cjt_processadors.find(id_proc);
    if (it != cjt_processadors.end()) it->second.baixa_proces(id_job);
    else cout << "error: no existe procesador" << endl;
}

void Cluster::moure_temps(int t) {
    map<string, Processador>::iterator it;
    for (it = cjt_processadors.begin(); it != cjt_processadors.end(); ++it) {
        it->second.avanzar_temps_processador(t);
    }
}

void Cluster::modificar_cluster(string id_proc, Cluster &clust_extra) {
    map<string, Processador>::iterator it = cjt_processadors.find(id_proc);
    clust_extra.configurar_cluster();
    if (it != cjt_processadors.end()) {
        if (not it->second.te_processos()) {
            bool te_aux = true;
            busca_proc_aux_cluster(id_proc, clust_extra, arbre_id_clust, te_aux);
            if (not te_aux) {
                cjt_processadors.erase(id_proc);
                map<string, Processador> map_afegir = clust_extra.consultar_mapa();
                cjt_processadors.insert(map_afegir.begin(), map_afegir.end());
            }
        }
        else cout << "error: procesador con procesos" << endl;
    }
    else cout << "error: no existe procesador" << endl;
}

void Cluster::busca_proc_aux_cluster(string id_proc, const Cluster &clust_extra, BinTree<string> &arbre, bool &te_aux) {
    BinTree<string> l;
    BinTree<string> r;
    if (arbre.value() == id_proc) {
        if (arbre.left().empty() and arbre.right().empty()) {
            te_aux = false;
            arbre = clust_extra.consultar_arbre();
        }
        else
            cout << "error: procesador con auxiliares" << endl;
    }
    if (not arbre.left().empty()) {        

        l = arbre.left();
        busca_proc_aux_cluster(id_proc, clust_extra, l, te_aux);
    }
    if (not arbre.right().empty()) {
        r = arbre.right();
        busca_proc_aux_cluster(id_proc, clust_extra, r, te_aux);
    }
    arbre = BinTree<string>(arbre.value(), l, r);
}

void Cluster::compactar_memoria_processador(string id_proc) {
    map<string, Processador>::iterator it = cjt_processadors.find(id_proc);
    if (it != cjt_processadors.end()) it->second.compactar_memoria_processador();
    else cout << "error: no existe procesador" << endl;
}

void Cluster::compactar_memoria_cluster() {
    map<string, Processador>::iterator it;
    for (it = cjt_processadors.begin(); it != cjt_processadors.end(); ++it) {
        it->second.compactar_memoria_processador();
    }
}

void Cluster::busqueda_amplada_proc(const Proces &job, const BinTree<string>& arbre, map<string,Processador>::iterator &it_bo, bool &primera) {             //BFS
    int id = job.consultar_id_proces();
    int mem_proces = job.consultar_mem_neces();
    queue<BinTree<string>> cua;
    cua.push(arbre);
    int buit = 0;
    while (not cua.empty()) {
        BinTree<string> posible = (cua.front());
        map<string,Processador>::iterator posible_it = cjt_processadors.find(posible.value());
        int posible_buit = posible_it->second.consultar_buit_mes_ajustat(mem_proces);
        if (posible_buit != -1) {
            if (not posible_it->second.existeix_proces(id)) {
                if (primera or posible_buit < buit) {                //Quan primera es true, estem a la primera iteracio
                    buit = posible_buit;
                    it_bo = posible_it;
                    primera = false;
                }
                else if (posible_buit == buit) {                        
                    if (posible_it->second.consultar_mem_lliure() > it_bo->second.consultar_mem_lliure()) {
                        it_bo = posible_it;
                    }
                }

            }
        }
        if (not posible.left().empty()) cua.push(posible.left());       //Primer busquem per l'esquerra (hem d'agafar en cas d'empat el més a la esquerra)
        if (not posible.right().empty()) cua.push(posible.right());
        cua.pop();
    }
}

void Cluster::afegir_proces_cond(const Proces &job, bool &afegit) {
    map<string,Processador>::iterator it_bo;
    bool primera = true;
    busqueda_amplada_proc(job, arbre_id_clust, it_bo, primera);         //Utilitzem primera per veure si hi ha algun processador on es pugui afegir el procès
    if (not primera) {
        afegit = true;
        it_bo->second.alta_proces(job);
    }
}