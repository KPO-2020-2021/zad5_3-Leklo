#include "PLANE.hh"

// x 600, y 600 ,z 0
PLANE::PLANE(Wektor3D dim, int density, std::string name)
{
    this->name = name;
    double tab[3];
    licz_prostych=0;
    for (int i = -dim[0] / 2; i < dim[0] / 2; i += density)
    {
        for (int j = -dim[1] / 2; j < dim[1] / 2; j += density)
        {
            tab[0] = i;
            tab[1] = j;

            vertex.push_back(tab);
        }
        licz_prostych++;
    }
}
Wektor3D &PLANE::operator[](int index)
{
    return vertex[index];
}
Wektor3D PLANE::operator[](int index) const
{
    return vertex[index];
}

void PLANE::set_name(std::string name)
{
    this->name = name;
}

std::string PLANE::get_name() const
{
    return name;
}

void PLANE::zapisz()
{
      std::fstream plik;

    plik.open(name, std::ios::out);
 for (int i = 0; i < (int)vertex.size(); i ++)
 {
   if(i%licz_prostych==0)
   plik<<std::endl;
   plik<<vertex[i]<<std::endl;
 }
   
    plik.close();
}