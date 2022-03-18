CXX = g++
CXXFLAGS = -g -Wall -std=c++11 -pedantic
CPPFLAGS = -DP1 -I../Tests-auto -I.
VPATH = ../Tests-auto:.
DIR = ../Tests-auto/

NOMBREALUMNO = Arcos_Herrera_Raul

all: test-P1-auto test-fechacadena-consola

test-fechacadena-consola: test-fechacadena-consola.o fecha.o cadena.o
	${CXX} -o $@ ${LDFLAGS} $^

test-P1-auto: test-caso0-fecha-auto.o test-caso0-cadena-auto.o test-auto.o cadena.o fecha.o
	${CXX} -o $@ ${LDFLAGS} $^

test-caso0-fecha-auto.o test-caso0-cadena-auto.o test-auto.o:  test-auto.hpp fecha.hpp cadena.hpp

fecha.o: fecha.hpp

cadena.o: cadena.hpp

test-fechacadena-consola.o: fecha.hpp cadena.hpp

clean: 
	@$(RM) test-fechacadena-consola test-P0-auto *.o