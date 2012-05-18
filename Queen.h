#ifndef __QUEENS_H
#define __QUEENS_H

#include <iostream>
#include <queue>

using namespace std;

class Queen{

	int tabuleiro_size;
	int* rainhas;
	int quantidade_solucoes;
	queue<int> posicoes;

	bool Valida_posicoes(int coluna);

	void Imprime_solucao() const;

	public:
		Queen(int tamanho_tabuleiro);

		void Queen_recursivo(int coluna);

		~Queen(){ delete[] rainhas;}
};


#endif
