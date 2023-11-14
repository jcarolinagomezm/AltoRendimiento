/************************************************************************
* Autores: Jeimy Carolina Gómez Matiz
*		   Juan Sebastián Español
*		   Yesid Alexander Caicedo
* Fecha: Noviembre 2023
* Computación de Alto Rendimiento
* Maestría en Ingeniería de Sistemas, IoT e Inteligencia Artificial
* Tema: Programa de Multiplicación de Matrices usando hilos OpenMP
* -Algorimo Clásico filasXFilas (Punteros)
*************************************************************************/
# include <stdlib.h>
# include <stdio.h>
# include <omp.h>
# include "sample.h"

# ifndef MIN
# define MIN(x,y) ((x)<(y)?(x):(y))
# endif

# define DATA_SZ (1024*1024*64*3)

static double  MEM_CHUNK[DATA_SZ];

// Función para inicializar matrices y asegurar la alineación de la memoria
void Matrix_Init_row(int SZ, double **a, double **b, double **c, size_t alignment) {
    // Asegurar la alineación de memoria para las matrices
    *a = aligned_alloc(alignment, SZ * SZ * sizeof(double));
    *b = aligned_alloc(alignment, SZ * SZ * sizeof(double));
    *c = aligned_alloc(alignment, SZ * SZ * sizeof(double));

    if (*a == NULL || *b == NULL || *c == NULL) {
        // Manejar el error de asignación de memoria
        exit(EXIT_FAILURE);
    }

    int j, k;
    // Inicializar matrices a, b, y c con valores específicos
    for (j = 0; j < SZ; j++) {
        for (k = 0; k < SZ; k++) {
            (*a)[j + k * SZ] = 2.0 * (j + k);
            (*b)[j + k * SZ] = 3.2 * (j - k);
            (*c)[j + k * SZ] = 1.0;
        }
    }
}

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
    if (N > 1024 * 10) {
        printf("Invalid MatrixSize\n");
        return -1;
    }

    // Inicializar el sistema de medición de rendimiento
    Sample_Init(argc, argv);

    // Directiva OpenMP para paralelizar el bucle
    #pragma omp parallel
    {
        int     NTHR, THR, SZ;
        int     i, j, k;
        double  *a, *b, *c;
        size_t alignment = 64;

        SZ    = N; 
        THR  = Sample_PAR_install();
        NTHR = omp_get_num_threads();
      
        // Establecer punteros a las secciones de MEM_CHUNK para a, b y c
        a = MEM_CHUNK;
        b = a + SZ * SZ;
        c = b + SZ * SZ;

        // Inicializar matrices solo en el hilo maestro
        #pragma omp master
        Matrix_Init_row(SZ, &a, &b, &c, alignment);

        // Iniciar la medición de rendimiento
        Sample_Start(THR);

        // Bucle de multiplicación de matrices
        #pragma omp for
        for (i = 0; i < SZ; i++) {
            for (j = 0; j < SZ; j++) {
                double *pA, *pB, S;
                S = 0.0; 
                pA = a + (i * SZ); pB = b + j;
                for (k = SZ; k > 0; k--, pA++, pB += SZ) 
                    S += (*pA * *pB);
                c[i * SZ + j] = S;
            }
        } 

        // Detener la medición de rendimiento
        Sample_Stop(THR);

        // Liberar memoria asignada solo en el hilo maestro
        #pragma omp master
        {
            free(a);
            free(b);
            free(c);
        }
    }
    
    // Finalizar el sistema de medición de rendimiento
    Sample_End();
}
