#include "UkladRownanLiniowych.hh"
#include <iomanip>

//************Metody:Getter i Setter************//
template<class TYP, int ROZMIAR>
const Wektor<TYP,ROZMIAR> & UkladRownanLiniowych<TYP,ROZMIAR>::getwektor() const
{
   return wektor;
}

template<class TYP, int ROZMIAR>
void UkladRownanLiniowych<TYP,ROZMIAR>::setwektor(const Wektor<TYP,ROZMIAR> & W)
{
  this->wektor = W;
}

template<class TYP, int ROZMIAR>
const Macierz<TYP,ROZMIAR> & UkladRownanLiniowych<TYP,ROZMIAR>::getmacierz() const
{
  return macierz;
}

template<class TYP, int ROZMIAR>
void UkladRownanLiniowych<TYP,ROZMIAR>::setmacierz(const Macierz<TYP,ROZMIAR> & M)
{
  this->macierz = M;
}

//************Metody: Rozwiaz************//
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> UkladRownanLiniowych<TYP,ROZMIAR>::rozwiaz(MetodaUkladu metoda) const
{
  Macierz<TYP,ROZMIAR> tempM2(this->macierz);
  Wektor<TYP,ROZMIAR> wynik;
  Wektor<TYP,ROZMIAR> tempW2(wektor);
  TYP wyznacznik = tempM2.Wyznacznik();
  switch (metoda){
  case cramer:
    for (int i = 0; i < ROZMIAR; i++)
    {
      tempM2[i] = wektor;
      wynik[i] = tempM2.Wyznacznik();
      tempM2[i] = macierz[i];
    }

    if (wyznacznik != 0)
    {
      for (int i = 0; i < ROZMIAR; i++)
      {
        wynik[i] = wynik[i]/wyznacznik;
      }
      return wynik;
    }
    //else if (WX !=0 || WY != 0 || WZ != 0) std::cerr << "Uklad sprzeczny" << std::endl;
    else throw THROWNOANSWER;
  break;
  case gaussjordan:
    tempM2 = tempM2.transponuj();

    for (int i = 0; i < ROZMIAR-1; i++)
    {
      //podmienianie  
      bool flag = false;
      int j = i;        
      while (!flag && j < ROZMIAR)
      {
        if (tempM2[i][j] != 0)
        {
          if (i != j) 
          {
            tempM2 = tempM2.SwapLineVertical(i, j); //praca na macierzy tranponowanej, dlatego nie jest SwapLineHorizontal (tak jak by wynikalo na logike)
            tempW2 = tempW2.Swap(i,j);
          }
          flag = true;
        }
        j++;
      }
      //wyznacznik 0, bo nie da się podzielic i zostaly same zera
      if (!flag) throw THROWNOANSWER;

      //odejmowanie, aby powstala macierz trojkatna
      for (int k = i+1; k < ROZMIAR; k++)
      {
        tempW2[k] = tempW2[k] - tempW2[i] * tempM2[k][i] / tempM2[i][i];	
        tempM2[k] = tempM2[k] - tempM2[i] * tempM2[k][i] / tempM2[i][i]; 
      }
    }
    
    //sprawdzanie czy ostatni element ostatniego wiersza nie jest rowny 0, co oznaczaloby, ze caly ostatni wiersz jest 0
    if (tempM2[ROZMIAR-1][ROZMIAR-1] == 0) throw THROWNOANSWER;
    
    for (int i = ROZMIAR-1; i > 0; i--)
    {
      //odejmowanie, aby powstala macierz diagonalna
      for (int k = i-1; k >= 0; k--)
      {
        tempW2[k] = tempW2[k] - tempW2[i] * tempM2[k][i] / tempM2[i][i];	
        tempM2[k] = tempM2[k] - tempM2[i] * tempM2[k][i] / tempM2[i][i]; 
      }
    }
    
    //*****Rozwiazanie*****//
    for (int i = 0; i < ROZMIAR; i++)
    {
      wynik[i] = tempW2[i]/tempM2[i][i]; 
    }
    return wynik;
  break;
  case odwrotna:
    tempM2 = tempM2.odwroc();
    wynik = tempM2 * wektor;
  return wynik;
  break;
  }
  std::cerr << ERROROUTOFENUM << std::endl;
  exit(0);
}


//************Funkcje: in/out************//
template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP,ROZMIAR> &UklRown)
{
  Wektor<TYP,ROZMIAR> tempW;
  Macierz<TYP,ROZMIAR> tempM;
  Strm >> tempM >> tempW;
  UklRown.setmacierz(tempM);
  UklRown.setwektor(tempW);
  return Strm; 
}

template<class TYP, int ROZMIAR>
std::ostream& operator << ( std::ostream &Strm,  const UkladRownanLiniowych<TYP,ROZMIAR> &UklRown)
{
  Macierz<TYP,ROZMIAR> tempM(UklRown.getmacierz().transponuj());
  
  for (int i = 0; i < ROZMIAR; i++)
  Strm <<  " |" << tempM[i] << "| " << " |x_" << i+1 << "|"<< std::setw(2) << (i==1?'=':' ') << std::setw(2) << "|" << std::setw(SKIP) << UklRown.getwektor()[i] << "|" << std::endl;
  return Strm; 
}
