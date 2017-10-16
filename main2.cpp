#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h> 
#include <unistd.h>

int indexOf(std::vector<char> vars,char c){
	std::vector<char>::iterator it=std::find(vars.begin(), vars.end(), c);
	int dist = std::distance(vars.begin(),it);
	return dist; 
}

int main(int argc, char *const *argv)
{

	char *ivalue = NULL;
	char *svalue = NULL;
	int index;
	int c;
	opterr = 0;
	double** matriz;

	while ((c = getopt (argc, argv, "i:s:")) != -1)
		switch (c)
		{
			case 'i':
				ivalue = optarg;
				break;
			case 's':
				svalue = optarg;
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
	if(ivalue&&svalue){
		std::ifstream f (ivalue);
		std::vector<char> estados;
		int numVariables=0;
		std::string cadena=std::string(svalue);
		if (f.is_open()) { 
			f>>numVariables;
			matriz= new double*[numVariables];
			std::string vars;
			f>>vars;
			for (int i = 0; i < numVariables; ++i)
			{
				estados.insert(estados.end(),vars.at(i));
			}

			for (int i = 0; i < numVariables; ++i)
			{
				std::string s;
				matriz[i] = new double[numVariables];
				f>>s;
				std::istringstream g(s);
				std::string _s; 

				for (int j=0;getline(g, _s, ';');j++) {
					double p = std::strtold (_s.c_str(), NULL);
					matriz[i][j]=p;
				}
			}
			double probabilidad=1;
			int j=-1;
			for (int k = 0; k < cadena.length(); ++k)
			{
				int i=j;
				j=indexOf(estados,cadena.at(k));
				if(i<0)continue;
				else{
					probabilidad*=matriz[i][j];
				}

			}
			std::cout<<"La probabilidad es: "<<probabilidad<<'\n';
		}
	}
	return 0;
}