#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include "LZespolona.hh"
#include <iostream>


template<class TYP, int ROZMIAR>
class Wektor {
  TYP array[ROZMIAR];


  public: 
  Wektor<TYP,ROZMIAR>() { for (TYP &Wsp: array) Wsp = 0; };

  const TYP & operator[] (int index) const;
  TYP & operator[] (int index);

  Wektor<TYP,ROZMIAR> operator + (Wektor<TYP,ROZMIAR> const &Wek) const;
  Wektor<TYP,ROZMIAR> operator - (Wektor<TYP,ROZMIAR> const &Wek) const;
  TYP operator * (Wektor<TYP,ROZMIAR> const &Wek) const;

  Wektor<TYP,ROZMIAR> operator * (TYP a) const;
  Wektor<TYP,ROZMIAR> operator / (TYP a) const;

  double dlugosc() const;

  bool operator== (const Wektor<TYP,ROZMIAR> & W2) const;
  bool operator!= (const Wektor<TYP,ROZMIAR> & W2) const;

  Wektor Swap(int w1, int w2) const;
};
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> operator*(TYP a, const Wektor<TYP,ROZMIAR> & W2);

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP,ROZMIAR> &Wek);

template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP,ROZMIAR> &Wek);

#endif
