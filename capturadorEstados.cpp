#include "VirtualClasses.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

void contarEstados(std::string filePath,MatrizATCG* m){
	std::ifstream f (filePath);
	char c;
	if (f.is_open()) { 
		int i=-1;
		int k=24984570;//limite de lectura
		while(f.get(c)){
			if(c<33)continue;
			if(k--==0)break;
			m->tryInsert(c);
			int ind=m->indexOf(c);
			if(ind>=0){
				if(i==-1){
					//estado inicial
					i=ind;
				}else{
					m->Pijpp(i,ind);
					i=ind;
				}
			}
		}
		m->normalizarMatriz();
		std::cout<<m->toString()<<std::endl;
	}
}
