#include "Queen.h"

//=======================================================================================

Queen::Queen(int tamanho_tabuleiro){
	
	tabuleiro_size = tamanho_tabuleiro;
	rainhas = new int[tamanho_tabuleiro];
	quantidade_solucoes = 0;

	for(register int i=0; i<tamanho_tabuleiro; i++)
		posicoes.push(i);
}

//=======================================================================================
// Esta funcao verifica a posicao das rainhas posicionadas nas colunas anteriores a coluna
// passada como parametro.

bool Queen::Valida_posicoes(int coluna){

	if( coluna < 2 )
		return true;

	// Da forma como esta implementada a solucao (utilizando uma fila para armazenar 
	// as posicoes ainda disponiveis), nao ha necessidade de verificar se existem 
	// rainhas na mesma linha ou na mesma coluna, verifica-se apenas as posicoes 
	// diagonais.

	for(register int i=rainhas[coluna-1]+1, j=coluna-2; (i<tabuleiro_size)&&(j>=0); i++,j--){

		if( rainhas[j] == i )
			return false;
	}

	for(register int i=rainhas[coluna-1]-1, j=coluna-2; (i>=0)&&(j>=0); i--,j--){

		if( rainhas[j] == i )
			return false;
	}

	return true;
}
		
//=======================================================================================

void Queen::Imprime_solucao() const{
	
	cout<< "Solucao "<< quantidade_solucoes<< ":\n";

	for(register int i=0; i<tabuleiro_size; i++)
		cout<< "\tColuna: "<< i<< "; Linha: "<< rainhas[i]<< endl;

	cout<< "\n\n";
}

//=======================================================================================

void Queen::Queen_recursivo(int coluna){

	if( coluna < tabuleiro_size ){

		if( Valida_posicoes(coluna) == true ){
			int limite = posicoes.size();

			for(register int i=0; i<limite; i++){
				int pos = posicoes.front();
				posicoes.pop();

				rainhas[coluna] = pos;
				Queen_recursivo(coluna+1);

				posicoes.push(pos);
			}
		}
	}
	else{
		if( Valida_posicoes(coluna) == true ){
			quantidade_solucoes++;
			Imprime_solucao();
		}
	}
}

//=======================================================================================


