#ifndef PLANE_HH
#define PLANE_HH

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <fstream>
#include <vector>

class PLANE
{
protected:
    std::vector<Wektor3D> vertex;
    std::string name;
   int licz_prostych;
public:
    PLANE(Wektor3D dim=Wektor3D(),int density=10, std::string name="../datasets/PLANE");

    Wektor3D &operator[](int index);
    Wektor3D operator[](int index) const;

    void set_name(std::string name);
    std::string get_name() const;

    void zapisz();
};

#endif