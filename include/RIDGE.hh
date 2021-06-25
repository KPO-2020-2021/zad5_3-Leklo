#ifndef RIDGE_HH
#define RIDGE_HH

#include "BLOCK.hh"

class RIDGE : public BLOCK
{

public:

RIDGE(Wektor3D center=Wektor3D(), double x=50,double y=50, double z=50,std::string name="../datasets/RIDGE.dat");
RIDGE( RIDGE& pr );
 RIDGE &operator=(const RIDGE &other)
    {
     dim=other.dim;
 vertex=other.vertex;
  center=other.center;
  name=other.name;
        return *this;
    }
};







#endif 