#include <iostream>
#include <iomanip>
#include "Wektor.hh"
#include "Macierz.hh"
#include "LZespolona.hh"
#include "UkladRownanLiniowych.hh"
//#include "rozmiar.h"


int main()
{
  UkladRownanLiniowych<LZespolona,5> UklRown;
  Wektor<LZespolona,5> Wynik; bool ErrorWynik = false; Wektor<LZespolona,5> Blad;

  std::cout << std::endl; 
  std::cin >> UklRown;
  if (!std::cin.good()){std::cerr<<ERRORLOAD<<std::endl<<std::endl; exit(0);}

  //std::cout << "Macierz A^T:" << std::endl; 
  //std::cout << UklRown.getmacierz().transponuj() << std::endl;
  //std::cout << "Macierz A:" << std::endl; 
  //std::cout << UklRown.getmacierz()<< std::endl;
  //std::cout << "Wektor B:" << std::endl; 
  //std::cout << UklRown.getwektor()<< std::endl;
  
  std::cout << std::endl;
  std::cout << "Wyznacznik - Gauss:\t"   << UklRown.getmacierz().Wyznacznik()   << std::endl;
  
  std::cout << std::endl;
  std::cout << "Uklad rownan" << std::endl << UklRown << std::endl<< std::endl;
  
  //Cramer
  try 
  {
     Wynik = UklRown.rozwiaz(cramer);
     ErrorWynik = false;
  }
  catch (int Error)
  {
    std::cout << "Cramer: " <<ERRORNOANSWER << std::endl;
    ErrorWynik = true;
  }
  if (!ErrorWynik)
  {
    Blad = UklRown.getmacierz() * Wynik - UklRown.getwektor();
    std::cout << "Rozwiazanie X1 X2 X3 - Cramer:" << std::endl << Wynik << std::endl;
    std::cout << "Wektor bledu - Cramer:" << std::endl << Blad << std::endl;
    std::cout << "Dlugosc wektor bledu - Cramer:" << std::endl << Blad.dlugosc() << std::endl<< std::endl;
    std::cout << std::endl;
  }

  //Gauss-Jordan
  try 
  {
     Wynik = UklRown.rozwiaz(gaussjordan);
     ErrorWynik = false;
  }
  catch (int Error)
  {
    std::cout << "Gauss-Jordan: "<< ERRORNOANSWER << std::endl;
    ErrorWynik = true;
  }
  if (!ErrorWynik)
  {
    Blad = UklRown.getmacierz() * Wynik - UklRown.getwektor();
    std::cout << "Rozwiazanie X1 X2 X3 - Gauss:" << std::endl << Wynik << std::endl;
    std::cout << "Wektor bledu - Gauss:" << std::endl << Blad << std::endl;
    std::cout << "Dlugosc wektor bledu - Gauss:" << std::endl << Blad.dlugosc() << std::endl;
    std::cout << std::endl<< std::endl;
  }

  //Macierz odwrotna
  try 
  {
     Wynik = UklRown.rozwiaz(odwrotna);
     ErrorWynik = false;
  }
  catch (int Error)
  {
    std::cout << "Macierz odwrotna: "<< ERRORNOANSWER << std::endl;
    ErrorWynik = true;
  }
  if (!ErrorWynik)
  {
    Blad = UklRown.getmacierz() * Wynik - UklRown.getwektor();
    std::cout << "Rozwiazanie X1 X2 X3 - Macierz odwrotna:" << std::endl << Wynik << std::endl;
    std::cout << "Wektor bledu - Macierz odwrotna:" << std::endl << Blad << std::endl;
    std::cout << "Dlugosc wektor bledu - Macierz odwrotna:" << std::endl << Blad.dlugosc() << std::endl<< std::endl;
  }

  UkladRownanLiniowych<double,5> UklRown2;
  Wektor<double,5> Wynik2; bool ErrorWynik2 = false; Wektor<double,5> Blad2;

  std::cout << std::endl; 
  std::cin >> UklRown2;
  if (!std::cin.good()){std::cerr<<ERRORLOAD<<std::endl<<std::endl; exit(0);}

  //std::cout << "Macierz A^T:" << std::endl; 
  //std::cout << UklRown2.getmacierz().transponuj() << std::endl;
  //std::cout << "Macierz A:" << std::endl; 
  //std::cout << UklRown2.getmacierz()<< std::endl;
  //std::cout << "Wektor B:" << std::endl; 
  //std::cout << UklRown2.getwektor()<< std::endl;
  
  std::cout << std::endl;
  std::cout << "Wyznacznik - Gauss:\t"   << UklRown2.getmacierz().Wyznacznik()   << std::endl;
  
  std::cout << std::endl;
  std::cout << "Uklad rownan" << std::endl << UklRown2 << std::endl<< std::endl;
  
  //Cramer
  try 
  {
     Wynik2 = UklRown2.rozwiaz(cramer);
     ErrorWynik2 = false;
  }
  catch (int Error)
  {
    std::cout << "Cramer: " <<ERRORNOANSWER << std::endl;
    ErrorWynik2 = true;
  }
  if (!ErrorWynik2)
  {
    Blad2 = UklRown2.getmacierz() * Wynik2 - UklRown2.getwektor();
    std::cout << "Rozwiazanie X1 X2 X3 - Cramer:" << std::endl << Wynik2 << std::endl;
    std::cout << "Wektor bledu - Cramer:" << std::endl << Blad2 << std::endl;
    std::cout << "Dlugosc wektor bledu - Cramer:" << std::endl << Blad2.dlugosc() << std::endl<< std::endl;
    std::cout << std::endl;
  }

  //Gauss-Jordan
  try 
  {
     Wynik2 = UklRown2.rozwiaz(gaussjordan);
     ErrorWynik2 = false;
  }
  catch (int Error)
  {
    std::cout << "Gauss-Jordan: "<< ERRORNOANSWER << std::endl;
    ErrorWynik2 = true;
  }
  if (!ErrorWynik2)
  {
    Blad2 = UklRown2.getmacierz() * Wynik2 - UklRown2.getwektor();
    std::cout << "Rozwiazanie X1 X2 X3 - Gauss:" << std::endl << Wynik2 << std::endl;
    std::cout << "Wektor bledu - Gauss:" << std::endl << Blad2 << std::endl;
    std::cout << "Dlugosc wektor bledu - Gauss:" << std::endl << Blad2.dlugosc() << std::endl;
    std::cout << std::endl<< std::endl;
  }

  //Macierz odwrotna
  try 
  {
     Wynik2 = UklRown2.rozwiaz(odwrotna);
     ErrorWynik2 = false;
  }
  catch (int Error)
  {
    std::cout << "Macierz odwrotna: "<< ERRORNOANSWER << std::endl;
    ErrorWynik2 = true;
  }
  if (!ErrorWynik2)
  {
    Blad2 = UklRown2.getmacierz() * Wynik2 - UklRown2.getwektor();
    std::cout << "Rozwiazanie X1 X2 X3 - Macierz odwrotna:" << std::endl << Wynik2 << std::endl;
    std::cout << "Wektor bledu - Macierz odwrotna:" << std::endl << Blad2 << std::endl;
    std::cout << "Dlugosc wektor bledu - Macierz odwrotna:" << std::endl << Blad2.dlugosc() << std::endl<< std::endl;
  }
}
