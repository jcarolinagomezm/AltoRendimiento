
/*******************
Autor:  Carolina Gomez Matiz
Materia: HPC
*****************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "modulo.h"

size_t **InitMatriz(size_t N){
	size_t ** matrix;
	matrix = (size_t **)calloc(N, sizeof(size_t *));
	
	for(size_t i = 0; i < N; ++i)
		matrix[i] = (size_t *)malloc(N * sizeof(size_t));
		
	// Inicialización de Matriz con valores aleatoreas entre 1 y 100	
	for(size_t i = 0; i < N; ++i){
		for (size_t j = 0; j < N; ++j){
			matrix[i][j] = (size_t) rand()%100 +1;

		}		
	}
	return matrix;
}

void imprimir( size_t **matrix, size_t N){
	// Impresión de matriz	
	for(size_t i = 0; i < N; ++i){
		for (size_t j = 0; j < N; ++j){
			printf("%zu ",matrix[i][j]);

		}		
		printf("\n");
	}	

}



