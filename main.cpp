
#include "VirtualClasses.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
int main(int argc, char *const *argv)
{
	
	char *ivalue = NULL;
	char *Nvalue = NULL;
	char *ovalue = NULL;
	int index;
	int c;

	opterr = 0;

	while ((c = getopt (argc, argv, "i:N:o:")) != -1)
		switch (c)
		{
			case 'i':
				ivalue = optarg;
				break;
			case 'N':
				Nvalue = optarg;
				break;
			case 'o':
				ovalue = optarg;
				break;
			case '?':
				if (optopt == 'i')
					fprintf (stderr, "Opcion -%c necesita un argumento.\n", optopt);
				else if (isprint (optopt))
					fprintf (stderr, "Opcion desconocida `-%c'.\n", optopt);
				else
					fprintf (stderr,
						"Caracter desconocido `\\x%x'.\n",
						optopt);
				return 1;
			default:
				abort ();
		}
	if(ivalue&&Nvalue&&ovalue){
		std::cout<<"█████████████████████████████████████████"<<std::endl;
		std::cout<<"██                                     ██"<<std::endl;
		std::cout<<"██  Generador de matriz de transicion  ██"<<std::endl;
		std::cout<<"██                                     ██"<<std::endl;
		std::cout<<"█████████████████████████████████████████"<<std::endl;
		printf ("» i = %s, N = %s,\n\t» o = %s «  \n",
			ivalue, Nvalue, ovalue);
		int n = atoi(Nvalue);
		n++;n--;
		MatrizATCG* m = new MatrizATCG(n);
		std::cout<<"┌──────────────────────────────────────┐"<<std::endl;
		contarEstados(std::string(ivalue),m);
		std::cout<<"└──────────────────────────────────────┘"<<std::endl;
		std::ofstream fs (std::string(ovalue),std::ofstream::binary);

		fs << m->toString();
		fs.close();
	}
	else
		printf ("Faltan argumentos");
	

	for (index = optind; index < argc; index++)
		printf ("Non-option argument %s\n", argv[index]);

	
	return 0;
}