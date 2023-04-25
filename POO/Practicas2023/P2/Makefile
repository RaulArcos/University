# $Id: Makefile 399 2017-05-17 17:32:04Z gerardo $
# Makefile para los casos de uso 1, 2, 3 y 4 de la LIBRERÍA
# ©2010-20 los profesores de POO, para P2, P3 y P4
# ©2021 Gerardo - La Gran Unificación
# ©2023 Francisco Palomo Lozano

# AP1_AP2_N es el nombre del directorio donde el alumno ha desarrollado las
# prácticas de POO. Dentro, aparecerán los de cada práctica, es decir, P0, P1,
# P2, P3 y P4, así como los directorios y ficheros suministrados por los
# profesores de la asignatura: Tests-auto, dsl-comprobaciones y luhn.cpp. Véanse
# las instrucciones de entrega en el enunciado de la práctica.

# La variable P recoge el nombre de directorio de la práctica actual. AP1_AP2_N
# debe ser de la forma: Apellido1_Apellido2_Nombre_de_pila, sin tildes ni
# diéresis, y cambiando «ñ» por «nn».

NA        := $(shell dirname ${PWD})
AP1_AP2_N := $(notdir ${NA})
P         := $(shell basename ${PWD})
D         := ${AP1_AP2_N}/$P
D1        := ${AP1_AP2_N}/P1

# Directorio de la práctica 1, con todo lo relativo a las clases Cadena y Fecha.

DIRFC = ../P1

# Directorio con los ficheros del programa de pruebas unitarias automáticas.

DIRTESTS = ../Tests-auto

# Directorio donde está el fichero luhn.cpp con la función luhn.

DIRLUHN = ..

# Compilador de C++ y versión de la norma del lenguaje.
#
# c++	     Compilador de C++ predeterminado, si es que hay uno instalado
# g++ 	     Compilador de C++ de la GNU CC (GNU Compiler Collection)
# icpc       Compilador de C++ de Intel
# clang++    Compilador de C++ de Clang/LLVM

CXX = clang++
STD = c++17
override CXX += -std=${STD}

# Opciones para el preprocesador.
#
# -Idir   Directorio donde buscar cabeceras adicionales (#include "...")
# -Dmacro Define una macro del preprocesador (como con #define)

CPPFLAGS := -D$P -I${DIRFC} -I${DIRTESTS} -I.

# Opciones para el compilador.
#
# En lugar de «-g», empleamos «-gdwarf-4». La cuestión es que, a partir de Clang
# 14, se genera por omisión Dwarf 5 y las versiones de Valgrind inferiores a la
# 3.20 solo pueden trabajar con Dwarf 4.

CXXFLAGS := -gdwarf-4 -Wall -Wextra -pedantic

# Opciones para el enlazador.

LDFLAGS =
LDLIBS  = -lcrypt

# Opciones para Valgrind.

VGFLAGS = --quiet --track-origins=yes --leak-check=full --show-leak-kinds=all --show-reachable=no

#

LOCALLIBS = ${DIRFC}/cadena.o ${DIRFC}/fecha.o ${DIRLUHN}/luhn.o
LIBS      = ${LOCALLIBS} ${LDLIBS}

# Ficheros de código fuente que tiene que escribir el alumno, y sus objetos binarios.

SRCS  = usuario.cpp tarjeta.cpp articulo.cpp
ifneq ($P, P2)
SRCS += pedido-articulo.cpp pedido.cpp usuario-pedido.cpp
endif
HDRS  = ${SRCS:.cpp=.hpp}
OBJS  = ${SRCS:.cpp=.o}

# Ficheros correspondientes a las pruebas de consola.

MAIN_SRCS = test-consola.cpp
MAIN_OBJS = ${MAIN_SRCS:.cpp=.o}
MAIN_EXE  = test-$P-consola

# Ficheros correspondientes a las pruebas unitarias.

TEST_SRCS = ${DIRTESTS}/test-caso0-cadena-auto.cpp \
	    ${DIRTESTS}/test-caso0-fecha-auto.cpp  \
	    ${DIRTESTS}/test-caso1-2-auto.cpp ${DIRTESTS}/test-auto.cpp
