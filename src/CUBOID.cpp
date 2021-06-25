#include "CUBOID.hh"

CUBOID::CUBOID(Wektor3D center, double x,double y, double z,std::string name)
{
    double tab[]={x,y,z};
    dim=std::make_shared<Wektor3D> (tab);
    this->name=name;
  this->center=center;
  Wektor3D point;

  point[0]=center[0]-(x/2);
  point[1]=center[1]+(y/2);
  point[2]=center[2]+(z/2);
  vertex.push_back(point);

  point[0]=center[0]-(x/2);
  point[1]=center[1]+(y/2);
  point[2]=center[2]-(z/2);
  vertex.push_back(point);


  point[0]=center[0]+(x/2);
  point[1]=center[1]+(y/2);
  point[2]=center[2]+(z/2);
  vertex.push_back(point);

  point[0]=center[0]+(x/2);
  point[1]=center[1]+(y/2);
  point[2]=center[2]-(z/2);
  vertex.push_back(point);

   point[0]=center[0]+(x/2);
  point[1]=center[1]-(y/2);
  point[2]=center[2]+(z/2);
  vertex.push_back(point);

  point[0]=center[0]+(x/2);
  point[1]=center[1]-(y/2);
  point[2]=center[2]-(z/2);
  vertex.push_back(point);


  point[0]=center[0]-(x/2);
  point[1]=center[1]-(y/2);
  point[2]=center[2]+(z/2);
  vertex.push_back(point);

  point[0]=center[0]-(x/2);
  point[1]=center[1]-(y/2);
  point[2]=center[2]-(z/2);
  vertex.push_back(point);

}

CUBOID::CUBOID( CUBOID& pr )
{
   dim=pr.dim;
 vertex=pr.vertex;
  center=pr.center;
  name=pr.name;
}