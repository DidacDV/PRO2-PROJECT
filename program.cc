/** 
 * @mainpage Pràctica: Simulació del rendiment de processadors interconnectats.

La pràctica constitueix en un programa modular que imita el funcionament de processadors interconnectats.
S'utilitzen les classes <em>Cluster</em>, <em>Processador</em>, <em>Proces</em>, <em>Area_espera</em> i <em>Prioritat</em>.
*/

/** @file main.cc
	@brief Programa principal

*/

#include "Cluster.hh"
#include "Proces.hh"
#include "Area_espera.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

int main() {
    Cluster cl;
    cl.configurar_cluster();
    Area_espera ae;
    ae.llegir();
    string comando;
    cin >> comando;
    while (comando != "fin") {
        if (comando == "configurar_cluster" or comando == "cc") {           //1
            cout << "#" << comando << endl;
            cl.configurar_cluster();                        
        }

        else if (comando == "modificar_cluster" or comando == "mc") {       //2
            string p;
            cin >> p;
            cout << "#" << comando << " " << p << endl;
            Cluster clust_extra;
            cl.modificar_cluster(p, clust_extra);
        }

        else if (comando == "alta_prioridad" or comando == "ap") {          //3
            string p;
            cin >> p;
            cout << "#" << comando << " " << p << endl;
            ae.alta_prioritat(p);
        }

        else if (comando == "baja_prioridad" or comando == "bp") {          //4
            string p;
            cin >> p;
            cout << "#" << comando << " " << p << endl;
            ae.baixa_prioritat(p);
        }

        else if (comando == "alta_proceso_espera" or comando == "ape") {    //5
            string id_prior;
            cin >> id_prior;
            Proces job;
            job.llegir_proces();
            int id_job = job.consultar_id_proces();
            cout << "#" << comando << " " << id_prior << " " << id_job << endl;
            ae.alta_proces_espera(job, id_prior);
        }

        else if (comando == "alta_proceso_procesador" or comando == "app") {    //6
            string id_prc;
            cin >> id_prc;
            Proces job;
            job.llegir_proces();
            cout << "#" << comando << " " << id_prc << " "  << job.consultar_id_proces() << endl;
            cl.alta_proces_processador(id_prc, job);
        }

        else if (comando == "baja_proceso_procesador" or comando == "bpp") {    //7
            cout << "#" << comando << " ";
            string id_prc;
            cin >> id_prc;
            int id_job;
            cin >> id_job;
            cout << id_prc << " " << id_job << endl;
            cl.baixa_proces_processador(id_prc, id_job);
        }

        else if (comando == "enviar_procesos_cluster" or comando == "epc") {
            int n;
            cin >> n;
            cout << "#" << comando << " " << n << endl;
            ae.enviar_processos_cluster(cl, n);
        }

        else if (comando == "avanzar_tiempo" or comando == "at") {              //9
            int t;
            cin >> t;
            cout << "#" << comando << " " << t << endl;
            cl.moure_temps(t);
        }

        else if (comando == "imprimir_prioridad" or comando == "ipri") {        //10
            string id_prio;
            cin >> id_prio;
            cout << "#" << comando << " " << id_prio << endl;
            ae.imprimir_prioritat(id_prio);
        }

        else if (comando == "imprimir_area_espera" or comando == "iae") {       //11
            cout << "#" << comando << endl;
            ae.imprimir_area_espera();            
        }

        else if (comando == "imprimir_procesador" or comando == "ipro") {        //12
            string id_prc;
            cin >> id_prc;
            cout << "#" << comando << " " << id_prc << endl;
            cl.imprimir_processador(id_prc);
        }

        else if (comando == "imprimir_procesadores_cluster" or comando == "ipc") {    //13
            cout << "#" << comando << endl;
            cl.imprimir_processadors_cluster();   
        }

        else if (comando == "imprimir_estructura_cluster" or comando == "iec") {        //14
            cout << "#" << comando << endl;
            cl.imprimir_estructura_cluster();     
        }
        
        else if (comando == "compactar_memoria_procesador" or comando == "cmp") {       //15
            string id_proc;
            cin >> id_proc;
            cout << "#" << comando << " " << id_proc << endl;
            cl.compactar_memoria_processador(id_proc);
        }

        else if (comando == "compactar_memoria_cluster" or comando == "cmc") {          //16
            cout << "#" << comando << endl;
            cl.compactar_memoria_cluster();
        }
        cin >> comando;
    }
}