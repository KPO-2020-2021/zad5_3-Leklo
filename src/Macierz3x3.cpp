#include "Macierz3x3.hh"

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz3x3, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

Macierz3x3 mac_obr_x(double angle)
{
    double rad = angle * M_PI / 180;
    Macierz3x3 rotation;
    rotation(0, 0) = 1;
    rotation(0, 1) = 0;
    rotation(0, 2) = 0;

    rotation(1, 0) = 0;
    rotation(1, 1) = cos(rad);
    rotation(1, 2) = -sin(rad);

    rotation(2, 0) = 0;
    rotation(2, 1) = sin(rad);
    rotation(2, 2) = cos(rad);
    return rotation;
}
Macierz3x3 mac_obr_y(double angle)
{
    double rad = angle * M_PI / 180;
    Macierz3x3 rotation;
    rotation(0, 0) = cos(rad);;
    rotation(0, 1) = 0;
    rotation(0, 2) = sin(rad);

    rotation(1, 0) = 0;
    rotation(1, 1) = 1;
    rotation(1, 2) = 0;

    rotation(2, 0) = -sin(rad);
    rotation(2, 1) = 0;
    rotation(2, 2) = cos(rad);
    return rotation;
}
Macierz3x3 mac_obr_z(double angle)
{
    double rad = angle * M_PI / 180;
    Macierz3x3 rotation;
    rotation(0, 0) = cos(rad);;
    rotation(0, 1) = -sin(rad);
    rotation(0, 2) = 0;

    rotation(1, 0) = sin(rad);
    rotation(1, 1) = cos(rad);
    rotation(1, 2) = 0;

    rotation(2, 0) = 0;
    rotation(2, 1) = 0;
    rotation(2, 2) = 1;
    return rotation;
}