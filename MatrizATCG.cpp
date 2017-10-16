#include "VirtualClasses.h"
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
void MatrizATCG::VirtualMatrizP::normalizarMatriz(){
	//normalizacion
	unsigned long long int sumaRow;
	int j;
	for (int i = 0; i < this->numEstados; ++i)
	{
	 	sumaRow=0;
	 	for (j = 0; j < this->numEstados; ++j)//se suman la cantidad contada
			sumaRow+=this->matriz[i][j];
		double k=0;
		for (j = 0; j < this->numEstados-1; ++j)//se dividen respecto a la cantidad de elementos 
		{
			this->normMatriz[i][j]=((double)this->matriz[i][j])/sumaRow;
			k=k+this->normMatriz[i][j];
		}
		this->normMatriz[i][this->numEstados-1]=1-k;
	} 
}
void MatrizATCG::VirtualMatrizP::Pijpp(int i,int j){
	this->matriz[i][j]++;
}
unsigned long long int MatrizATCG::VirtualMatrizP::getPij(int i,int j){
	return this->matriz[i][j];
}
double MatrizATCG::VirtualMatrizP::getPij_n(int i,int j){
	return this->normMatriz[i][j];
}
std::string MatrizATCG::VirtualMatrizP::toString(){
	std::stringstream salida;
	salida << numEstados<<'\n';
	for (std::vector<char>::iterator i = this->nombres.begin(); i != this->nombres.end(); ++i)
	{
		salida << *i;
	}
	for (int i = 0; i < numEstados; ++i)
	{
		salida<<'\n';
		for (int j = 0; j < numEstados; ++j)
		{
			if(j>0)
				salida<<';';
			salida<<this->normMatriz[i][j];
		}
	}
	return salida.str();
}
bool MatrizATCG::tryInsert(char c){
	if(this->nombres.size()<this->numEstados){	
		std::vector<char>::iterator it=std::find(this->nombres.begin(), this->nombres.end(), c);
		if( it!= this->nombres.end())
			return false;	
		else{
			this->nombres.insert(this->nombres.end(),c);
			return true;
		}
	}
	return false;
}
int MatrizATCG::indexOf(char c){
	std::vector<char>::iterator it=std::find(this->nombres.begin(), this->nombres.end(), c);
	int dist = std::distance(this->nombres.begin(),it);
	return dist; 
}