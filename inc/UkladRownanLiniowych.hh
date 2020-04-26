#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"


enum MetodaUkladu {cramer, gaussjordan, odwrotna};

template<class TYP, int ROZMIAR>
class UkladRownanLiniowych {
  Macierz<TYP,ROZMIAR> macierz;
  Wektor<TYP,ROZMIAR> wektor;

  public:
  UkladRownanLiniowych<TYP,ROZMIAR>(){};
  UkladRownanLiniowych<TYP,ROZMIAR>(const Macierz & M, const Wektor & W);

  Wektor<TYP,ROZMIAR> rozwiaz(MetodaUkladu metoda = cramer) const;

  const Wektor<TYP,ROZMIAR> & getwektor() const;
  void setwektor(const Wektor<TYP,ROZMIAR> & W);

  const Macierz<TYP,ROZMIAR> & getmacierz() const;
  void setmacierz(const Macierz<TYP,ROZMIAR> & M);
};


std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP,ROZMIAR> &UklRown);

std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych<TYP,ROZMIAR> &UklRown);


#endif
