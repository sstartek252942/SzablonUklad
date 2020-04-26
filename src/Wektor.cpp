#include "Wektor.hh"
#include "LZespolona.hh"
#include <math.h>
#include <iomanip>

//************Metody:Getter i Setter************//
template<class TYP, int ROZMIAR>
const TYP & Wektor<TYP,ROZMIAR>::operator[] (int index) const
{
  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->array[index];
}
 
template<class TYP, int ROZMIAR>
TYP & Wektor<TYP,ROZMIAR>::operator[] (int index)
{
  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->array[index];
}

//************Metody operatorow arytmetycznych************//
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator + (Wektor<TYP,ROZMIAR> const &Wek) const
{
  Wektor tempWek;
  TYP tempTYPU;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    tempTYPU = (*this)[i] + Wek[i];
    tempWek[i] = tempTYPU;
  }
  return tempWek;
}

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator - (Wektor<TYP,ROZMIAR> const &Wek) const
{
  Wektor<TYP,ROZMIAR> tempWek;
  TYP tempTYPU;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    tempTYPU = (*this)[i] - Wek[i];
    tempWek[i]=tempTYPU;
  }
  return tempWek;
}

template<class TYP, int ROZMIAR>
TYP Wektor<TYP,ROZMIAR>::operator * (Wektor<TYP,ROZMIAR> const &Wek) const
{
  TYP tempTYPU = (TYP) 0.0;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    tempTYPU += (*this)[i] * Wek[i];
  }

  return tempTYPU;
}

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator * (TYP a) const
{
  Wektor<TYP,ROZMIAR> tempWek;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    tempWek[i] = (*this)[i] * a;
  }
  return tempWek;
}

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator / (TYP a) const
{
  Wektor<TYP,ROZMIAR> tempWek;
  if (a != 0.0)
  for (int i = 0; i < ROZMIAR; i++)    
  {
    tempWek[i] = (*this)[i] / a;
  }
  else throw THROWDIVIDEZERO;
  return tempWek;
}

template<class TYP, int ROZMIAR>
double Wektor<TYP,ROZMIAR>::dlugosc() const
{
  double tempDouble = 0;
  for (int i = 0; i < ROZMIAR; i++)
  {
    tempDouble += (*this)[i] * ((*this)[i]);
  }
  return sqrt(tempDouble);
}

template <>
double Wektor<LZespolona,4>::dlugosc() const
{
  double tempDouble = 0;
  for (int i = 0; i < 4; i++)
  {

    LZespolona tempLZ = (*this)[i]*Sprzezenie((*this)[i]);
    tempDouble += tempLZ.re;
  }
  return sqrt(tempDouble);
}

template <>
double Wektor<LZespolona,5>::dlugosc() const
{
  double tempDouble = 0;
  for (int i = 0; i < 5; i++)
  {

    LZespolona tempLZ = (*this)[i]*Sprzezenie((*this)[i]);
    tempDouble += tempLZ.re;
  }
  return sqrt(tempDouble);
}

//*****Porownania*****//
template<class TYP, int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator == (const Wektor<TYP,ROZMIAR> & W2) const
{ 
  bool flag = true;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    if (abs((*this)[i]-W2[i])>EPSILON)
    flag = false;
  }
  return flag;
}

template<>
bool Wektor<LZespolona,4>::operator == (const Wektor<LZespolona,4> & W2) const
{ 
  bool flag = true;
  for (int i = 0; i < 4; i++)    
  {
    if ((*this)[i] != W2[i])
    flag = false;
  }
  return flag;
}


template<>
bool Wektor<LZespolona,5>::operator == (const Wektor<LZespolona,5> & W2) const
{ 
  bool flag = true;
  for (int i = 0; i < 5; i++)    
  {
    if ((*this)[i] != W2[i])
    flag = false;
  }
  return flag;
}

template<class TYP, int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator != (const Wektor<TYP,ROZMIAR> & W2) const
{ 
  return !((*this)==W2);
}

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::Swap(int w1, int w2) const
{
  Wektor<TYP,ROZMIAR> W2(*this);
  if (w1 < 0 || w1 >= ROZMIAR || w2 < 0 || w2 >= ROZMIAR)
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
 
  TYP temp(W2[w1]);
  W2[w1] = W2[w2];
  W2[w2] = temp;
  return W2;
}

//************Koniec Metod - Start Fukcji************//

//************Funkcje mnozenia************//
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> operator*(TYP a, const Wektor<TYP,ROZMIAR> & W2)
{
  return W2*a;
}

//************Funkcje: in/out************//
template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP,ROZMIAR> &Wek)
{
  for (int i = 0; i < ROZMIAR; i++)    
  {
    TYP newElement;
    Strm>>newElement;
    Wek[i] = newElement;
  }
  return Strm;
}

template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP,ROZMIAR> &Wek)
{
  for (int i = 0; i < ROZMIAR; i++)    
  {
    Strm<< std::setw(SKIP) << Wek[i];
  }

  return Strm;
}
