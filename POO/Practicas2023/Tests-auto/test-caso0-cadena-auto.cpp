/* $Id: test-caso0-cadena-auto.cpp $
 *
 * Pruebas unitarias automáticas para la clase Cadena (P0, P1)
 *
 * ©2014 Antonio G.ª Dguez.
 * ©2015-23 el resto de profesores de POO
 */
#include "test-auto.hpp"

using namespace std;

namespace {
   bool bPrimera = true;
}

FCTMF_SUITE_BGN(test_cadena) {

  if (bPrimera) {
    bPrimera = false;
    cerr << "\n---------- PRÁCTICA "
#ifdef P0
      "0"
#else
      "1"
#endif
      ": CADENA ----------\n" << endl;
  }

  FCT_TEST_BGN(Cadena - Ctor: repetir caracter ciertas veces) {
    const Cadena a(5, '*');
    const Cadena b(0, '*');
    fct_chk_eq_str(a.operator const char*(), "*****");
    fct_chk_eq_int(a.length(), 5);
    fct_chk_eq_str(b.operator const char*(), "");
    fct_chk_eq_int(b.length(), 0);
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Ctor: entero - repite espacios) {
    const Cadena a(10);
    const Cadena b(size_t(0));
    fct_chk_eq_str(a.operator const char*(), "          ");
    fct_chk_eq_int(a.length(), 10);
    fct_chk_eq_str(b.operator const char*(), "");
    fct_chk_eq_int(b.length(), 0);
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Ctor: sin parametros - vacia) {
    const Cadena a;
    fct_chk_eq_str(a.operator const char*(), "");
    fct_chk_eq_int(a.length(), 0);
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Ctor: por copia de otra cadena) {
    const size_t n = 3;
    const Cadena a(n);
    const Cadena b(a);
    fct_chk_eq_str(a.operator const char*(), "   ");
    fct_chk_eq_int(a.length(), n);
    fct_chk_eq_str(b.operator const char*(), "   ");
    fct_chk_eq_int(b.length(), n);
    fct_chk(a.operator const char *() != b.operator const char*());
    const Cadena c;
    const Cadena d(c);
    fct_chk_eq_str(c.operator const char*(), "");
    fct_chk_eq_int(c.length(), 0);
    fct_chk_eq_str(d.operator const char*(), "");
    fct_chk_eq_int(d.length(), 0);
    fct_chk(c.operator const char*() != d.operator const char*());
  }
  FCT_TEST_END();
  // Solo en P1, no se pide en P0
#ifndef P0
  FCT_TEST_BGN(Cadena - Ctor: de movimiento) {
    Cadena a(3);
    const char* c = a.operator const char*();
    const Cadena b(std::move(a));
    fct_chk(b.operator const char*() == c);
    fct_chk_eq_str(b.operator const char*(), "   ");
    fct_chk_eq_int(b.length(), 3);
    fct_chk_eq_str(a.operator const char*(), "");
    fct_chk_eq_int(a.length(), 0);
    Cadena d;
    c = d.operator const char *();
    const Cadena e(std::move(d));
    fct_chk(e.operator const char*() == c);
    fct_chk_eq_str(e.operator const char*(), "");
    fct_chk_eq_int(e.length(), 0);
    fct_chk(d.operator const char*() != c);
    fct_chk_eq_str(d.operator const char*(), "");
    fct_chk_eq_int(d.length(), 0);
  }
  FCT_TEST_END();
#endif

  FCT_TEST_BGN(Cadena - Ctor: desde cadena de bajo nivel) {
    const Cadena a("hola");
    fct_chk_eq_str(a.operator const char*(), "hola");
    fct_chk_eq_int(a.length(), 4);
    const char* b = "";
    const Cadena c(b);
    fct_chk_eq_str(c.operator const char*(), "");
    fct_chk_eq_int(c.length(), 0);
    fct_chk(c.operator const char*() != b);
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Asignar una cadena a otra) {
    Cadena a("adios");
    const Cadena b;
    a = b;
    fct_chk_eq_str(a.operator const char*(), "");
    fct_chk_eq_int(a.length(), 0);
    fct_chk_eq_str(b.operator const char*(), "");
    fct_chk_eq_int(b.length(), 0);
    fct_chk(a.operator const char*() != b.operator const char*());
    const Cadena c(3);
    a = c;
    fct_chk_eq_str(a.operator const char*(), "   ");
    fct_chk_eq_int(a.length(), 3);
    fct_chk_eq_str(c.operator const char*(), "   ");
    fct_chk_eq_int(c.length(), 3);
    fct_chk(a.operator const char*() != c.operator const char*());
  }
  FCT_TEST_END();

  // Solo en P1, no se pide en P0
#ifndef P0
  FCT_TEST_BGN(Cadena - Asignar una cadena a otra: movimiento) {
    Cadena a("hola"), b("adios");
    const char* c = b.operator const char*();
    a = std::move(b);
    fct_chk(a.operator const char*() == c);
    fct_chk_eq_str(a.operator const char*(), "adios");
    fct_chk_eq_int(a.length(), 5);
    fct_chk_eq_str(b.operator const char*(), "");
    fct_chk_eq_int(b.length(), 0);
    Cadena d;
    c = d.operator const char*();
    a = std::move(d);
    fct_chk(a.operator const char*() == c);
    fct_chk_eq_str(a.operator const char*(), "");
    fct_chk_eq_int(a.length(), 0);
    fct_chk(d.operator const char*() != c);
    fct_chk_eq_str(d.operator const char*(), "");
    fct_chk_eq_int(d.length(), 0);
  }
  FCT_TEST_END();
#endif

  FCT_TEST_BGN(Cadena - Asignar una cadena de bajo nivel) {
    Cadena a;
    a = "lembas";
    fct_chk_eq_str(a.operator const char*(), "lembas");
    fct_chk_eq_int(a.length(), 6);
    const char* b = "";
    a = b;
    fct_chk_eq_str(a.operator const char*(), "");
    fct_chk_eq_int(a.length(), 0);
    fct_chk(a.operator const char*() != b);
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Observadora de longitud: cadena vacia) {
    const Cadena a;
    fct_chk_eq_int(a.length(), 0);
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Observadora de longitud: cadena no vacia) {
    const char *s = "Pimienta, sal y cebolla cuando se pone la olla";
    const Cadena a(s);
    fct_chk_eq_int(a.length(), strlen(s));
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Observadora: operator const char*()) {
    const Cadena a, b("La avaricia rompe el saco");
    fct_chk_eq_str(a.operator const char*(), "");
    fct_chk_eq_str(b.operator const char*(), "La avaricia rompe el saco");
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Concatenacion: con +=) {
    Cadena a("Ingles,"); // Inglés, pero para que no haya problemas
    // ni diplomáticos ni de codificaciones de caracteres...
    a += Cadena(" pirata es");
    fct_chk_eq_str(a.operator const char*(), "Ingles, pirata es");
    fct_chk_eq_int(a.length(), 17);
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Concatenacion: con +) {
    const Cadena a("Cada cual,"), b(" en su corral");
    Cadena c = a + b;
    fct_chk_eq_str((a + b).operator const char*(), "Cada cual, en su corral");
    fct_chk_eq_int(c.length(), a.length() + b.length());
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Comparacion: igualdad) {
    fct_chk(  Cadena("hola")  ==        "hola"   );
    fct_chk(!(       "hola"   == Cadena("adios")));
    fct_chk(!(Cadena("hola")  == Cadena("holas")));
    fct_chk(!(Cadena("holas") == Cadena("hola" )));
    fct_chk(  Cadena(       ) ==          ""     );
    fct_chk(!(         ""     == Cadena("adios")));
    fct_chk(!(Cadena("adios") == Cadena(       )));
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Comparacion: desigualdad) {
    fct_chk(!(       "hola"   != Cadena("hola" )));
    fct_chk(  Cadena("hola" ) !=        "adios"  );
    fct_chk(  Cadena("hola" ) != Cadena("holas") );
    fct_chk(  Cadena("holas") != Cadena("hola" ) );
    fct_chk(!(Cadena(       ) !=          ""    ));
    fct_chk(           ""     != Cadena("adios") );
    fct_chk(  Cadena("adios") != Cadena(       ) );
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Comparacion: menor que) {
    fct_chk(  Cadena( "" ) <        "x"   );
    fct_chk(         "a"   < Cadena("b" ) );
    fct_chk(!(Cadena(    ) <         ""  ));
    fct_chk(!(Cadena("a" ) < Cadena( "" )));
    fct_chk(!(Cadena("ab") < Cadena("ab")));
    fct_chk(!(Cadena("ca") < Cadena("aa")));
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Comparacion: menor o igual que) {
    fct_chk(          ""   <= Cadena("x" ) );
    fct_chk(  Cadena("a" ) <=        "b"   );
    fct_chk(  Cadena("ab") <= Cadena("ab") );
    fct_chk(  Cadena(    ) <=        ""    );
    fct_chk(!(Cadena("a" ) <= Cadena(    )));
    fct_chk(!(Cadena("ca") <=        "aa" ));
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Comparacion: mayor que) {
    fct_chk(!(Cadena( "" ) >        "x"  ));
    fct_chk(!(       "a"   > Cadena("b" )));
    fct_chk(!(Cadena(    ) > Cadena( "" )));
    fct_chk(!(Cadena("ab") > Cadena("ab")));
    fct_chk(  Cadena("a" ) >         ""   );
    fct_chk(  Cadena("ca") > Cadena("aa") );
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Comparacion: mayor o igual que) {
    fct_chk(!(        ""   >= Cadena("x" )));
    fct_chk(!(Cadena("a" ) >=        "b" ) );
    fct_chk(  Cadena("ab") >= Cadena("ab") );
    fct_chk(  Cadena(    ) >= Cadena( "" ) );
    fct_chk(  Cadena("a" ) >=         ""   );
    fct_chk(  Cadena("ca") >= Cadena("aa") );
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Leer caracter: [] y posicion valida) {
    const Cadena a("abcd");
    fct_chk(a.operator[](0) == 'a');
    fct_chk(a.operator[](3) == 'd');
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Leer caracter: [] y posicion no valida) {
    const Cadena a;
    const Cadena b("abcd");
    fct_chk(a.operator[](0) == 0);
    fct_chk(b.operator[](4) == 0);
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Leer caracter: at y posicion valida) {
    const Cadena a("abcd");
    fct_chk(a.at(0) == 'a');
    fct_chk(a.at(3) == 'd');
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Leer caracter: at y posicion no valida) {
    const Cadena a;
    const Cadena b("abcd");
    fct_chk_ex(out_of_range&, a.at(0));
    fct_chk_ex(out_of_range&, b.at(4));
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Escribir caracter: []) {
    Cadena a("pava");
    a.operator[](2) = 'p';
    fct_chk_eq_str(a.operator const char*(), "papa");
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Escribir caracter: at()) {
    Cadena a("Papa");
    a.at(2) = 'c';
    fct_chk_eq_str(a.operator const char*(), "Paca");
  }
  FCT_TEST_END();
  FCT_TEST_BGN(Cadena - Escribir caracter: at() y posicion no valida) {
    Cadena a("Papa");
    fct_chk_ex(out_of_range&, a.at(21) = 'x');
    fct_chk_ex(out_of_range&, a.at(4) = 'x');
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Subcadena: caso normal) {
    const Cadena a("eenie meenie moe");
    fct_chk_eq_str(a.substr(6, 6).operator const char*(), "meenie");
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Subcadena: posicion inicial mayor que longitud) {
    const Cadena a("0123456789");
    fct_chk_ex(out_of_range&, a.substr(10, 10));
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Subcadena: posicion inicial negativa) {
    const Cadena a("0123456789");
    fct_chk_ex(out_of_range&, a.substr(-1, 10));
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Subcadena: tamanno cero) {
    const Cadena a("eenie meenie moe");
    fct_chk_eq_str(a.substr(6, 0).operator const char*(), "");
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Subcadena: tamanno mayor que longitud restante) {
    const Cadena a("0123456789");
    fct_chk_ex(out_of_range&, a.substr(9, 2));
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Subcadena: tamanno negativo) {
    const Cadena a("0123456789");
    fct_chk_ex(out_of_range&, a.substr(9, -1));
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Subcadena: tamanno excesivo) {
    const Cadena a("0123456789");
    fct_chk_ex(out_of_range&, a.substr(9, 1000));
  }
  FCT_TEST_END();

  // P1 - E/S e iteradores
#ifndef P0
  FCT_TEST_BGN(Cadena - Extraccion: entrada vacia) {
    istringstream is("");
    Cadena c("algo");
    is >> c;
    fct_chk_empty_str(c.operator const char*());
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Extraccion: solo espacios) {
    istringstream is(" \t\r\n\v");
    Cadena c("algo");
    is >> c;
    fct_chk_empty_str(c.operator const char*());
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Extraccion: hasta fin de entrada) {
    istringstream is("prueba");
    Cadena c;
    is >> c;
    fct_chk_eq_str(c.operator const char*(), "prueba");
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Extraccion: una palabra) {
    istringstream is("bueno bonito barato");
    Cadena c;
    is >> c;
    fct_chk_eq_str(c.operator const char*(), "bueno");
    fct_chk(is.peek() == ' ');
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Extraccion: una palabra con espaciado inicial) {
    istringstream is("   hola adiós");
    Cadena c;
    is >> c;
    fct_chk_eq_str(c.operator const char*(), "hola");
    fct_chk(is.peek() == ' ');
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Extraccion: una palabra de mas de 32 caracteres) {
    istringstream is("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    Cadena c;
    is >> c;
    fct_chk_eq_str(c.operator const char*(), "abcdefghijklmnopqrstuvwxyzABCDEF");
    fct_chk(is.peek() == 'G');
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Insercion) {
    ostringstream os;
    const char *s = "probando 1 2 3";
    const Cadena c(s);
    os << c;
    fct_chk_eq_str(os.str().c_str(), s);
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Insercion nula) {
    ostringstream os;
    const Cadena c;
    os << c;
    fct_chk_empty_str(os.str().c_str());
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Iterador: begin()) {
    Cadena a("hola");
    *a.begin() = ' ';
    fct_chk(a.begin() == a.operator const char*());
    fct_chk(a[0] == ' ');
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Iterador: end()) {
    Cadena a("hola");
    fct_chk(a.end() == a.operator const char*() + 4);
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Iterador: begin() const) {
    const Cadena a("hola");
    fct_chk(a.begin() == a.operator const char*());
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Iterador: end() const) {
    const Cadena a("hola");
    fct_chk(a.end() == a.operator const char*() + 4);
  }
  FCT_TEST_END();
 FCT_TEST_BGN(Cadena - Iterador: cbegin()) {
    const Cadena a("hola");
    fct_chk(a.cbegin() == a.operator const char*());
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Iterador: cend()) {
    const Cadena a("hola");
    fct_chk(a.cend() == a.operator const char*() + 4);
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Iterador: rbegin()/rend()) {
    Cadena a("hola");
    *a.rbegin() = 'o';
    *a.rend().base() = ' ';
    fct_chk(*a.rbegin() == 'o');
    fct_chk(*a.rend().base() == ' ');
  } FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Iterador: rbegin()/rend() const) {
    const Cadena a("hola");
    fct_chk(*a.rbegin() == 'a');
    fct_chk(*a.rend().base() == 'h');
  } FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Iterador: crbegin()/crend()) {
    const Cadena a("hola");
    fct_chk(*a.crbegin() == 'a');
    fct_chk(*a.crend().base() == 'h');
  } FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Iteradores: recorridos directos) {
    Cadena a("hola");
    for (Cadena::iterator i = a.begin(); i != a.end(); ++i)
      (*i)++;
    fct_chk(a == "ipmb");
    const Cadena b(a);
    ostringstream os;
    for (Cadena::const_iterator i = b.begin(); i != b.end(); ++i)
      os << *i;
    fct_chk(os.str() == "ipmb");
    for (auto i = a.cbegin(); i != a.cend(); ++i) os << *i;
    fct_chk(os.str() == "ipmbipmb");
  }
  FCT_TEST_END();

  FCT_TEST_BGN(Cadena - Iteradores: recorridos inversos) {
    const Cadena a("hola");
    Cadena b(a);
    ostringstream os;
    for (Cadena::reverse_iterator r = b.rbegin(); r != b.rend(); ++r)
      os << ++*r;
    fct_chk(os.str() == "bmpi");
    for (Cadena::const_reverse_iterator r = a.rbegin(); r != a.rend(); ++r)
      os << *r;
    fct_chk(os.str() == "bmpialoh");
    for (auto r = a.crbegin(); r != a.crend(); ++r) 
      os << *r;
    fct_chk(os.str() == "bmpialohaloh");
  }
  FCT_TEST_END();
#endif

#if defined(P2) || defined(P3) || defined(P4)
  FCT_TEST_BGN(Cadena - hash) {
    hash<Cadena> hc;
    size_t h = hc("hola");	// operator()
    fct_chk_neq_int(h, 0); // 4749747280605603126
  }
  FCT_TEST_END();
#endif
}
FCTMF_SUITE_END()
