#ifndef PLATEAU_HH
#define PLATEAU_HH

#include "BLOCK.hh"

class PLATEAU : public BLOCK
{

public:

PLATEAU(Wektor3D center=Wektor3D(), double x=50,double y=50, double z=50,std::string name="../datasets/PLATEAU.dat");
PLATEAU( PLATEAU& pr );
   PLATEAU &operator=(const PLATEAU &other)
    {
     dim=other.dim;
 vertex=other.vertex;
  center=other.center;
  name=other.name;
        return *this;
    }
};







#endif 