ifeq ($P, P3)
TEST_SRCS += ${DIRTESTS}/test-caso3-auto.cpp
endif
ifeq ($P, P4)
TEST_SRCS += ${DIRTESTS}/test-caso3-auto.cpp ${DIRTESTS}/test-caso4-auto.cpp
endif
TEST_HDRS = ${DIRTESTS}/test-auto.hpp ${DIRTESTS}/fct.h
TEST_OBJS = ${TEST_SRCS:.cpp=.o}
TEST_EXE  = test-$P-auto

# Nombre del archivo comprimido que se entregará a los profesores de la asignatura.

NOMBRETAR = ../../${AP1_AP2_N}.tar.gz

# Objetivos falsos.

.PHONY: all tests test-consola test-auto check valgrind clean clean-all distclean dist help variables

# Objetivos silenciosos (no muestran sus acciones).

.SILENT: help variables

# En los programas de GNU se emplean los siguientes nombres para los objetivos:
#
# https://www.gnu.org/software/make/manual/make.html#Standard-Targets

# Construye los programas de prueba.

all: ${MAIN_EXE} ${TEST_EXE}
	@echo "Pruebe «make help» para más objetivos interesantes"

# Ejecuta los programas de prueba.

tests: test-consola test-auto

# Construye y ejecuta las pruebas de consola.

test-consola: ${MAIN_EXE}
	./$<

# Construye y ejecuta las pruebas unitarias automáticas.

test-auto: ${TEST_EXE}
	./$<

# Ejecuta las comprobaciones sobre el código fuente.

check:
	${MAKE} --no-print-directory --makefile=Make_check.mk $@

# Ejecuta las pruebas comprobando que no haya fugas de memoria.
#
# La opción --logger no corresponde a Valgrind, sino al marco de pruebas (se define en "fct.h").

valgrind: ${MAIN_EXE} ${TEST_EXE}
	valgrind ${VGFLAGS} ./${MAIN_EXE}
	valgrind ${VGFLAGS} ./${TEST_EXE} --logger=minimal

# Construye el programa de pruebas de consola.

${MAIN_EXE}: ${MAIN_OBJS} ${OBJS} ${LOCALLIBS}
	${CXX} -o $@ ${LDFLAGS} $^ ${LDLIBS}

# Construye el programa de pruebas unitarias automáticas.

${TEST_EXE}: ${TEST_OBJS} ${OBJS} ${LOCALLIBS}
	${CXX} -o $@ ${LDFLAGS} $^ ${LDLIBS}

# Generación automática de las dependencias de los ficheros de código fuente C++.
#
# Adaptado de:
#
# https://www.gnu.org/software/make/manual/html_node/Automatic-Prerequisites.html
#
# Empleamos las siguientes opciones del preprocesador:
#
# -MM           Genera la regla (como -M), pero sin las cabeceras del sistema
# -MF fichero	Fichero de salida con las dependencias
#
# La orden «sed» final modifica el fichero de dependencias para añadirlo como
# objetivo a la regla.

%.d: %.cpp
	@${CXX} ${CPPFLAGS} -MM -MF $@ $<
	@sed --regexp-extended --in-place 's|($*)\.o[ :]*|\1.o $@: |g' $@

# Incluye las dependencias dinámicamente (e ignora posibles errores, de ahí el «-»).

-include ${SRCS:.cpp=.d} ${MAIN_SRCS:.cpp=.d} ${TEST_SRCS:.cpp=.d}

# Cadena y Fecha aún son susceptibles de cambios, que delegamos en su makefile.

${DIRFC}/cadena.o:
	${MAKE} --no-print-directory --directory=${DIRFC} --makefile=${DIRFC}/Makefile $@

${DIRFC}/fecha.o:
	${MAKE} --no-print-directory --directory=${DIRFC} --makefile=${DIRFC}/Makefile $@

# Por si se cambia algo en las pruebas automáticas.

${TESTS_OBJS}: ${TESTS_SRCS} ${TESTS_HDRS}

# Limpia el directorio de la práctica.

clean:
	${RM} ${OBJS} ${MAIN_EXE} ${MAIN_OBJS} ${TEST_EXE} ${TEST_OBJS} *.d core *~ 
	${MAKE} --no-print-directory --makefile=Make_check.mk $@

# Limpia el directorio de la práctica y el de las pruebas unitarias, y elimina el archivo.

