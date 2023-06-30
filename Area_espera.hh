/** @file Area_espera.hh
    @brief Especificació de la classe Area_espera
*/

#ifndef AREA_ESPERA_HH
#define AREA_ESPERA_HH

// Classe Procès

/** @class Area_espera
	@brief Representa una Area_espera
*/
#include "Cluster.hh"
#include "Prioritat.hh"
#ifndef NO_DIAGRAM
#include <string>
#include <map>
#include <vector>
#endif

class Area_espera {

private:

/** @brief Mapa ordenat per identificador de la prioritat i valor la prioritat
 */
map <string, Prioritat> cjt_prioritats;
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
    \cost Logarítmic sobre el mapa cjt_prioritats
*/
bool existeix_prio(string id_prioritat);

//Entrada i sortida

/** @brief Llegeix una area d'espera
    \pre  <em>Cert</em>
    \post Es llegeix una àrea d'espera
    \cost Lineal sobre el nombre de prioritats que té l'àrea d'espera
*/
void llegir();

/** @brief S'imprimeix una prioritat i escriu el numero de processos de tal
           prioritat que han sigut rebutjats i acceptats amb la operacio epc
    \pre  A l'entrada hi ha un identificador de propietat <em>id_prioritat</em>
    \post Si no existeix una prioritat amb <em>id_prioritat</em>, salta error, al contrari
          s'escriuen els processos pendents de la prioritat i el número d'acceptats
          i rebutjats de tal prioritat del p.i
    \cost Doble logarítmic sobre el mapa de cjt_prioritats (per veure si existeix) i lineal
          a la quantitat de procesos de la prioritat
*/
void imprimir_prioritat(string id_prioritat);

/** @brief S'imprimeixen totes les prioritats de l'àrea d'espera
    \pre  <em>Cert</em>
    \post S'imprimeixen totes les prioritats del p.i
    \cost Lineal respecte al tamany de cjt_prioritats, després s'aplica el cost de imprimir
          prioritat a cada iteració
*/
void imprimir_area_espera() const;

//Operacions

/** @brief Envia un procès a l'àrea d'espera amb una certa prioritat
    \pre  A l'entrada hi ha un procès <em>job</em> i l'identificador d'una prioritat <em>id_prioritat</em>
    \post Afegeix un procès <em>job</em> a la prioritat amb <em>id_prioritat</em>
    \cost Doble logarítmic respecte cjt_prioritats més el cost de alta_proces_espera_prio
*/
void alta_proces_espera(const Proces &job, string id_prioritat);

/** @brief Afegeix una prioritat a l'àrea d'espera
    \pre  A l'entrada hi ha un identificador de prioritat <em>id_prioritat</em>
    \post Si <em>id_prioritat</em> no existeix al p.i, s'afegeix al p.i la propietat 
          amb <em>id_prioritat</em>, al contrari s'imprimeix un missatge d'error
    \cost Logarítmic respecte cjt_prioritats
*/
void alta_prioritat(string id_prioritat);

/** @brief Esborra una prioritat de l'àrea d'espera
    \pre  A l'entrada hi ha un identificador de prioritat <em>id_prioritat</em>
    \post Si <em>id_prioritat</em> existeix, la prioritat amb <em>id_prioritat</em>
          es esborrada del p.i, al contrari s'imprimeix un missatge d'error, també en el cas de que la prioritat 
          tingui procesos pendents
    \cost Doble logarítmic respecte cjt_prioritats
*/
void baixa_prioritat(string id_prioritat);

/** @brief  S'intenta enviar al cluster un nombre determinat de procesos pendents
    \pre  A l'entrada hi ha un enter no negatiu <em>n</em> que es el nombre de processos que s'intentaran enviar
          al cluster <em>clust</em>
    \post S'intenten enviar <em>n</em> processos pendents de l'àrea cap al p.i seguint
          certes normes
    \cost Lineal respecte n i el tamany de cjt_prioritats depenent qui acabi abans més el cost de enviar_cluster
          per cada iteració
*/
void enviar_processos_cluster(Cluster &clust ,int n);

};
#endif