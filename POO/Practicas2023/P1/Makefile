#!/usr/bin/colormake
# Makefile para P0-P1
# ©2021 - Gerardo - La Gran Unificación
# ©2022-2023 Francisco Palomo

# La variable P debe valer P0 o P1 (prácticas 0 o 1 respectivamente).
# Por defecto se coge su valor del nombre del directorio de la práctica,
# que debe ser P0 o P1.

ifndef P
P = $(shell basename ${PWD})
endif

# Directorio donde están los programas de pruebas unitarias.

DIRTESTS = ../Tests-auto

# Compilador y sus opciones.

CXX = clang++
STD = c++17

CPPFLAGS := -I${DIRTESTS} -I. -D$P

# En lugar de «-g», empleamos «-gdwarf-4». La cuestión es que, a
# partir de Clang 14, se genera por omisión Dwarf 5 y las versiones de
# Valgrind inferiores a la 3.20 solo pueden trabajar con Dwarf 4.

CXXFLAGS := -gdwarf-4 -Wall -Wextra -pedantic -std=${STD}
LDFLAGS  =
LDLIBS   =

# Opciones para Valgrind.

VGFLAGS = --quiet --track-origins=yes --leak-check=full --show-leak-kinds=all --show-reachable=no

# Otros.

SRCS = cadena.cpp fecha.cpp
HDRS = ${SRCS:.cpp=.hpp}
OBJS = ${SRCS:.cpp=.o}

MAIN_SRCS = test-fechacadena-consola.cpp
MAIN_OBJS = ${MAIN_SRCS:.cpp=.o}
MAIN_EXE  = ${MAIN_SRCS:.cpp=}

TEST_SRCS = ${DIRTESTS}/test-caso0-fecha-auto.cpp \
            ${DIRTESTS}/test-caso0-cadena-auto.cpp ${DIRTESTS}/test-auto.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
TEST_EXE  = test-$P-auto

TEST_HDRS = ${DIRTESTS}/test-auto.hpp ${DIRTESTS}/fct.h

.PHONY: all tests test-consola test-auto check valgrind clean clean-all

# Construye los programas de prueba.

all: ${TEST_EXE} ${MAIN_EXE}

# Ejecuta los programas de prueba.

tests: test-consola test-auto

# Ejecuta las pruebas de consola.

test-consola: ${MAIN_EXE}
	./$<

# Ejecuta las pruebas unitarias automáticas.

test-auto: ${TEST_EXE}
	./$<

# Ejecuta las comprobaciones sobre el código fuente.

check:
	${MAKE} --no-print-directory --makefile=Make_check.mk $@

# Ejecuta los tests comprobando que no haya fugas de memoria.

valgrind: ${MAIN_EXE} ${TEST_EXE}
	valgrind ${VGFLAGS} ./${MAIN_EXE}
	valgrind ${VGFLAGS} ./${TEST_EXE} --logger=minimal

# Construye el programa de prueba de consola.

${MAIN_EXE}: ${MAIN_OBJS} ${OBJS}
	${CXX} -o $@ ${LDFLAGS} ${LDLIBS} $^

# Construye el programa de pruebas unitarias automáticas.

${TEST_EXE}: ${TEST_OBJS} ${OBJS}
	${CXX} -o $@ ${LDFLAGS} ${LDLIBS} $^

# Dependencias y compilación.

${OBJS} ${MAIN_OBJS} ${TEST_OBJS}: ${HDRS}

# Por si se cambia algo en los tests automáticos.

${TESTS_OBJS}: ${TESTS_HDRS}

# Limpieza en el directorio de la práctica.

clean:
	${RM} ${OBJS} ${MAIN_EXE} ${MAIN_OBJS} ${TEST_EXE} ${TEST_OBJS} *.d core *~ 
	${MAKE} --no-print-directory --file=Make_check.mk $@

clean-all: clean
	${RM} ${DIRTESTS}/*.d ${DIRTESTS}/*~
