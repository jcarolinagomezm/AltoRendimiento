
/*******************
Autor:  Carolina Gomez Matiz
Materia: HPC
*****************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int arg,  char* argv[])
{
	size_t **matrix;  	//Matriz 2D NxN
	size_t N=5;		//Valor Filas/Columnas
	srand(time(NULL));	//Semilla generador Aleatoreas

	matrix = (size_t **)calloc(N, sizeof(size_t *));
	
	for(size_t i = 0; i < N; ++i)
		matrix[i] = (size_t *)malloc(N * sizeof(size_t));
		
	// Inicialización de Matriz con valores aleatoreas entre 1 y 100	
	for(size_t i = 0; i < N; ++i){
		for (size_t j = 0; j < N; ++j){
			matrix[i][j] = (size_t) rand()%100 +1;

		}		
	}
	
	// Impresión de matriz	
	for(size_t i = 0; i < N; ++i){
		for (size_t j = 0; j < N; ++j){
			printf("%zu ",matrix[i][j]);

		}		
		printf("\n");
	}	

	for(size_t i = 0; i < N; ++i)
		free(matrix[i]);
	free(matrix);
	return 0;

}

