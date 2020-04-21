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
  for (int i = 0; i < ROZMIAR; i++)    
  {
    temp[i] = (*this)[i] * a;
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

template<class TYP, int ROZMIAR>
double Macierz<TYP,ROZMIAR>::dopelnienie(int x, int y) const
{
  double temp;
  if (x < 0 || x >= ROZMIAR || y < 0 || y >= ROZMIAR)
  {
    std::cerr << ERROROUTOFBOUNDS << std::endl;
    exit(1);
  }
 
  temp = (*this)[(x+1)%ROZMIAR][(y+1)%ROZMIAR] * (*this)[(x+2)%ROZMIAR][(y+2)%ROZMIAR] - (*this)[(x+2)%ROZMIAR][(y+1)%ROZMIAR] * (*this)[(x+1)%ROZMIAR][(y+2)%ROZMIAR];
  return temp;
}

template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::odwroc() const
{
  Macierz<TYP,ROZMIAR> M2;
  double Wyznacznik = (*this).Wyznacznik();
  if (Wyznacznik != 0)
  {
    for (int j = 0; j < ROZMIAR; j++)
      for (int i = 0; i < ROZMIAR; i++)
        M2[i][j] = (*this).dopelnienie(i,j) / Wyznacznik;
  }
  else throw THROWDIVIDEZERO;
  return M2.transponuj();
}

template<class TYP, int ROZMIAR>
double Macierz<TYP,ROZMIAR>::Wyznacznik(MetodaWyznacznika metoda) const //sarrus, laplace, gauss
{
  double temp = 0;
  switch(metoda){
  case sarrus:		//Macierz 3x3
    for (int i = 0; i < ROZMIAR; i++)
      temp += (*this)[i % ROZMIAR][0] * (*this)[(i+1) % ROZMIAR][1] * (*this)[(i+2) % ROZMIAR][2];
    for (int i = 0; i < ROZMIAR; i++)
      temp -= (*this)[i % ROZMIAR][0] * (*this)[(i+2) % ROZMIAR][1] * (*this)[(i+1) % ROZMIAR][2];
    return temp;

  case laplace:		//Macierz 3x3, dla innych trzeba poprawić dopelnienie
    for (int i = 0; i < ROZMIAR; i++)
    temp += (*this)[i][0] * ((*this).dopelnienie(i,0));
    return temp;
  
  case gauss: //Macierz dowolna
    Macierz<TYP,ROZMIAR> tempMacierz(*this);
    temp = 1;
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
            temp *= -1;
          }
          flag = true;
        }
        j++;
      }
      //wyznacznik 0, bo nie da się podzielic i zostaly same zera
      if (!flag) return 0;

      //odejmowanie
      for (int k = i+1; k < ROZMIAR; k++)
      {
        tempMacierz[k] = tempMacierz[k] - tempMacierz[i] * (tempMacierz[k][i] / tempMacierz[i][i]);
      }
    }
    
    for (int i = 0; i < ROZMIAR; i++)
    {
      temp *= tempMacierz[i][i];
    }
    //tempMacierz[1] = tempMacierz[1] - tempMacierz[0] * (tempMacierz[1][0] / tempMacierz[0][0]);
    //tempMacierz[2] = tempMacierz[2] - tempMacierz[0] * (tempMacierz[2][0] / tempMacierz[0][0]);
    //tempMacierz[2] = tempMacierz[2] - tempMacierz[1] * (tempMacierz[2][1] / tempMacierz[1][1]);

    return temp;
  }
  std::cerr << ERROROUTOFENUM << std::endl;
  exit(0);
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


