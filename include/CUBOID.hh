#ifndef CUBOID_HH
#define CUBOID_HH

#include "BLOCK.hh"

class CUBOID : public BLOCK
{

public:

CUBOID(Wektor3D center=Wektor3D(), double x=50,double y=50, double z=50,std::string name="../datasets/CUBOID.dat");
CUBOID( CUBOID& pr );
   CUBOID &operator=(const CUBOID &other)
    {
     dim=other.dim;
 vertex=other.vertex;
  center=other.center;
  name=other.name;
        return *this;
    }
};







#endif 