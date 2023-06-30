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
#include <queue>
#include <map>
#endif

class Cluster {

private:

/** @brief Arbre del cluster dels identificadors dels processadors
 */
BinTree<string> arbre_id_clust;           

/** @brief Mapa del cluster ordenat per l'identificador del processador i el processador com a contingut
 */
map<string, Processador> cjt_processadors; 

/** @brief Llegeix un arbre de id_processador
      \pre  A l'entrada hi ha un cluster <em>clust</em>
      \post El cluster obté els seus elements
      \cost Lineal respecte el tamany del arbre i logarítmic respecte el tamany de cjt_processadors
*/
void llegir_arbre_clust(BinTree<string> &btp);

/** @brief Escriu cada arbre del cluster
      \pre  A l'entrada hi ha el cluster <em>btp</em>
      \post Imprimeix l'estructura del cluster
      \cost Lineal respecte el tamany de l'arbre
*/
static void escriure_arbre_clust(const BinTree<string> &btp);

/** @brief Operació per determinar el procès a afegir al fer epc
      \pre  Hi ha al canal d'entrada un proces, l'arbre del cluster, un iterador i el boleà primera
      \post Si es pot afegir a un processador, primera serà cert, fals al contrari. 
      \cost Lineal respecte el tamany de l'arbre més el de existeix_procès(logarítmic respecte els procesos) depenent del cas
            més logarítmic respecte els buits del processador al fer consultar_buit_més_ajustat 
*/
void busqueda_amplada_proc(const Proces &job, const BinTree<string>& arbre,map<string,Processador>::iterator &it_bo, bool &primera);

/** @brief Retorna el mapa de processadors
      \pre  <em>Cert</em>
      \post Retorna el mapa de processadors
      \cost Constant
*/
map<string,Processador> consultar_mapa() const;

/** @brief Retorna l'arbre de id de processadors
      \pre  <em>Cert</em>
      \post Retorna l'arbre de id de processadors
      \cost Constant
*/
BinTree<string> consultar_arbre() const;

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
      \cost De llegir_arbre_clust
*/
void configurar_cluster();

/** @brief  Imprimeix un processador
      \pre  A l'entrada un identificador del processador <em>id_proc</em>
      \post Si <em>id_proc</em> existeix al p.i, imprimeix el processador donat per <em>id_proc</em>
            al contrari, salta error
      \cost Doble cost logarítmic (veure si existeix el processador i al buscarlo per escriure) respecte cjt_processadors
*/
void imprimir_processador(string id_proc);

/** @brief Escriu tots els processadors del cluster
      \pre  <em>Cert</em>
      \post S'escriuen tots els processadors del p.i per ordre creixent d'identificador
      \cost Lineal respecte el tamany de cjt_processadors
*/
void imprimir_processadors_cluster();

/** @brief Escriu l'estructura del cluster
      \pre  <em>Cert</em>
      \post Escriu l'estructura de processadors del p.i
      \cost El mateix que escriure_arbre_clust
*/
void imprimir_estructura_cluster() const;

//Consultores

/** @brief Consulta si existeix un processador
      \pre  Hi ha al canal d'entrada un identificador <em>p<em>
      \post Cert si existeix un processador amb l'identificador p al p.i, fals al contrari
      \cost Logaritmic respecte cjt_processadors
*/
bool existeix_processador(string p) const;

//Operacions

/** @brief Passa un procès a executar-se a un processador
      \pre  Al canal d'entrada hi ha un identificador de processador <em>id_proc</em> i les dades d'un procès <em>job</em>
      \post Si el processador no existeix al p.i, ja té un proces amb el mateix id o no
            cap, dona error, al contrari el procès <em>job</em> passa a executar-se al processador amb <em>id_proc</em>
      \cost Doble logarítmic sobre cjt_processadors més el de alta_proces
*/
void alta_proces_processador(string id_proc, const Proces &job);

/** @brief Operació per a eliminar un procès
      \pre  A l'entrada hi ha un identificador <em>id_proc</em> d'un processador i un procès
      \post Si no existeix el processador o el procès no es troba al processador,
            dona error, al contrari elimina el procès del processador
      \cost Logarítmic respecte cjt_processadors
*/
void baixa_proces_processador(string id_proc,  int id_job);

/** @brief Operació per a avançar un cert temps
      \pre  Hi ha al canal d'entrada un enter t >= 0
      \post S'avança <em>t</em> temps i es modifiquen els processadors en base aquest temps
      \cost Lineal respecte el tamany de cjt_processadors més el de avanzar_temps
*/
void moure_temps(int t);

/** @brief Modifica un cluster
      \pre  Hi ha al canal d'entrada un identificador de processador <em>id_proc</em> 
      \post Si p no existeix, te algun procès executant-se o té algun processador auxiliar,
            dona error, al contrari el cluster cl_aux substitueix al processador p del p.i
      \cost Cas pitjor: Logarítmic sobre cjt_processadors més el de configurar_cluster i busca_proc_aux_cluster
            més logarítmic i lineal respecte cjt_processadors al insertar un mapa nou
*/          
void modificar_cluster(string id_proc, Cluster &clust_extra);

/** @brief Operació per a afegir un cluster a un processador
      \pre  A l'entrada hi ha un identificador <em>id_proc</em> d'un processador i un Cluster
      \post Si el processador te processadors auxiliars, imprimeix error, al contrari s'afegeix el Cluster
      \cost Lineal respecte arbre_id_clust fins arribar al processador dessitjat
*/

void busca_proc_aux_cluster(string id_proc, const Cluster &clust_extra, BinTree<string> &arbre_id_clust, bool &te_aux);

/** @brief Operació per a compactar un processador
      \pre  Hi ha un identificador d'un processador <em>id_proc</em> a l'entrada
      \post Si el processador no existeix al p.i salta un error, al contrari es
            mouen tots els processos cap al principi de la memoria del processador
      \cost Logarítmic respecte cjt_processadors més compactar_memoria_proces
*/
void compactar_memoria_processador(string id_proc);

/** @brief Operació per a compactar la memòria d'un cluster
      \pre  <em>Cert</em>
      \post Tots els del p.i processadors són compactats
      \cost Lineal respecte cjt_processadors (més compactar_memoria_processador a cada iteració)
*/
void compactar_memoria_cluster();

/** @brief Operació per determinar i afegir un proces a un processador
      \pre  Hi ha al canal d'entrada un proces i un bolea, que indica si s'ha pogut afegir el proces
      \post Si s'ha pogut afegir, afegit serà cert, fals al contrari. 
      \cost El de busqueda_amplada_proc més alta_procès
*/
void afegir_proces_cond(const Proces &job, bool &afegit); 
};
#endif