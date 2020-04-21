#include <iostream>
#include <iomanip>

#include "Macierz.cpp"
#include "LZespolona.hh"



template class Wektor<double,3>;
template std::istream& operator >> (std::istream &Strm, Macierz<double,3> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double,3> &Mac);
template Macierz<double,3> operator *(double B, const Macierz<double,3> M);

template class Wektor<double,5>;
template std::istream& operator >> (std::istream &Strm, Macierz<double,5> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double,5> &Mac);
template Macierz<double,5> operator *(double B, const Macierz<double,5> M);

template class Wektor<LZespolona,5>;
template std::istream& operator >> (std::istream &Strm, Macierz<LZespolona,5> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<LZespolona,5> &Mac);
template Macierz<LZespolona,5> operator *(double B, const Macierz<LZespolona,5> M);
