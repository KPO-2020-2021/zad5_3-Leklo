#ifndef MACIERZ_HH
#define MACIERZ_HH


#include <iostream>
#include "Wektor.hh"
#include <cmath>
using namespace std;

template <int Dimension>
class Macierz{

  double Mac[Dimension][Dimension];
  public:

Macierz();
double operator()(int index_x, int index_y) const;
double &operator()(int index_x, int index_y);
Wektor<Dimension> operator *( Wektor<Dimension> wsp);
Macierz<Dimension> operator *( Macierz<Dimension> wsp);
};

template <int Dimension>
Macierz<Dimension> ::Macierz()
{
  for(int i = 0; i < Dimension; ++i)
  {
    for(int j = 0; j < Dimension; ++j)
    {
      if(i==j)
      {
        Mac[i][j]=1;
      }
      else
      {
        Mac[i][j]=0;
      }
    }
  }
}

template <int Dimension>
double Macierz<Dimension> ::operator()(int index_x, int index_y) const
{
    if (index_x > Dimension|| index_x < 0 || index_y > Dimension || index_y < 0) 
    {
        std::cerr << "Indeks poza skala" << std::endl;
        exit(1);
    }
    return Mac[index_x][index_y];
}

template <int Dimension>
double &Macierz<Dimension> ::operator()(int index_x, int index_y)
{
    if (index_x > Dimension || index_x < 0 || index_y > Dimension || index_y < 0) 
    {
        std::cerr << "Indeks poza skala" << std::endl;
        exit(1);
    }
    return Mac[index_x][index_y];
}

template <int Dimension>
Wektor<Dimension> Macierz<Dimension> ::operator *( Wektor<Dimension> wsp)
{
  Wektor<Dimension> Wynik;

  for(int i = 0; i < Dimension; ++i)
  {
    for(int j = 0; j < Dimension; ++j)
    {
      Wynik[i] += Mac[i][j] * wsp[j];
    }
  }
    return Wynik;
}

template <int Dimension>
Macierz<Dimension> Macierz<Dimension>::operator *( Macierz<Dimension> wsp)
{
  Macierz<Dimension> Wynik;

  for(int i = 0; i < Dimension; ++i)
  {
    for(int j = 0; j < Dimension; ++j)
    {
      Wynik(i,j) =0;
         for(int k = 0; k < Dimension; k++ ) Wynik(i,j) += Mac [ i ][ k ] * wsp(k,j) ;
    }
  }
    return Wynik;
}


template <int Dimension>
inline
std::ostream& operator << (std::ostream &Strm, const Macierz<Dimension> &wsp)
{
   for(int i = 0; i < Dimension; ++i)
  {
    for(int j = 0; j < Dimension; ++j)
    {
     cout<<wsp(i,j)<<" ";
    }
         cout<<endl;
  }
  return Strm;  
}


#endif
