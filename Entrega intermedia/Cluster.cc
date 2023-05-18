#include "Cluster.hh"

Cluster::Cluster() {
}

bool Cluster::existeix_processador(string p) const {
    map<string, Processador>::const_iterator it = clust_proc.find(p);
    return it != clust_proc.end();
}

void Cluster::llegir_arbre_clust(BinTree<string> &btp) {
    BinTree<string> l;
    BinTree<string> r;
    string id;
    cin >> id;
    if (id != "*") {
        int mem;
        cin >> mem;
        Processador p(id, mem);
        clust_proc.insert(make_pair(id, p));
        llegir_arbre_clust(l);
        llegir_arbre_clust(r);
        btp = BinTree<string>(id,l,r);
    }
    else btp = BinTree<string>();
}

void Cluster::configurar_cluster() {
    clust_proc.clear();
    llegir_arbre_clust(arbre_id_clust);
}

void Cluster::imprimir_processador(string id_proc) {
    if (existeix_processador(id_proc)) {
        clust_proc[id_proc].escriure_processador();
    }
    else cout << "error: no existe procesador" << endl;
}

void Cluster::imprimir_processadors_cluster() {
    if (not clust_proc.empty()) {
        map<string, Processador>::iterator it;
        for (it = clust_proc.begin(); it != clust_proc.end(); ++it) {
            cout << it->second.consultar_id_proc() << endl;
            it->second.escriure_processador();
        }
    }
}

void Cluster::escriure_arbre_clust(const BinTree<string> &btp){
    if (not btp.empty()) {
        cout << '(';
        cout << btp.value();
        escriure_arbre_clust(btp.left());
        escriure_arbre_clust(btp.right());
        cout << ')';
    }
    else cout << " ";
}

void Cluster::imprimir_estructura_cluster() const {
    escriure_arbre_clust(arbre_id_clust);
    cout << endl;
}

void Cluster::alta_proces_processador(string id_proc, Proces &job) {
    if (not existeix_processador(id_proc)) cout << "error: no existe procesador" << endl;
    else clust_proc[id_proc].alta_proces(job);
}

void Cluster::baixa_proces_processador(string id_proc, int id_job) {
    map<string, Processador>::iterator it = clust_proc.find(id_proc);
    if (it != clust_proc.end()) {    
        clust_proc[id_proc].baixa_proces(id_job);
    }
    else cout  << "error: no existe procesador" << endl;
}


void Cluster::moure_temps(int t) {
    map<string, Processador>::iterator it;
    for (it = clust_proc.begin(); it != clust_proc.end(); ++it) {
        it->second.avanzar_temps_processador(t);
    }
}

