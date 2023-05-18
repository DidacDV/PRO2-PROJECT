/** @file Area_espera.hh
    @brief Especificació de la classe Area_espera
*/

#ifndef AREA_ESPERA_HH
#define AREA_ESPERA_HH

// Classe Procès

/** @class Area_espera
	@brief Representa una Area_espera
*/
#include "Proces.hh"
#include "Cluster.hh"
#include "Prioritat.hh"
#ifndef NO_DIAGRAM
#include <string>
#include <map>
#include <vector>
#endif

class Area_espera {

private:
map <string, Prioritat> cjt_prioritats;     // Clau: identificador_prioritat, Contingut: Prioritat
public:

//Constructora
/** @brief Crea una area de espera buida
    \pre  <em>Cert</em>
    \post Crea una àrea de espera buida
*/
Area_espera();

//Consultores

/** @brief Consulta si existeix una prioritat
    \pre  A l'entrada hi ha un identificador de prioritat <em>id_prioritat</em>
    \post Cert si <em>id_prioritat</em> es troba al p.i, fals al contrari
*/

bool existeix_prio(string id_prioritat);

/** @brief Consulta una prioritat
    \pre  A l'entrada hi ha un identificador de prioritat <em>id_prioritat</em> que existeix
    \post Retorna la prioritat amb <em> id_prioritat</em>
*/
Prioritat consultar_prioritat(string id_prioritat);

/** @brief Consulta si hi han procesos pendents
    \pre  A l'entrada hi ha un identificador d'una prioritat <em>id_prioritat</em>
    \post Cert si hi han processos pendents a la prioritat indicada per <em>id_prioritat</em>, fals al contrari
*/
bool te_processos_pendents(string id_prioritat) const;

/** @brief Consulta el nombre de processos enviats d'una prioritat
    \pre  A l'entrada hi ha l'identificador d'una prioritat <em>id_prioritat</em>
    \post Retorna el nombre de processos enviats del p.i de la <em>id_prioritat</em>
*/
int consultar_n_enviats(string id_prioritat) const;

/** @brief Consulta el nombre de processos rebutjats d'una prioriat
    \pre  A l'entrada hi ha l'identificador d'una prioritat <em>id_prioritat</em>
    \post Retorna el nombre de processos rebutjats del p.i de la <em>id_prioritat</em>
*/
int consultar_n_rebutjats(string id_prioritat) const;

//Entrada i sortida

/** @brief Llegeix una area d'espera
    \pre  <em>Cert</em>
    \post Es llegeix una àrea d'espera
*/
void llegir();

/** @brief S'imprimeix una prioritat i escriu el numero de processos de tal
           prioritat que han sigut rebutjats i acceptats amb la operacio epc
    \pre  A l'entrada hi ha un identificador de propietat <em>id_prioritat</em>
    \post Si no existeix una prioritat amb <em>id_prioritat</em>, salta error, al contrari
          s'escriuen els processos pendents de la prioritat i el número d'acceptats
          i rebutjats de tal prioritat del p.i
*/
void imprimir_prioritat(string id_prioritat);

/** @brief S'imprimeixen totes les prioritats de l'àrea d'espera
    \pre  <em>Cert</em>
    \post S'imprimeixen totes les prioritats del p.i
*/
void imprimir_area_espera() const;

//Operacions

/** @brief Envia un procès a l'àrea d'espera amb una certa prioritat
    \pre  A l'entrada hi ha un procès <em>job</em> i l'identificador d'una prioritat <em>id_prioritat</em>
    \post Afegeix un procès <em>job</em> a la prioritat amb <em>id_prioritat</em>
*/
void alta_proces_espera(Proces job, string id_prioritat);

/** @brief Esborra un procès d'una certa prioritat
    \pre  A l'entrada hi ha un identificador de procès <em>id_job</em> i l'identificador d'una prioritat <em>id_prioritat</em>
    \post Esborra el procès amb <em>id_job</em> de la propietat <em>id_prioritat</em>
*/
void baixa_proces_espera(int id_job, string id_prioritat);

/** @brief Augmenta el nombre de processos enviats d'una prioritat
    \pre  A l'entrada hi ha l'identificador d'una prioritat <em>id_prioritat</em>
    \post Augmenta el nombre de processos enviats del p.i de la <em>id_prioritat</em>
*/
void augmentar_n_enviats(string id_prioritat);

/** @brief Augmenta el nombre de processos rebutjats d'una prioritat
    \pre  A l'entrada hi ha l'identificador d'una prioritat <em>id_prioritat</em>
    \post Augmenta el nombre de processos rebutjats del p.i de la <em>id_prioritat</em>
*/
void augmentar_n_rebutjats(string id_prioritat);

/** @brief Afegeix una prioritat a l'àrea d'espera
    \pre  A l'entrada hi ha un identificador de prioritat <em>id_prioritat</em>
    \post Si <em>id_prioritat</em> no existeix al p.i, s'afegeix al p.i la propietat 
          amb <em>id_prioritat</em>, al contrari s'imprimeix un missatge d'error
*/
void alta_prioritat(string id_prioritat);

/** @brief Esborra una prioritat de l'àrea d'espera
    \pre  A l'entrada hi ha un identificador de prioritat <em>id_prioritat</em>
    \post Si <em>id_prioritat</em> existeix, la prioritat amb <em>id_prioritat</em>
          es esborrada del p.i, al contrari s'imprimeix un missatge d'error
*/
void baixa_prioritat(string id_prioritat);

/** @brief  S'intenta enviar al cluster un nombre determinat de procesos pendents
    \pre  A l'entrada hi ha un enter no negatiu <em>n</em> que es el nombre de processos que s'intentaran enviar
    \post S'intenten enviar <em>n</em> processos pendents de l'àrea cap al p.i seguint
          certes normes
*/
void enviar_processos_cluster(int n);

};
#endif