#ifndef BLOCK_HH
#define BLOCK_HH

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <fstream>
#include <vector>
#include <memory>
#include "StageObj.hh"
class BLOCK:public StageObj, public std::enable_shared_from_this< BLOCK >
{
 protected:
 
  std::shared_ptr<Wektor3D> dim;
 std::vector<Wektor3D> vertex;
 Wektor3D center;
 std::string name;
 public:
 bool colisioncheck(shared_ptr <StageObj> ob);
  double range(){return sqrt(pow(center[0]-vertex[0][0],2) + pow(center[1]-vertex[0][1],2)+pow(center[2]-vertex[0][2],2));}
  Wektor3D &operator[](int index);
  Wektor3D operator[](int index)const;

 void set_center(Wektor3D center);
 void set_name(std::string name);
 Wektor3D get_center() const;
 std::string get_name() const;

 void move(Wektor3D mv);
 void translacja(Macierz3x3 obr);

 void zapisz();

};





#endif
