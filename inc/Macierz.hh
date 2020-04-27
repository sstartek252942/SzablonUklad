#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


enum MetodaWyznacznika {laplace, gauss};

template<class TYP, int ROZMIAR>
class Macierz {
  Wektor<TYP,ROZMIAR> array[ROZMIAR]; //Program dziala na macierzach pionowych

  TYP dopelnienie(int x, int y) const;

  public: 
  Macierz<TYP,ROZMIAR>()  {for (int j = 0; j < ROZMIAR; j++) for (int i = 0; i < ROZMIAR; i++) this->array[i][j] = 0;};

  const Wektor<TYP,ROZMIAR> & operator[] (int index) const;
  Wektor<TYP,ROZMIAR> & operator[] (int index);

  Macierz<TYP,ROZMIAR> operator + (const Macierz<TYP,ROZMIAR> & B) const;
  Macierz<TYP,ROZMIAR> operator - (const Macierz<TYP,ROZMIAR> & B) const;
  Macierz<TYP,ROZMIAR> operator * (const Macierz<TYP,ROZMIAR> & B) const;

  Macierz<TYP,ROZMIAR> operator * (double B) const;
  Wektor<TYP,ROZMIAR>  operator * (const Wektor<TYP,ROZMIAR> & W) const;

  bool operator == (const Macierz<TYP,ROZMIAR> & W2) const;
  bool operator != (const Macierz<TYP,ROZMIAR> & W2) const;
  
  Macierz<TYP,ROZMIAR> SwapLineVertical  (int w1, int w2) const;
  Macierz<TYP,ROZMIAR> SwapLineHorizontal(int w1, int w2) const;

  Macierz<TYP,ROZMIAR> transponuj() const;
  Macierz<TYP,ROZMIAR> odwroc() const;
  TYP Wyznacznik(MetodaWyznacznika metoda = gauss) const;

  

};

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP,ROZMIAR> &Mac);
template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP,ROZMIAR> &Mac);
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> operator *(double B, const Macierz<TYP,ROZMIAR> M);

//Macierz MacierzJednostkowa();

#endif