distclean: clean
#	${MAKE} --directory=${DIRFC} --file=${DIRFC}/Makefile $@
	${RM} ${LOCALLIBS} ${DIRTESTS}/*.d ${DIRTESTS}/*~
	${RM} ${NOMBRETAR}

# Archiva para su entrega (incondicionalmente, lo que es mejorable).

dist: distclean ${NOMBRETAR}

${NOMBRETAR}:
	@echo "Creando archivo en «${NOMBRETAR}» con el siguiente contenido:"
	@tar --create --verbose --gzip --file=${NOMBRETAR} --directory=../.. \
	     ${D1}/cadena.cpp ${D1}/cadena.hpp ${D1}/fecha.cpp ${D1}/fecha.hpp \
	     ${SRCS:%.cpp=$D/%.cpp} ${HDRS:%.hpp=$D/%.hpp}

# Muestra la ayuda.

help:
	echo "make [all]          -- Construye los programas de prueba"
	echo "make tests          -- Construye y ejecuta los programas de prueba"
	echo "make test-consola   -- Construye y ejecuta el programa de pruebas de consola"
	echo "make test-auto      -- Construye y ejecuta el programa de pruebas unitarias automáticas"
	echo "make check          -- Construye y ejecuta el programa de comprobaciones estáticas de código fuente"
	echo "make valgrind       -- Construye y ejecuta con valgrind los programas de prueba"
	echo "make clean          -- Limpia el directorio de la práctica"
	echo "make distclean      -- Limpia el directorio de la práctica más otros ficheros"
	echo "make dist           -- Archiva en «${NOMBRETAR}» lo que se debe entregar, tras limpiar"
	echo "make help           -- Muestra esta ayuda"
	echo "make variables      -- Muestra las variables más importantes definidas en este «makefile»"

# Muestra las principales variables y sus valores.

PRINT = printf '%-10s = %-44s\t \# %s\n'

variables:
	echo "# Principales variables definidas en el «makefile»"
	echo
	echo "# Directorios:"
	echo
	${PRINT} "AP1_AP2_N" "${AP1_AP2_N}" "Directorio con las prácticas de POO"
	${PRINT} "P"         "$P"           "Nombre de esta práctica y su directorio"
	${PRINT} "DIRFC"     "${DIRFC}"     "Directorio de la práctica 1 con las clases Fecha y Cadena"
	${PRINT} "DIRTESTS"  "${DIRTESTS}"  "Directorio de los programas de pruebas unitarias automáticas"
	${PRINT} "DIRLUHN"   "${DIRLUHN}"   "Directorio donde está el fichero con el algoritmo de Luhn"
	echo
	echo "# Traducción (preprocesado, compilación y enlazado):"
	echo
	${PRINT} "CXX"      "${CXX}"      "Compilador"
	${PRINT} "CPPFLAGS" "${CPPFLAGS}" "Opciones para el preprocesador"
	${PRINT} "CXXFLAGS" "${CXXFLAGS}" "Opciones para el compilador"
	${PRINT} "LDFLAGS"  "${LDFLAGS}"  "Opciones para el enlazador"
	${PRINT} "LDLIBS"   "${LDLIBS}"   "Opciones para el enlazador (bibliotecas a enlazar)"
	echo
	echo "# Ficheros:"
	echo
	${PRINT} "SRCS"      "${SRCS}"      "Fuentes a escribir"
	${PRINT} "HDRS"      "${HDRS}"      "Cabeceras a escribir"
	${PRINT} "MAIN_SRCS" "${MAIN_SRCS}" "Fuentes del programa de pruebas de consola"
	${PRINT} "MAIN_EXE"  "${MAIN_EXE}"  "Programa de pruebas de consola"
	${PRINT} "TEST_SRCS" "${TEST_SRCS}" "Fuentes del programa de pruebas unitarias automáticas"
	${PRINT} "TEST_HDRS" "${TEST_HDRS}" "Cabeceras del programa de pruebas unitarias automáticas"
	${PRINT} "TEST_EXE"  "${TEST_EXE}"  "Programa de pruebas unitarias automáticas"
	${PRINT} "NOMBRETAR" "${NOMBRETAR}" "El archivo comprimido con lo que hay que entregar"
