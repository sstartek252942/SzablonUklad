//#include "Wektor.hh"
//#include <math.h>
#include <iostream>
#include <iomanip>

#include "Wektor.cpp"
#include "LZespolona.hh"



template class Wektor<double,2>;
template Wektor<double,2> operator*(double a, const Wektor<double,2> & W2);
template std::istream & operator>>(std::istream & strm, Wektor<double,2> & Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double,2> &Wek);

template class Wektor<double,3>;
template Wektor<double,3> operator*(double a, const Wektor<double,3> & W2);
template std::istream & operator>>(std::istream & strm, Wektor<double,3> & Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double,3> &Wek);

template class Wektor<double,4>;
template Wektor<double,4> operator*(double a, const Wektor<double,4> & W2);
template std::istream & operator>>(std::istream & strm, Wektor<double,4> & Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double,4> &Wek);

template class Wektor<double,5>;
template Wektor<double,5> operator*(double a, const Wektor<double,5> & W2);
template std::istream & operator>>(std::istream & strm, Wektor<double,5> & Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double,5> &Wek);

template class Wektor<LZespolona,4>;
template Wektor<LZespolona,4> operator*(LZespolona a, const Wektor<LZespolona,4> & W2);
template std::istream & operator>>(std::istream & strm, Wektor<LZespolona,4> & Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<LZespolona,4> &Wek);

template class Wektor<LZespolona,5>;
template Wektor<LZespolona,5> operator*(LZespolona a, const Wektor<LZespolona,5> & W2);
template std::istream & operator>>(std::istream & strm, Wektor<LZespolona,5> & Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<LZespolona,5> &Wek);



//template class Wektor<double,4>;
