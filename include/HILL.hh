#ifndef HILL_HH
#define HILL_HH

#include "BLOCK.hh"

class HILL : public BLOCK
{

public:
  double range(){return (*dim)[2];}
HILL(Wektor3D center=Wektor3D(), double x=50,double y=50, double z=50,std::string name="../datasets/HILL.dat");
HILL( HILL& pr );
 HILL &operator=(const HILL &other)
    {
     dim=other.dim;
 vertex=other.vertex;
  center=other.center;
  name=other.name;
        return *this;
    }
};







#endif 