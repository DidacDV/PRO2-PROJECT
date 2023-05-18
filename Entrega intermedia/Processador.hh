/** @file Processador.hh
    @brief Especificació de la classe Processador
*/
#ifndef PROCESSADOR_HH
#define PROCESSADOR_HH

// Classe Processador

/** @class Processador
	@brief Representa un Processador
*/

#include "Proces.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <set>
#endif

class Processador {

private:
int mem_total;
pair<string, int> proc;             //string = id_proc, int = memoria del processador
map <int,Proces> cjt_job;           // Clau: index memoria, Contingut: proces
map <int,int> cjt_job_mem;          // Clau: id job, Contingut: index mem
map <int, set<int>> cjt_buits;      // Clau: tamany buit, Contingut: index mem
public:

//Constructores

/** @brief Creadora sense dades
      \pre <em>Cert</em>
      \post El resultat és un processador sense memoria disponible i sense identificador
*/
Processador();

/** @brief Creadora amb id i memoria
      \pre a l'entrada hi ha un string <em>id_processador</em> i un enter <em>mem</em>
      \post El resultat és un processador amb una certa memòria i un identificador
*/
Processador(string id_proc, int mem);

//Consultores

/** @brief Consultra de si existeix un procès dins d'un processador
      \pre A l'entrada hi ha un identificador d'un procès job <em>id_job</em>
      \post Cert si el p.i té el procès <em>job<em>, fals al contrari
*/
bool existeix_proces(int id_job) const;

/** @brief Consultora de l'id d'un processador
      \pre <em>Cert</em>
      \post Retorna l'id del processador
*/
string consultar_id_proc();

/** @brief Consultora de si un processador té processos
      \pre <em>Cert</em>
      \post Cert si el p.i té processos executant-se, fals al contrari
*/
bool te_processos() const;

/** @brief Consultra de si un processador té processadors auxiliars
      \pre <em>Cert</em>
      \post Cert si el p.i té processos auxiliars, fals al contrari
*/
bool te_processadors_aux() const;

//Entrada i sortida

/** @brief Operació de escriptura
      \pre <em>Cert</em>
      \post S'escriuen els processos del p.i per ordre creixent de primera posició de memòria, per
            per cada procès, s'escriu el temps restant per a que acabi
*/
void escriure_processador();

//Operacions

/** @brief Operació per a eliminar processos
      \pre A l'entrada hi ha un identificador d'un proces <em>id_job</em>
      \post S'elimina el proces del p.i
*/
void eliminar_proces(int id_job, map<int,Proces>::iterator &it);

/** @brief Operació per modificar el temps transcorregut d'un processador
      \pre A l'entrada hi ha un enter <em>t</em>
      \post El temps es mou t unitats
*/
void avanzar_temps_processador(int t);

/** @brief Afegeix un proces a un processador
      \pre A l'entrada hi ha un procès
      \post Si el procès no existeix al processador, s'afegeix, al contrari salta error
*/
void alta_proces(Proces &job);

/** @brief Retorna la memoria d'un procès
      \pre A l'entrada hi ha l'id d'una memòria
      \post Retorna la memòria del procès
*/
int consultar_memoria_proces(int id_job);

/** @brief Compacta la memòria d'un processador
      \pre <em>Cert<\em>
      \post La memòria del processador queda compactada
*/
void compactar_memoria_processador();

/** @brief Elimina un proces d'un processador
      \pre A l'entrada hi ha l'identificador d'un proces
      \post Si el proces existeix al processador, s'elimina, al contrari salta error
*/
void baixa_proces(int id_job);

};
#endif