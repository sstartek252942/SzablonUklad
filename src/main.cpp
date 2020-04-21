#include <iostream>
#include <iomanip>
#include "Wektor.hh"
#include "Macierz.hh"
#include "LZespolona.hh"
//#include "rozmiar.h"


int main()
{
  Wektor<LZespolona,5> D3;
  D3[0] = {8,6};
  std::cout << D3.dlugosc() << std::endl;

  Macierz<LZespolona,5> M3;
  M3[0][3] = {8,6};
  std::cout << M3 << std::endl;
}
