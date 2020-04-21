#include <iostream>
#include <iomanip>
#include "Wektor.hh"
#include "LZespolona.hh"
//#include "rozmiar.h"


int main()
{
  Wektor<LZespolona,5> D3;
  D3[0] = {8,6};
  std::cout << D3.dlugosc() << std::endl;
}
