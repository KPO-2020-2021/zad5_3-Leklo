#include "PRISM.hh"

PRISM::PRISM(Wektor3D center, double z, double range , std::string name )
{
    double tab[] = {0, 0, z};
   dim=std::make_shared<Wektor3D> (tab);
    this->name = name;
    this->center = center;
    Wektor3D point;
    for (int i = 0; i < 360; i += 60)
    {
        point[0] = range * cos(i * M_PI / 180);
        point[1] = range * sin(i * M_PI / 180);
        point[2] = center[2] + (z / 2);
        vertex.push_back(point);
        point[0] = range * cos(i * M_PI / 180);
        point[1] = range * sin(i * M_PI / 180);
        point[2] = center[2] - (z / 2);
        vertex.push_back(point);
    }
}