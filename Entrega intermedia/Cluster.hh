/** @file Cluster.hh
    @brief Especificació de la classe Cluster
*/
#ifndef CLUSTER_HH
#define CLUSTER_HH

// Classe Cluster

/** @class Cluster
	@brief Representa un Cluster
*/


#include "Processador.hh"
#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <iostream>
#include <map>
#endif

class Cluster {

private:
BinTree<string> arbre_id_clust;           // Conjunt de id's de processadors
map<string, Processador> clust_proc;      // Clau: id del processador, Contingut: processador

/** @brief Escriu cada arbre del cluster
    \pre  A l'entrada hi ha el cluster <em>btp</em>
    \post Imprimeix l'estructura del cluster
*/
static void escriure_arbre_clust(const BinTree<string> &btp);

/** @brief Llegeix un arbre de id_processador
      \pre  A l'entrada hi ha un cluster <em>clust</em>
      \post El cluster obté els seus elements
*/
void llegir_arbre_clust(BinTree<string> &btp);

public:

//Constructores

/** @brief Creadora sense dades
      \pre  <em>Cert</em>
      \post El resultat és un cluster buit
*/
Cluster();

//Entrada i sortida

/** @brief Configurador d'un cluster
      \pre  <em>Cert</em>
      \post El p.i obté processadors i els seus atributs
*/
void configurar_cluster();

/** @brief  Imprimeix un processador
      \pre  A l'entrada un identificador del processador <em>id_proc</em>
      \post Si <em>id_proc</em> existeix al p.i, imprimeix el processador donat per <em>id_proc</em>
            al contrari, salta error
*/
void imprimir_processador(string id_proc);

/** @brief Escriu tots els processadors del cluster
      \pre  <em>Cert</em>
      \post S'escriuen tots els processadors del p.i per ordre creixent d'identificador
*/
void imprimir_processadors_cluster();

/** @brief Escriu l'estructura del cluster
      \pre  <em>Cert</em>
      \post Escriu l'estructura de processadors del p.i
*/
void imprimir_estructura_cluster() const;

//Consultores

/** @brief Consulta si existeix un processador
      \pre  Hi ha al canal d'entrada un identificador <em>p<em>
      \post Cert si existeix un processador amb l'identificador p al p.i, fals al contrari
*/
bool existeix_processador(string p) const;

//Operacions

/** @brief Modifica un cluster
      \pre  Hi ha al canal d'entrada un identificador de processador <em>id_proc</em> i un cluster <em>clust_aux</em>
      \post Si p no existeix, te algun procès executant-se o té algun processador auxiliar,
            dona error, al contrari el cluster cl_aux substitueix al processador p del p.i
*/
void modificar_cluster(string id_proc, Cluster clust_aux);

/** @brief Passa un procès a executar-se a un processador
      \pre  Al canal d'entrada hi ha un identificador de processador <em>id_proc</em> i les dades d'un procès <em>job</em>
      \post Si el processador no existeix al p.i, ja té un proces amb el mateix id o no
            cap, dona error, al contrari el procès <em>job</em> passa a executar-se al processador amb <em>id_proc</em>
*/
void alta_proces_processador(string id_proc, Proces &job);

/** @brief Operació per a eliminar un procès
      \pre  A l'entrada hi ha un identificador <em>id_proc</em> d'un processador i un procès
      \post Si no existeix el processador o el procès no es troba al processador,
            dona error, al contrari elimina el procès del processador
*/
void baixa_proces_processador(string id_proc,  int id_job);

/** @brief Operació per a avançar un cert temps
      \pre  Hi ha al canal d'entrada un enter t >= 0
      \post S'avança <em>t</em> temps i es modifiquen els processadors en base aquest temps
*/
void moure_temps(int t); 
/** @brief Operació per a compactar un processador
      \pre  Hi ha un identificador d'un processador <em>id_proc</em> a l'entrada
      \post Si el processador no existeix al p.i salta un error, al contrari es
            mouen tots els processos cap al principi de la memoria del processador
*/
void compactar_memoria_processador(string id_proc);

/** @brief Operació per a compactar la memòria d'un cluster
      \pre  <em>Cert</em>
      \post Tots els del p.i processadors són compactats
*/
void compactar_memoria_cluster();

};
#endif