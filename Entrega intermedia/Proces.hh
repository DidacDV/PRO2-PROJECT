/** @file Proces.hh
    @brief Especificació de la classe Proces
*/

#ifndef PROCES_HH
#define PROCES_HH

// Classe Procès

/** @class Proces
	@brief Representa un Proces
*/
using namespace std;

class Proces {

private:
int id_job;
int mem_neces;      // Memòria necessària per executar el procès, sempre > 0
int temps_exec;     // Temps d'execució del procès, sempre > 0

public:

//Constructores
/** @brief Crea un procès buit
    \pre  <em>Cert</em>
    \post Crea un procès buit
*/
Proces();

//Consultores

/** @brief Consulta la memoria que ocupa el procès
    \pre  <em>Cert</em>
    \post Retorna la memoria <em>mem_neces</em> que necessita el p.i 
*/
int consultar_mem_neces() const;

/** @brief Consulta el temps que li queda al procès
    \pre  <em>Cert</em>
    \post Retorna el temps restant del proces, si es 0 vol dir que ha finalitzat
*/
int consultar_temps_exec() const;

/** @brief Consulta un procès
    \pre  <em>Cert</em>
    \post Retorna el procès amb id_job
*/
Proces consultar_proces() const;

/** @brief Consulta un procès
    \pre  <em>Cert</em>
    \post Retorna la id del procès
*/
int consultar_id_proces() const;

//Entrada i sortida

/** @brief LLegeix un proces
    \pre  Hi ha al canal d'entrada un identificador d'un procès <em>id_job</em>, la memoria necessaria <em>mem_neces</em> del proces i el seu
          temps d'execució <em>temps_exec</em>
    \post Els p.i passa a tenir els atributs d'entrada
*/
void llegir_proces();

/** @brief Escriu un procès
    \pre  <em>Cert</em>
    \post S'escriu el p.i
*/
void escriure_proces() const;

//Operacions

/** @brief Modifica el temps d'un procès
    \pre  A l'entrada hi ha el temps transcorregut
    \post El temps del p.i es veu afectat pel temps transcorregut
*/
void modificar_temps(int t);
};
#endif