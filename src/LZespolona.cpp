#include <iostream>
#include <assert.h>
#include <cmath>
#include "LZespolona.hh"
#include "rozmiar.h"

/****************************************Praca na liczbach zespolonych****************************************/

/****************************************Obliczenia****************************************/


/***Sprzezenie zespolone***/
LZespolona Sprzezenie (const LZespolona & Skl)
{
  LZespolona Temp = Skl;
  Temp.im *= -1;
  return Temp;
}

/***Modul liczby zespolonej***/
double Modul (const LZespolona & Skl)
{
  return sqrt((Skl.re * Skl.re) + (Skl.im * Skl.im));
}

/*!
 * Praca na operatorach arytmetycznych
 */

LZespolona  operator * (const LZespolona & Skl,  double  a)
{
  LZespolona Temp = Skl;
  Temp.re *= a;
  Temp.im *= a;
  return Temp;
}

LZespolona  operator / (const LZespolona & Skl,  double  a)
{
  LZespolona Temp = Skl;
  assert(a != 0);
  Temp.re /= a;
  Temp.im /= a;
  return Temp;
}

/*Operacje porownania liczb zespolonych*/

bool  operator == (const LZespolona & Skl1,  const LZespolona & Skl2)
{
  return (abs(Skl1.re - Skl2.re) <= EPSILON && abs(Skl1.im - Skl2.im) <= EPSILON);
}

bool  operator != (const LZespolona & Skl1,  const LZespolona & Skl2)
{
  return !(Skl1 == Skl2); 	//(Skl2.im != Skl2.im || Skl1.re != Skl2.re)
}

bool  operator == (const LZespolona & Skl1,  double Skl2)
{
  return (abs(Skl1.re - Skl2) <= EPSILON);
}

bool  operator != (const LZespolona & Skl1,  double Skl2)
{
  return !(Skl1 == Skl2); 	//(Skl2.im != Skl2.im || Skl1.re != Skl2.re)
}

LZespolona  operator + (const LZespolona & Skl1,  const LZespolona & Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona  operator - (const LZespolona & Skl1,  const LZespolona & Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (const LZespolona & Skl1,  const LZespolona & Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}

LZespolona  operator / (const LZespolona & Skl1,  const LZespolona & Skl2)
{
  LZespolona  Wynik;
  Wynik = (Skl1 * Sprzezenie(Skl2)) / (Modul(Skl2)*Modul(Skl2));
  return Wynik;
}

LZespolona  operator += (LZespolona & Skl1,  const LZespolona & Skl2) 
{
  Skl1 = Skl1 + Skl2; 
  return Skl1;
}

LZespolona  operator -= (LZespolona & Skl1,  const LZespolona & Skl2) 
{
  Skl1 = Skl1 - Skl2; 
  return Skl1;
}

LZespolona  operator *= (LZespolona & Skl1,  const LZespolona & Skl2) 
{
  Skl1 = Skl1 * Skl2; 
  return Skl1;
}

LZespolona  operator /= (LZespolona & Skl1,  const LZespolona & Skl2) 
{
  Skl1 = Skl1 / Skl2; 
  return Skl1;
}
/*Praca na operatorach przesuniecia*/

/*
 * Wczytywanie ze strumienia liczby zespolonej
 */
std::istream & operator >>(std::istream & strm, LZespolona & Skl)
{
  char znak;
  strm>>znak;
  if (znak != '(') 
    strm.setstate(std::ios::failbit); 
  strm>>Skl.re>>Skl.im>>znak;
  if (znak != 'i') 
    strm.setstate(std::ios::failbit); 
  strm>>znak;
  if (znak != ')') 
    strm.setstate(std::ios::failbit); 
  return strm;
}

/*
 * Przekazywanie do strumienia liczby zespolonej
 */
std::ostream & operator <<(std::ostream & strm, const LZespolona & Skl)
{
  strm << '(' << Skl.re << std::showpos << Skl.im << std::noshowpos << 'i' << ')';// << std::endl;
  return strm;
}
