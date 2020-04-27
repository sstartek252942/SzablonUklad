#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  
  LZespolona() : re(0), im(0) {};
  LZespolona(double re2, double im2) : re(re2), im(im2) {};
  explicit LZespolona (double liczba) : re(liczba), im(0) {};

  LZespolona operator = (double Skl2) {re = Skl2; im = 0.0; return (*this);};
};

std::istream & operator >>(std::istream & strm,        LZespolona & Skl);
std::ostream & operator <<(std::ostream & strm, const LZespolona & Skl);

/*
 * Dalej powinny pojawic sie zapowiedzi definicji bez przeciazen operatorow
 */

LZespolona  Sprzezenie (const LZespolona & Skl);
double	  Modul (const LZespolona & Skl);

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */



bool  operator == (const LZespolona & Skl1,  const LZespolona & Skl2);
bool  operator != (const LZespolona & Skl1,  const LZespolona & Skl2);
bool  operator == (const LZespolona & Skl1,  double  Skl2);
bool  operator != (const LZespolona & Skl1,  double  Skl2);

LZespolona  operator * (const LZespolona & Skl,  double  a);
LZespolona  operator / (const LZespolona & Skl,  double  a);

LZespolona  operator + (const LZespolona & Skl1,  const LZespolona & Skl2);
LZespolona  operator - (const LZespolona & Skl1,  const LZespolona & Skl2);
LZespolona  operator * (const LZespolona & Skl1,  const LZespolona & Skl2);
LZespolona  operator / (const LZespolona & Skl1,  const LZespolona & Skl2);

LZespolona  operator += (LZespolona & Skl1,  const LZespolona & Skl2);
LZespolona  operator -= (LZespolona & Skl1,  const LZespolona & Skl2);
LZespolona  operator *= (LZespolona & Skl1,  const LZespolona & Skl2);

LZespolona  operator *= (LZespolona & Skl1,  double Skl2);

/*
LZespolona  operator += (LZespolona & Skl1,  double Skl2) {Skl1.re = Skl1.re + Skl2; return Skl1;}
LZespolona  operator -= (LZespolona & Skl1,  double Skl2) {Skl1.re = Skl1.re - Skl2; return Skl1;}

LZespolona  operator /= (LZespolona & Skl1,  double Skl2) {Skl1 = Skl1 / Skl2; return Skl1;}*/

#endif
