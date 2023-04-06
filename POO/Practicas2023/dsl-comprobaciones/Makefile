# Construcción de la biblioteca encargada de las comprobaciones
# estáticas del código fuente de las prácticas de POO.

# ©2021      Gerardo - La Gran Unificación
# ©2022-2023 Pedro Delgado, Francisco Palomo

# Debemos emplear el compilador Clang/LLVM: no permitimos cambios al llamar a make.

override CXX = clang++

# Opciones para el preprocesador.

CPPFLAGS := $(shell llvm-config --cppflags)

# Opciones para el compilador.

CXXFLAGS := $(shell llvm-config --cxxflags)

# Opciones adicionales que estimamos oportunas.

CXXFLAGS += -O3 -fno-rtti -fexceptions

# Opciones para el enlazador.

LDFLAGS := $(shell llvm-config --ldflags)
LDLIBS  := $(shell llvm-config --libs --system-libs)

# Bibliotecas de Clang.

LDLIBS += \
-lclangFrontend \
-lclangSerialization \
-lclangDriver \
-lclangTooling \
-lclangParse \
-lclangSema \
-lclangAnalysis \
-lclangEdit \
-lclangAST \
-lclangASTMatchers \
-lclangLex \
-lclangBasic \
-lclangRewrite \
-lclangRewriteFrontend

# Versión específica de Clang.
#
# No existe una forma totalmente transportable de hacer esto. La idea
# es extraer el número mayor de versión que aparece tras la cadena
# "clang version". Funcionará en tanto en cuando la opción --version
# de Clang emplee este formato.
#
# NOTAS
#
# - [0-9] es [0123456789] (en POSIX, con localización "C", etc.).
# - Con grep -E y sed puede sustituirse [0-9] por [[:digit:]].
# - Emplear sed -n 's/.*clang version \([0-9]*\).*/\1/p' es otra opción.

CLANGVER = $(shell ${CXX} --version | grep -io 'clang version [0-9]*' | grep -o '[0-9]*')

# Con la versión 15 de Clang/LLVM necesitamos esta nueva biblioteca.

ifeq (${CLANGVER}, 15)
LDLIBS += -lclangSupport
endif

# Fuentes.

SRCS = caclibrary.cpp execute.cpp matchers.cpp
HDRS = ${SRCS:.cpp=.h} info.h

# Objetos.

OBJS = ${SRCS:.cpp=.o}

# Biblioteca.

LIB = libcac.a

all: ${LIB}

${LIB}: ${OBJS}
	${AR} ${ARFLAGS} -l "${LDFLAGS} ${LDLIBS}" $@ $^

${OBJS}: ${HDRS}

clean:
	${RM} ${OBJS}

clean-all: clean
	${RM} ${LIB} core *~

.PHONY: all clean clean-all
