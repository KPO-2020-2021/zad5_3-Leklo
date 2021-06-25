#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cmath>
using namespace std;

template <int Dimension>
class Wektor
{
    static int wszystkie;
    static int aktualne;
    double _wsp[Dimension];

public:
    Wektor();
    Wektor(Wektor<Dimension> &wek)
    {
        for (int i = 0; i < Dimension; i++)
            _wsp[i] = wek._wsp[i];

        aktualne++;
    }
    constexpr Wektor(const Wektor &other)
    {
        for (int i = 0; i < Dimension; i++)
            _wsp[i] = other._wsp[i];
        aktualne++;
    }
    Wektor &operator=(const Wektor &other)
    {
        for (int i = 0; i < Dimension; i++)
            _wsp[i] = other._wsp[i];
        return *this;
    }

    Wektor &operator=(const float &other)
    {
        for (int i = 0; i < Dimension; i++)
            _wsp[i] = other;
        return *this;
    }
    ~Wektor();
    Wektor(double _wsp[Dimension]);
    double operator[](int index) const;
    double &operator[](int index);
    Wektor<Dimension> operator+(Wektor<Dimension> &arg);
    Wektor<Dimension> operator-(Wektor<Dimension> &arg);
    void informacje();
};

template <int Dimension>
 int Wektor<Dimension>::wszystkie = 0;

template <int Dimension>
 int Wektor<Dimension>::aktualne = 0;

template <int Dimension>
void Wektor<Dimension>::informacje()
{
    cout << "akturalne obiekty: " << aktualne << endl;
    cout << "wszystkie obiekty: " << wszystkie << endl;
}

template <int Dimension>
Wektor<Dimension>::Wektor()
{
    for (int i = 0; i < Dimension; i++)
        _wsp[i] = 0;
    aktualne++;
    wszystkie++;
}

template <int Dimension>
Wektor<Dimension>::Wektor(double _wsp[Dimension])
{
    for (int i = 0; i < Dimension; i++)
        this->_wsp[i] = _wsp[i];
    aktualne++;
    wszystkie++;
}

template <int Dimension>
Wektor<Dimension>::~Wektor()
{
    aktualne--;
}

template <int Dimension>
double Wektor<Dimension>::operator[](int index) const
{
    if (index > Dimension || index < 0)
    {
        std::cerr << "Indeks poza skala" << std::endl;
        exit(1);
    }
    return _wsp[index];
}

template <int Dimension>
double &Wektor<Dimension>::operator[](int index)
{
    if (index > Dimension || index < 0)
    {
        std::cerr << "Indeks poza skala" << std::endl;
        exit(1);
    }
    return _wsp[index];
}

template <int Dimension>
Wektor<Dimension> Wektor<Dimension>::operator+(Wektor<Dimension> &arg)
{
    Wektor<Dimension> Wynik;
    for (int i = 0; i < Dimension; i++)
    {
        Wynik[i] = _wsp[i] + arg[i];
    }
    return Wynik;
}

template <int Dimension>
Wektor<Dimension> Wektor<Dimension>::operator-(Wektor<Dimension> &arg)
{
    Wektor<Dimension> Wynik;
    for (int i = 0; i < Dimension; i++)
    {
        Wynik[i] = _wsp[i] - arg[i];
    }
    return Wynik;
}

template <int Dimension>
std::istream &operator>>(std::istream &Strm, Wektor<Dimension> &Wek)
{
    for (int i = 0; i < Dimension; i++)
    {
        Strm >> Wek[i];
    }
    return Strm;
    return Strm;
}

template <int Dimension>
inline std::ostream &operator<<(std::ostream &Strm, const Wektor<Dimension> &Wek)
{
    for (int i = 0; i < Dimension; i++)
    {
        Strm << Wek[i] << " ";
    }
    return Strm;
}

#endif
