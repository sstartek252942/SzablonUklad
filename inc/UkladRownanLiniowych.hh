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
  UkladRownanLiniowych<TYP,ROZMIAR>(const Macierz<TYP,ROZMIAR> & M, const Wektor<TYP,ROZMIAR> & W){macierz = M; wektor = W;};


  Wektor<TYP,ROZMIAR> rozwiaz(MetodaUkladu metoda = cramer) const;

  const Wektor<TYP,ROZMIAR> & getwektor() const;
  void setwektor(const Wektor<TYP,ROZMIAR> & W);

  const Macierz<TYP,ROZMIAR> & getmacierz() const;
  void setmacierz(const Macierz<TYP,ROZMIAR> & M);
};

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP,ROZMIAR> &UklRown);
template<class TYP, int ROZMIAR>
std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych<TYP,ROZMIAR> &UklRown);


#endif
