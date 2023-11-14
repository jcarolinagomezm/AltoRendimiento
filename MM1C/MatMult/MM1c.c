/************************************************************************
* Autores: Jeimy Carolina Gómez Matiz
*          Juan Sebastián Español
*          Yesig Alexander Caicedo
* Fecha: Noviembre 2023
* Computación de Alto Rendimiento
* Maestría en Ingenieria de Sistemas, IoT e Inteligencia Artificial
* Tema: Programa de Multiplicación de Matrices usando hilos OpenMP
* -Algorimo Clásico filasXcolumnas
*************************************************************************/

// Inclusión de bibliotecas estándar
#include <stdlib.h> // Para funciones de asignación de memoria dinámica (como aligned_alloc)
#include <stdio.h>  // Para funciones de entrada/salida estándar
#include <omp.h>    // Para OpenMP (paralelización)
#include "sample.h" // Para funciones relacionadas con la medición de rendimiento

// Definición de la macro MIN para obtener el mínimo de dos valores
# ifndef MIN
# define MIN(x,y) ((x)<(y)?(x):(y))
# endif

// Tamaño del array estático MEM_CHUNK
# define DATA_SZ (1024*1024*64*3)

// Declaración de un array estático de doble precisión para almacenar datos
static double  MEM_CHUNK[DATA_SZ];

// Función para inicializar matrices con valores específicos
void Matrix_Init_col(int SZ, double *a, double *b, double *c){
    int j, k;
    // Bucle anidado para inicializar matrices a, b y c con valores específicos
    for (j = 0; j < SZ; j++) {
		for (k = 0; k < SZ; k++) {
			a[j + k * SZ] = 2.0 * (j + k);   // Inicializar matriz a
			b[j + k * SZ] = 3.2 * (j - k);   // Inicializar matriz b
			c[j + k * SZ] = 1.0;             // Inicializar matriz c
		}	
    }
}

// Función principal
int main(int argc, char **argv) {
    int  N;

    // Verificar si se proporciona el tamaño de la matriz como argumento de línea de comandos
    if (argc < 2) {
        printf("MM1c MatrixSize [Sample arguments ...]\n"); 
        return -1;
    }

    // Obtener el tamaño de la matriz desde los argumentos de línea de comandos
    N  = (int) atof(argv[1]); argc--; argv++;

    // Verificar si el tamaño de la matriz es válido
    if (N > 1024*10) {
        printf("Invalid MatrixSize\n");
        return -1;
    }

    // Inicializar el sistema de medición de rendimiento con argumentos de línea de comandos
    Sample_Init(argc, argv);

    // Directiva OpenMP para paralelizar el bucle principal
    #pragma omp parallel
	{
		int     NTHR, THR, SZ;
		int     i, j, k;
		double  *a, *b, *c;

		// Obtener el tamaño de la matriz, el número de hilos y el identificador del hilo
		SZ    = N; 
		THR  = Sample_PAR_install();
		NTHR = omp_get_num_threads();
	  
		// Establecer punteros a las secciones de MEM_CHUNK para a, b y c
		a = MEM_CHUNK;
		b = a + SZ*SZ;
		c = b + SZ*SZ;

		// Inicializar matrices solo en el hilo maestro
		#pragma omp master
		Matrix_Init_col(SZ, a, b, c); 

		// Iniciar la medición de rendimiento
		Sample_Start(THR);

		 // Directiva OpenMP para paralelizar el bucle de multiplicación de matrices
		 #pragma omp for
			for (i = 0; i < SZ; i++)
				for (j = 0; j < SZ; j++) {
					double *pA, *pB, S;
					S = 0.0; 
					pA = a + (i * SZ); pB = b + j;
					// Bucle para realizar la multiplicación de matrices
					for (k = SZ; k > 0; k--, pA++, pB += SZ) 
						S += (*pA * *pB);
					c[i * SZ + j] = S; // Almacenar el resultado en la matriz c
				} 

		// Detener la medición de rendimiento
		Sample_Stop(THR);
	}
	  
	// Finalizar el sistema de medición de rendimiento
	Sample_End();
		
}
