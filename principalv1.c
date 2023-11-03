
/*******************
Autor:  Carolina Gomez Matiz
Materia: HPC
*****************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "modulo.h"


int main(int arg,  char* argv[])
{
	size_t **matrix;  	//Matriz 2D NxN
	size_t N=5;		//Valor Filas/Columnas
	srand(time(NULL));	//Semilla generador Aleatoreas

	matrix = InitMatriz(N);
	
	imprimir(matrix, N);

	for(size_t i = 0; i < N; ++i)
		free(matrix[i]);
	free(matrix);
	return 0;

}

