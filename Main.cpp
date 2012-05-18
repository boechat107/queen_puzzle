#include "Queen.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

	if( argc != 2){
		cout<< "Numero de parametros incorreto!!\n\n";
		exit(1);
	}
	
	int tam = strlen(argv[1]);
	int tamanho_tabuleiro = 0;
	for(register int i=0; i<tam; i++)
		tamanho_tabuleiro = tamanho_tabuleiro*10 + (argv[1][i] - 48);

	Queen queen(tamanho_tabuleiro);
	queen.Queen_recursivo(0);

	return 0;
}
