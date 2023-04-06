# Makefile para las comprobaciones estáticas del código fuente de
# cadena.cpp y fecha.cpp. Clases Cadena y Fecha (P0 y P1).

# ©2017      Los profesores de POO (Universidad de Cádiz)
# ©2021      Gerardo - La Gran Unificación
# ©2022-2023 Pedro Delgado, Francisco Palomo

# Estándar de C++ empleado.

STD = c++17

# Directorio y nombre simbólico de la biblioteca del DSL.

DIR = ../dsl-comprobaciones
LIB = cac

# Nombre del directorio de prácticas (P0, P1, etc.).

ifndef P
P = $(shell basename ${PWD})
endif

# Compilador.

override CXX = clang++

# Opciones para el preprocesador.

CPPFLAGS := $(shell llvm-config --cppflags)
CPPFLAGS += -I${DIR} -D$P

# Opciones para el compilador.

CXXFLAGS := -std=${STD} -O3

# Opciones para el enlazador.

LDFLAGS := -L${DIR}
LDLIBS  = -l${LIB}

# Búsqueda automática de dependencias de bibliotecas estáticas.
#
# NOTA
#
# Hemos construido libcac.a con una lista de dependencias de
# bibliotecas. Para que el enlazador encuentre estas bibliotecas,
# debería bastar con la opción «-Xlinker -plugin libdep» o,
# equivalentemente, «-Wl,-plugin libdep». Sin embargo, no encuentra
# libdep, por lo que suministraremos su camino explícito.

PLUGIN = /usr/lib/x86_64-linux-gnu/bfd-plugins/libdep.so

# Sin embargo, para que funcione con el enlazador «ld» necesita:

# LDFLAGS += -Wl,--copy-dt-needed-entries,-plugin ${PLUGIN}

# Esto no ocurre con «gold». Lo dejamos. Es más rápido y moderno.

LDFLAGS += -fuse-ld=gold -Wl,--plugin ${PLUGIN}

# Fuente, objeto, ejecutable y biblioteca.

SRC =  fecha_cadena_check.cpp
OBJ := ${SRC:.cpp=.o}
EXE := ${SRC:.cpp=}

.PHONY: all check clean allclean

all: ${EXE}

${EXE}: ${OBJ} ${DIR}/lib${LIB}.a
	${CXX} -o $@ $< ${LDFLAGS} ${LDLIBS}

check: ${EXE}
	./$< -extra-arg-before="-D$P" -extra-arg="-std=${STD}" fecha.cpp cadena.cpp --

clean:
	${RM} ${EXE} ${OBJ}
