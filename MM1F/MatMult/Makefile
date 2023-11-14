# Makefile: Archivo para compilar el programa MM1f - Multiplicación de Matrices filas x filas
# Autores: Jeimy Carolina Gómez Matiz
#          Juan Sebastián Español
#          Yesid Alexander Caicedo
# Fecha: Noviembre 2023
# Computación de Alto Rendimiento
# Maestría en Ingeniería de Sistemas, IoT e Inteligencia Artificial
# Pontificia Universidad Javeriana
# Objetivo: Compilar el programa MM1f con opciones de OpenMP y optimización


# Definición del compilador a utilizar (gcc)
GCC = gcc

# Opciones de compilación para OpenMP y optimización de nivel 3
oT = -fopenmp -O3 

# Opciones de enlace (en este caso, solo se utiliza la biblioteca matemática -lm)
CFLAGS = -lm 

# Nombre del archivo fuente de código (Otime.c)
oL= Otime.c

# Directorio de salida para los archivos binarios
BINDIR = ../BIN/

# Lista de programas a compilar (en este caso, solo MM1f)
PROGS = $(BINDIR)MM1f

# Regla para construir todos los programas en este caso aplica solo para MM1f (Multipliccaión de matrices FilasXFilas)
all: MM1f

# Regla para limpiar los archivos binarios generados
clean:
	$(RM) $(PROGS)

# Regla para compilar el programa MM1f (Multipliccaión de matrices FilasXFilas)
MM1f:
	$(GCC) $(oT) $(oL) $@.c -g -o $(BINDIR)$@ $(CFLAGS)
