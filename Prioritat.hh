/** @file Prioritat.hh
    @brief Especificació de la classe Prioritat
*/

#ifndef PRIORITAT_HH
#define PRIORITAT_HH

// Classe Prioritat

/** @class Prioritat
	@brief Representa una Prioritat
*/
#include "Proces.hh"
#include "Cluster.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#endif

class Prioritat {
private:

/** @brief Mapa de procesos pendents d'una prioritat ordenat per ordre de prioritat
 */
    map<int,Proces> proc_pend;          // Clau: id_procès, Contingut: procès

/** @brief Llista de procesos pendents d'una prioritat
 */
    list<Proces> list_proc_pendent;     // Llista de procesos

/** @brief Nombre de procesos acceptats d'una prioritat
 */
    int n_acceptats = 0;             

/** @brief Mapa de procesos rebutjats d'una prioritat
 */
    int n_rebutjats = 0;

public:

//Constructora
/** @brief Crea una prioritat buida
    \pre  <em>Cert</em>
    \post Crea una prioritat buida
*/
Prioritat();

//Consultores

/** @brief Consultra de si existeix un procès dins d'un processador
      \pre A l'entrada hi ha un identificador d'un procès <em>id_job</em>
      \post Cert si el p.i té el procès <em>id_job</em>, fals al contrari
      \cost Cost logarítmic sobre el mapa proc_pend
*/
bool existeix_proces(int id_job) const;

/** @brief Consulta si hi han procesos pendents
    \pre  <em>Cert</em>
    \post Cert si hi han processos pendents a la prioritat del p.i, fals al contrari
    \cost Constant
*/
bool te_processos_pendents_prio() const;

//Entrada i sortida

/** @brief S'imprimeix una prioritat i escriu el numero de processos de tal
           prioritat que han sigut rebutjats i acceptats amb la operacio epc
    \pre  <em>Cert</em>
    \post S'escriuen els processos pendents de la prioritat i el número d'acceptats
          i rebutjats de la prioritat
    \cost Cost lineal sobre el tamany de list_proc_pendent
*/
void imprimir_prioritat_prio() const;

//Operacions

/** @brief Envia un procès a una prioritat
    \pre  A l'entrada hi ha un procès <em>job</em>
    \post El procès és afegit a la prioritat
    \cost Cost doble logaritmic sobre el mapa proc_pend (al buscar si existeix i afegir) i 
          constant al afegir a la llista list_proc_pendent 
*/
void alta_proces_espera_prio(const Proces &job);

/** @brief Intenta enviar un procès al Cluster
    \pre  A l'entrada hi ha n, que es el nombre de processos restants a intentar enviar
    \post S'intenten enviar n processos al cluster
    \cost Cost lineal sobre n, lineal i constant (al borrar) sobre la llista i lineal respecte afegir_proces_cond
          a cada iteració
*/
void enviar_cluster(Cluster &clust, int &n);

};
#endif