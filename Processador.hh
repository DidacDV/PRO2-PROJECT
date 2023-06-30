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
/** @brief Memòria lliure del processador
 */
int mem_lliure;

/** @brief Identificador del procesador i la seva memòria total
 */
pair<string, int> proc;  

/** @brief Mapa ordenat per posició del procès dins del processador i el procès
 */
map <int,Proces> cjt_job;   

/** @brief Mapa ordenat per identificador del procès i la posició d'aquest procès
 */
map <int,int> cjt_job_mem;          

/** @brief Mapa ordenat pel tamany de buits de la memoria i un set de posicions amb aquests buits
 */
map <int, set<int>> cjt_buits;      

/** @brief Operació per a eliminar processos
      \pre A l'entrada hi ha un identificador d'un proces <em>id_job</em>
      \post S'elimina el proces del p.i
      \cost En el pitjor cas, 5 cops logaritmic (per tots el erase i insert als mapes i sets donant valors) respecte cjt_buits
            més  un cost constant respecte cjt_job (borrar amb it)
*/
void eliminar_proces(int id_job, map<int,Proces>::iterator &it);

public:

//Constructores

/** @brief Creadora sense dades
      \pre <em>Cert</em>
      \post El resultat és un processador sense atributs
*/
Processador();

/** @brief Creadora amb id i memoria
      \pre a l'entrada hi ha un string <em>id_processador</em> i un enter <em>mem</em>
      \post El resultat és un processador amb una certa memòria i identificador
      \cost Constant
*/
Processador(string id_proc, int mem);

//Consultores

/** @brief Consultra de si existeix un procès dins d'un processador
      \pre A l'entrada hi ha un identificador d'un procès job <em>id_job</em>
      \post Cert si el p.i té el procès <em>job</em>, fals al contrari
      \cost Logarítmic respecte cjt_job_mem
*/
bool existeix_proces(int id_job) const;

/** @brief Consultora de l'id d'un processador
      \pre <em>Cert</em>
      \post Retorna l'id del processador
      \cost Constant
*/
string consultar_id_proc();

/** @brief Consultora de si un processador té processos
      \pre <em>Cert</em>
      \post Cert si el p.i té processos executant-se, fals al contrari
      \cost Constant
*/
bool te_processos() const;

/** @brief Consultora de la memoria lliure d'un processador
      \pre <em>Cert</em>
      \post Retorna la memoria lliure del processador
      \cost Constant
*/
int consultar_mem_lliure() const;

/** @brief Consultora del buit més ajustat i on es troba del processador
      \pre A l'entrada hi ha el tamany que ocupa un procès
      \post Retorna el tamany més ajustat per a tal procès o retorna -1 si no cap el procès
      \cost Logarítmic respecte cjt_buits
*/
int consultar_buit_mes_ajustat(int mem_proces) const;

//Entrada i sortida

/** @brief Operació de escriptura
      \pre <em>Cert</em>
      \post S'escriuen els processos del p.i per ordre creixent de primera posició de memòria, per
            per cada procès, s'escriu el temps restant per a que acabi
      \cost Lineal respecte el tamany de cjt_job
*/
void escriure_processador() const;

//Operacions

/** @brief Elimina un proces d'un processador
      \pre A l'entrada hi ha l'identificador d'un proces
      \post Si el proces existeix al processador, s'elimina, al contrari salta error
      \cost Doble logarítmic respecte cjt_job_mem i logarítmic cjt_job més el cost de eliminar_proces
*/
void baixa_proces(int id_job);

/** @brief Operació per modificar el temps transcorregut d'un processador
      \pre A l'entrada hi ha un enter <em>t</em>
      \post El temps es mou t unitats
      \cost Lineal sobre el tamany de cjt_job
*/
void avanzar_temps_processador(int t);

/** @brief Afegeix un proces a un processador
      \pre A l'entrada hi ha un procès
      \post Si el procès no existeix al processador, s'afegeix, al contrari salta error
      \cost Doble logarítmic respecte cjt_job_mem (busqueda i afegir), en el pitjor cas respecte cjt_buits també doble logaritmic i 
            logarítmic respecte cjt_job (afegir) i constant respecte el set de cjt_buits
*/
void alta_proces(const Proces &job);

/** @brief Retorna la memoria d'un procès
      \pre A l'entrada hi ha l'id d'una memòria
      \post Retorna la memòria del procès
      \cost Logarítmic respecte cjt_job
*/
int consultar_memoria_proces(int id_job);

/** @brief Compacta la memòria d'un processador
      \pre <em>Cert</em>
      \post La memòria del processador queda compactada
      \cost Lineal respecte el tamany de cjt_job i en el pitjor cas logarítmic respecte cjt_job_mem
            cjt_job (al fer insert i erase) més constant (erase amb it) tants cops com tamany de cjt_job
*/
void compactar_memoria_processador();
};
#endif