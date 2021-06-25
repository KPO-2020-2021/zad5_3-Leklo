#ifndef PRISM_HH
#define PRISM_HH

#include "BLOCK.hh"

class PRISM : public BLOCK
{
    public:
    PRISM(Wektor3D center=Wektor3D(),double z=10,double range=15,std::string name = "../datasets/PRISM.dat" );
   
};




#endif
