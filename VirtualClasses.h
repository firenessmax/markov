#ifndef HELLOWORLD
#define HELLOWORLD
#include <string>
#include <vector>
#include <iostream>

class VirtualMatrizP
{
public:
	explicit VirtualMatrizP(int _numEstados):nombres(0){
		numEstados=_numEstados;
		matriz = new unsigned long long int*[numEstados];
		for (int i = 0; i < numEstados; ++i)
		{
			matriz[i]=new unsigned long long int[numEstados];
			for (int j = 0; j < numEstados; ++j)
			{
				matriz[i][j]=0;
			}
		}
		normMatriz = new double*[numEstados];
		for (int i = 0; i < numEstados; ++i)
		{
			normMatriz[i]=new double[numEstados];
			for (int j = 0; j < numEstados; ++j)
			{
				normMatriz[i][j]=0.0;
			}
		}
	}
	virtual void normalizarMatriz();
	virtual void Pijpp(int i,int j);
	virtual unsigned long long int getPij(int i,int j);
	virtual double getPij_n(int i,int j);
	virtual std::string toString();
	int numEstados;
	unsigned long long int** matriz;
	double** normMatriz;
	std::vector<char> nombres;
};

class MatrizATCG: public VirtualMatrizP
{
public:
	explicit MatrizATCG(int n):VirtualMatrizP(n){}
	bool tryInsert(char c);
	int indexOf(char c);
};
void contarEstados(std::string filePath,MatrizATCG* m);
#endif 