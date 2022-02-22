# Codificaci�n ISO Latin-1 y terminal EPS.

set encoding iso_8859_1
set terminal postscript eps

# T�tulo de cada eje.
 
set xlabel "n (n�mero de celdas)"
set ylabel "t(n) (tiempo en segundos)"

# Estilo de presentaci�n (puntos interpolados linealmente).

#set data style linespoints

# Creaci�n de los ficheros EPS.

set output "graphic.eps"
plot 'data.txt' using 1:2 title "Sin pre-ordenaci�n" with lines, \
     '' using 1:3 title "Fusi�n" with lines, \
	 '' using 1:4 title "R�pida" with lines, \
	 '' using 1:5 title "Mont�culo" with lines
