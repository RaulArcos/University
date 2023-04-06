/*
 * ©2021 El autor
 */

#include "bienvenida.hpp"
#include "despedida.hpp"
#include <iostream>

void fiesta(void);

int main()
{
  bienvenida();
  fiesta();
  despedida();
}

void fiesta()
{
  std::cout << "¡¡FIESTA, FIESTA!! 🥳🎉🍷" << std::endl;
}
