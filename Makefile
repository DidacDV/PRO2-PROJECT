OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Cluster.o Area_espera.o Prioritat.o Proces.o Processador.o
	g++ -o program.exe *.o
Cluster.o: Area_espera.hh Processador.hh Prioritat.hh Proces.hh
	g++ -c Cluster.cc $(OPCIONS)
Area_espera.o: Prioritat.hh Proces.hh Cluster.hh
	g++ -c Area_espera.cc $(OPCIONS) 
Prioritat.o: Proces.hh Cluster.hh
	g++ -c Prioritat.cc $(OPCIONS)
Proces.o: 
	g++ -c Proces.cc $(OPCIONS)
Processador.o: Proces.hh 
	g++ -c Processador.cc $(OPCIONS)
program.o: program.cc Processador.hh Proces.hh Prioritat.hh Cluster.hh Area_espera.hh
	g++ -c program.cc $(OPCIONS)


clean:
	rm *.o
	rm *.x
	rm *.tar

practica.tar:
	tar -cvf practica.tar *.cc *.hh Makefile