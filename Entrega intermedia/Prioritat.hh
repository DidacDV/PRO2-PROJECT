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
#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include <map>
#include <list>
#endif

class Prioritat {
private:
    map<int,Proces> proc_pend;
    list<Proces> list_proc_pendent;
    int n_acceptats = 0;
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
      \post Cert si el p.i té el procès <em>id_job<em>, fals al contrari
*/
bool existeix_proces(int id_job) const;

/** @brief Consulta si hi han procesos pendents
    \pre  <em>Cert</em>
    \post Cert si hi han processos pendents a la prioritat del p.i, fals al contrari
*/
bool te_processos_pendents_prio() const;

/** @brief Consulta el nombre de processos enviats d'una prioritat
    \pre  <em>Cert</em>
    \post Retorna el nombre de processos enviats del de la propietat
*/
int consultar_n_enviats_prio() const;

/** @brief Consulta el nombre de processos rebutjats d'una prioriat
    \pre  <em>Cert</em>
    \post Retorna el nombre de processos rebutjats del p.i
*/
int consultar_n_rebutjats_prio() const;

//Entrada i sortida

/** @brief S'imprimeix una prioritat i escriu el numero de processos de tal
           prioritat que han sigut rebutjats i acceptats amb la operacio epc
    \pre  <em>Cert</em>
    \post S'escriuen els processos pendents de la prioritat i el número d'acceptats
          i rebutjats de la prioritat
*/
void imprimir_prioritat_prio() const;

//Operacions

/** @brief Augmenta el nombre de processos enviats d'una prioritat
    \pre  <em>Cert</em>
    \post Augmenta el nombre de processos enviats del p.i 
*/
void augmentar_n_enviats_prio();

/** @brief Augmenta el nombre de processos rebutjats d'una prioritat
    \pre  <em>Cert</em>
    \post Augmenta el nombre de processos rebutjats del p.i
*/
void augmentar_n_rebutjats_prio();

/** @brief Envia un procès a una prioritat
    \pre  A l'entrada hi ha un procès <em>job</em>
    \post El procès és afegit a la prioritat
*/
void alta_proces_espera_prio(Proces job);

/** @brief Esborra un procès d'una certa prioritat
    \pre  A l'entrada hi ha un identificador de procès <em>id_job</em>
    \post Esborra el procès amb <em>id_job</em> del p.i
*/
void baixa_proces_espera_prio(int id_job);

};
#endif