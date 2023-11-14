#!/usr/bin/perl

=for comment
/************************************************************************
*   Autores: Jeimy Carolina Gómez Matiz
*            Juan Sebastián Español
*            Yesid Alexander Caicedo
*   Fecha: Noviembre 2023
*   Computación de Alto Rendimiento
*   Maestría en Ingeniería de Sistemas, IoT e Inteligencia Artificial
*   Pontificia Universidad Javeriana
*   Objetivo: Herramienta para automatizar proceso de ejecución
*             por lotes.
****************************************************************/
=cut

# Verificar si se proporciona un argumento en la línea de comandos
if (@ARGV[0]) {
    $numRep = "$ARGV[0]";
} else {
    usage(); # Llamar a la función usage si no se proporciona un argumento
}

# Imprimir el número de repeticiones especificado
print "\n Repeticiones de la experimentación: $numRep \n\n";

# Obtener el directorio actual y extraer la ruta base
$path0 = `pwd`;
chomp($path0);
$T = index($path0, "T") - 1;
$Path = substr($path0, 0, $T);
print "$Path \n";

# Definir arrays con nombres de ejecutables, número de cores y tamaños de vectores
@Ejecutables = ("MM1c");
@cores = ("1", "2", "4", "8", "10", "14", "16", "20");
@VectorSize = ("100", "200", "400", "600", "800");

# Bucle anidado para ejecutar experimentos con diferentes parámetros
foreach $exe (@Ejecutables) {
    foreach $ves (@VectorSize) {
        foreach $c (@cores) {
            $file = "$Path/" . "Soluciones/" . "$exe" . "-Size" . "$ves" . "-core" . "$c";
            # Imprimir el nombre del fichero
            #print "$file \n";

            # Bucle para realizar experimentos con el mismo conjunto de parámetros
            for ($i = 0; $i < $numRep; $i++) {
                system("$Path/BIN/$exe $ves $c 0   >> $file");
                print "$Path/BIN/$exe $ves $c 0  \n";
            }
            close($file);
        }
    }
}

# Salir del script con código de salida 1
exit(1);

# Función para calcular el coeficiente de variación
sub MedCOV {
    my ($array1, $array2) = @_;
    @p_vector = @{$array1};
    @s_vector = @{$array2};
    $suma = 0; $std = 0;
    $media = 0; $coef = 0;
    $times = $s_vector[0];

    for ($j = 0; $j < $times; $j++) {
        $suma += $p_vector[$j];
        $suma2 += $p_vector[$j]**2;
    }

    if ($j > 0) {
        $media = $suma / $j;
    }

    for ($j = 0; $j < $times; $j++) {
        $std += ($p_vector[$j] - $media)**2;
    }

    $cov = sqrt($std / ($times - 1));

    if ($media > 0) {
        $coef = 100 * $cov / $media;
    }

    splice(@p_vector, 0, $times);
}

# Función para imprimir mensaje de uso del script
sub usage {
    print "\n tst.pl: Uso incorrecto\n\n";
    print "\t revisar entradas o directorio de almacenaje \n\n\n";
    exit(1);
}
