# AltoRendimiento
#Universidad Pontificia Javeriana

# Autores: 

           Jeimy Carolina Gómez Matiz

           Juan Sebastián Español
           
           Yesid Alexander Caicedo
           

# Objetivo: 


El objetivo de este proyecto es probar y realizar metricas y análisis de paralelización en sistemas de computo a través de muliplicación de matrices usando OpenMP,

Se realizará experimentación de la solución openMP para multiplicación de matrices de ColumnasXColumnas y multiplicación de matrices de FilasXFilas(punteros) en diferentes escenarios de pruebas con diferentes baterias de pruebas  para medir el rendimiento.

# Multiplicación de matrices de ColumnasXColumnas y FilasXFilas(punteros) 

## 1 Escenario: 2 Cores
           - El archivo Otime.c debe ser modificado en la siguiente linea:
                      #define MAX_THREADS 2
           - El archivo lanzador.pl debe ser modificado en la siguiente linea:
                      @cores = ("1","2");
## 2do Escenario:  4 Cores
           - El archivo Otime.c debe ser modificado en la siguiente linea:
                      #define MAX_THREADS 4
           - El archivo lanzador.pl debe ser modificado en la siguiente linea:
                      @cores = ("1","2","3","4");
## 3er Escenario: 6 Cores
           - El archivo Otime.c debe ser modificado en la siguiente linea:
                      #define MAX_THREADS 6
           - El archivo lanzador.pl debe ser modificado en la siguiente linea:
                      @cores = ("1","2","3","4,"5","6");
## 4to escenario: 8 Cores
           - El archivo Otime.c debe ser modificado en la siguiente linea:
                      #define MAX_THREADS 8
           - El archivo lanzador.pl debe ser modificado en la siguiente linea:
                      @cores = ("1","2","3","4","5","6","7","8");

# Graficación de Resultados y toma de muestras de batería de pruebas

Para realizar la tabulación y gráficas de los resultados y análizar el speedUp, se utilizó colab, que por medio de una libería de Python que se encuentra en la ruta del Repositorio (GraficasResultados/Colab/Tabular_solucion_HPC.ipynb)

El proyecto en líene apara ver las gráficas de speedUp se encuentra en:

[httpscolab.research.google.comdrive1WbkL_XiMZ0XBVoCxJSIv_qVWyxMpKQz0usp=sharing](https://colab.research.google.com/drive/1WbkL_XiMZ0XBVoCxJSIv_qVWyxMpKQz0?usp=sharing)https://colab.research.google.com/drive/1WbkL_XiMZ0XBVoCxJSIv_qVWyxMpKQz0?usp=sharing

