/** @file Proces.hh
    @brief Especificació de la classe Proces
*/

#ifndef PROCES_HH
#define PROCES_HH

#ifndef NO_DIAGRAM
#include <iostream>
#endif

// Classe Procès

/** @class Proces
	@brief Representa un Proces
*/
using namespace std;

class Proces {

private:
/** @brief Identificador del procès
 */
int id_job;

/** @brief Memoria que ocupa el procès
 */
int mem_neces;     

/** @brief Temps d'execució del procès
 */
int temps_exec;  

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
    \cost Constant 
*/
int consultar_mem_neces() const;

/** @brief Consulta el temps que li queda al procès
    \pre  <em>Cert</em>
    \post Retorna el temps restant del proces, si es 0 vol dir que ha finalitzat
    \cost Constant
*/
int consultar_temps_exec() const;

/** @brief Consulta un procès
    \pre  <em>Cert</em>
    \post Retorna la id del procès
    \cost Constant
*/
int consultar_id_proces() const;


//Entrada i sortida

/** @brief LLegeix un proces
    \pre  Hi ha al canal d'entrada un identificador d'un procès <em>id_job</em>, la memoria necessaria <em>mem_neces</em> del proces i el seu
          temps d'execució <em>temps_exec</em>
    \post Els p.i passa a tenir els atributs d'entrada
    \cost Constant
*/
void llegir_proces();

/** @brief Escriu un procès
    \pre  <em>Cert</em>
    \post S'escriu el p.i
    \cost Constant
*/
void escriure_proces() const;

//Operacions

/** @brief Modifica el temps d'un procès
    \pre  A l'entrada hi ha el temps transcorregut
    \post El temps del p.i es veu afectat pel temps transcorregut
    \cost Constant
*/
void modificar_temps(int t);
};
#endif