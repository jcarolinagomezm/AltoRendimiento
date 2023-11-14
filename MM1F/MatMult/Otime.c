/************************************************************************
* Autores: Jeimy Carolina Gómez Matiz
*          Juan Sebastián Español
*          Yesid Alexander Caicedo
* Fecha: Noviembre 2023
* Computación de Alto Rendimiento
* Maestría en Ingenieria de Sistemas, IoT e Inteligencia Artificial
* Tema: Programa de Multiplicación de Matrices usando hilos OpenMP
* -Clase Otime para documentar y guardar la medición de rendimiento y mostrar los resultados que servirá de insumo para calcular el speedUp
*************************************************************************/

// Inclusión de bibliotecas estándar
#include <stdlib.h>     // Biblioteca estándar para funciones de asignación de memoria dinámica y otras utilidades
#include <omp.h>        // Biblioteca para OpenMP, que permite la paralelización de código
#include <string.h>     // Biblioteca para funciones de manipulación de cadenas de caracteres
#include <errno.h>      // Biblioteca para manejar errores a través de la variable "errno"
#include <sys/time.h>   // Biblioteca para funciones relacionadas con el tiempo
#include <stdio.h>      // Biblioteca estándar para funciones de entrada/salida estándar

#define MAX_THREADS 20   // Número máximo de hilos permitidos

struct timeval start[MAX_THREADS];  // Estructura para almacenar el tiempo de inicio de cada hilo
struct timeval stop[MAX_THREADS];   // Estructura para almacenar el tiempo de finalización de cada hilo

static int N_THREADS;   // Número de hilos a utilizar

// Función para marcar el tiempo de inicio de una sección de código
void Sample_Start(int THR) {
    #pragma omp barrier  // Sincronizar los hilos antes de marcar el tiempo de inicio
    gettimeofday(start + THR, (void *)0);  // Obtener el tiempo de inicio del hilo actual
}

// Función para marcar el tiempo de finalización de una sección de código
void Sample_Stop(int THR) {
    gettimeofday(&(stop[THR]), (void *)0);  // Obtener el tiempo de finalización del hilo actual
}

// Función para inicializar el sistema de medición de rendimiento
void Sample_Init(int argc, char *argv[]) {
    
    if (argc < 3) {
        printf("Sample parameters: NumberThreads \n");
        exit(1);
    }

    N_THREADS = (int) atof(argv[1]);  // Obtener el número de hilos desde los argumentos de línea de comandos

    if (!N_THREADS || N_THREADS > MAX_THREADS) {
        printf("Number of Threads is not valid\n"); 
        exit(1);
    }

    omp_set_num_threads(N_THREADS);  // Establecer el número de hilos para OpenMP
}

// Función para obtener el identificador del hilo actual
int Sample_PAR_install() { 
    int THR;
    THR = omp_get_thread_num();  // Obtener el identificador del hilo actual
    return THR;
}

// Función para finalizar el sistema de medición de rendimiento y mostrar los resultados
void Sample_End() {
    int THR;

    for (THR = 0; THR < N_THREADS; THR++) {
        printf(" %1.0f:  ", (double) THR);
        stop[THR].tv_usec -= start[THR].tv_usec;
        if (stop[THR].tv_usec < 0) {
            stop[THR].tv_usec += 1000000;
            stop[THR].tv_sec--;
        }
        stop[THR].tv_sec -= start[THR].tv_sec;

        printf("%9.0f\n", (double) (stop[THR].tv_sec * 1000000 + stop[THR].tv_usec));
    }
}
