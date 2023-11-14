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

# Ejemplos de Resultados (Según bateria de pruebas y experimentos realizados)
Dentro del proyecto en Cada una de las carpetas principales se guardan los resultados después de correr la bateria de pruebas.
###AltoRendimiento/MM1C/Soluciones/
Dentro de esta carpeta se encuentra cada una de las carpetas o subcarpetas por cada una de las instancias de computo de las pruebas del programa de **multiplicación de matrices por Columnas** para cada una de las instancias:
 Así:
 
             /Soluciones2CPU/
             /Soluciones4CPU/
             /Soluciones6CPU/
             /Soluciones8CPU/

   Aquí apareceran los resultados para cada uno de los cores y tamaños de las matrices. Por ejemplo:
   
            AltoRendimiento/MM1C/Soluciones//Soluciones4CPU/MM1c-Size100-core1

###AltoRendimiento/MM1F/Soluciones/
 Dentro de esta carpeta se encuentra cada una de las carpetas o subcarpetas por cada una de las instancias de computo de las pruebas del programa de **multiplicación de matrices por filas (punteros)** para cada una de las instancias:
 Así:
      
             /Soluciones4CPU/
             /Soluciones6CPU/
             /Soluciones8CPU/
             
   Aquí apareceran los resultados de la multiplicación de matrices POR FILAS para cada uno de los cores y tamaños de las matrices. Por ejemplo:
   
            AltoRendimiento/MM1F/Soluciones//Soluciones4CPU/MM1c-Size100-core1
            

Ahí estarán los datos de resultados para generar los SpeedUp, estos logs con los tiempos servirán de insumo para la graficación de los resultados.


# Graficación de Resultados y toma de muestras de batería de pruebas

Para realizar la tabulación y gráficas de los resultados y análizar el speedUp, se utilizó colab, que por medio de una clase de Python que se encuentra en la ruta del Repositorio (GraficasResultados/Colab/Tabular_solucion_HPC.ipynb), se encarga de realizar la grafica del speedup acorde a los logs con los resultados productos de cada una de las baterias de experimentación. 

El proyecto en línea para ver las gráficas de speedUp se encuentra en:

[httpscolab.research.google.comdrive1WbkL_XiMZ0XBVoCxJSIv_qVWyxMpKQz0usp=sharing](https://colab.research.google.com/drive/1WbkL_XiMZ0XBVoCxJSIv_qVWyxMpKQz0?usp=sharing)https://colab.research.google.com/drive/1WbkL_XiMZ0XBVoCxJSIv_qVWyxMpKQz0?usp=sharing

