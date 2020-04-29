#include "Macierz.hh"
#include <iomanip>

//************Metody:Getter i Setter************//
template<class TYP, int ROZMIAR>
const Wektor<TYP,ROZMIAR> & Macierz<TYP,ROZMIAR>::operator[] (int index) const
{
  if (index < 0 || index >= ROZMIAR) 
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  return this->array[index];
}

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> & Macierz<TYP,ROZMIAR>::operator[] (int index)
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
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator + (const Macierz<TYP,ROZMIAR> & M2) const
{
  Macierz<TYP,ROZMIAR> temp;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    temp[i] = (*this)[i] + M2[i];
  }
  return temp;
}

template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator - (const Macierz<TYP,ROZMIAR> & M2) const
{
  Macierz<TYP,ROZMIAR> temp;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    temp[i] = (*this)[i] - M2[i];
  }
  return temp;
}

template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator * (const Macierz<TYP,ROZMIAR> & M2) const
{
  Macierz<TYP,ROZMIAR> M1T((*this).transponuj());
  Macierz<TYP,ROZMIAR> temp;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    for (int j = 0; j < ROZMIAR; j++)    
    {
        temp[j][i] += M1T[j] * M2[i];
        //std::cout << (*this)[j] * M2T[i] << std::endl;
    }
  }
  return temp;
}

template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator * (double a) const 
{
  Macierz<TYP,ROZMIAR> temp;
  TYP tempTYP(a);
  for (int i = 0; i < ROZMIAR; i++)    
  {
    temp[i] = (*this)[i] * tempTYP;
  }
  return temp;
}

template<class TYP, int ROZMIAR>
bool Macierz<TYP,ROZMIAR>::operator == (const Macierz<TYP,ROZMIAR> & M2) const
{
  bool flag = true;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    if ((*this)[i] != M2[i])
    flag = false;
  }
  return flag;
}

template<class TYP, int ROZMIAR>
bool Macierz<TYP,ROZMIAR>::operator != (const Macierz<TYP,ROZMIAR> & M2) const
{
  return !(*this==M2);
}
  
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::transponuj() const
{
  Macierz<TYP,ROZMIAR> M2;
  for (int j = 0; j < ROZMIAR; j++)
    for (int i = 0; i < ROZMIAR; i++)
        M2[j][i]= (*this)[i][j];
  
  return M2;
}

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator * (const Wektor<TYP,ROZMIAR> & W) const
{
  Wektor<TYP,ROZMIAR> tempW;
  for (int i = 0; i < ROZMIAR; i++)    
  {
    for (int j = 0; j < ROZMIAR; j++)    
    {
      tempW[i] += (*this)[j][i] * W[j];
      //std::cout << (*this)[j][i] << " " << W[j] << std::endl;
    }
  }
  return tempW;
}

template<class TYP, int ROZMIAR> //NOT WORK
TYP Macierz<TYP,ROZMIAR>::dopelnienie(int x, int y) const
{
  Macierz<TYP,4> macierzSmallTemp;
  if (x < 0 || x >= ROZMIAR || y < 0 || y >= ROZMIAR)
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
  
  for (int j = 0; j < ROZMIAR; j++)
  {
     for (int i = 0; i < ROZMIAR; i++)
     {
       if (i < x && j < y) macierzSmallTemp[i][j] = (*this)[i][j];
       if (i < x && j > y) macierzSmallTemp[i][j-1] = (*this)[i][j];
       if (i > x && j < y) macierzSmallTemp[i-1][j] = (*this)[i][j];
       if (i > x && j > y) macierzSmallTemp[i-1][j-1] = (*this)[i][j];   
     }
  }
  return macierzSmallTemp.Wyznacznik();
}

template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::odwroc() const
{
  Macierz<TYP,ROZMIAR> M2;
  TYP Wyznacznik = (*this).Wyznacznik();
  if (Wyznacznik != 0)
  {
    for (int j = 0; j < ROZMIAR; j++)
      for (int i = 0; i < ROZMIAR; i++)
	{
        M2[i][j] = (*this).dopelnienie(i,j) / Wyznacznik * ((i+j)%2==0?1:-1);
  }}
  else throw THROWDIVIDEZERO;
  return M2.transponuj();
}

template<class TYP, int ROZMIAR>
TYP Macierz<TYP,ROZMIAR>::Wyznacznik() const //laplace, gauss
{
  TYP temp(1);
  
  Macierz<TYP,ROZMIAR> tempMacierz(*this);
  for (int i = 0; i < ROZMIAR-1; i++)
  {
    //podmienianie  
    bool flag = false;
    int j = i;        
    while (!flag && j < ROZMIAR)
    {
      if (tempMacierz[i][j] != 0)
      {
        if (i != j) 
        {
          tempMacierz = tempMacierz.SwapLineVertical(i, j);
          temp = temp * -1.0;
        }
        flag = true;
      }
      j++;
    }

    //wyznacznik 0, bo nie da się podzielic i zostaly same zera
    if (!flag) 
    {
      temp = 0;
      return temp;
    }
    //odejmowanie
    for (int k = i+1; k < ROZMIAR; k++)
    {
      tempMacierz[k] = tempMacierz[k] - tempMacierz[i] * tempMacierz[k][i] / tempMacierz[i][i];  
    }
    //std::cout << tempMacierz << std::endl;
  }
    
  for (int i = 0; i < ROZMIAR; i++)
  {
    temp *= tempMacierz[i][i];
  }
  return temp;
}

template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::SwapLineHorizontal(int w1, int w2) const
{
  Macierz<TYP,ROZMIAR> M2((*this).transponuj());
  if (w1 < 0 || w1 >= ROZMIAR || w2 < 0 || w2 >= ROZMIAR)
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
 
  Wektor<TYP,ROZMIAR> tempW(M2[w1]);
  M2[w1] = M2[w2];
  M2[w2] = tempW;
  M2 = M2.transponuj();
  return M2;
}

template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::SwapLineVertical(int w1, int w2) const
{
  Macierz<TYP,ROZMIAR> M2(*this);
  if (w1 < 0 || w1 >= ROZMIAR || w2 < 0 || w2 >= ROZMIAR)
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
 
  Wektor<TYP,ROZMIAR> tempW(M2[w1]);
  M2[w1] = M2[w2];
  M2[w2] = tempW;
  return M2;
}

//************Funkcje mnozenia************//
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> operator *(double a, const Macierz<TYP,ROZMIAR> M)
{
  return M*a;
}

//************Funkcje: in/out************//
template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP,ROZMIAR> &Mac)
{
  for (int i = 0; i < ROZMIAR; i++)
  { 
    Strm>>Mac[i];
  }
  return Strm;
}

template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP,ROZMIAR> &Mac)
{
  for (int i = 0; i < ROZMIAR; i++)
  {
     for (int j = 0; j < ROZMIAR; j++)
     {
       Strm << std::setw(SKIP) << Mac.transponuj()[i][j];
     }
   Strm  << std::endl;
  }
  return Strm;
}


