#ifndef DRONE_HH
#define DRONE_HH

#include "CUBOID.hh"
#include "PRISM.hh"
#include "lacze_do_gnuplota.hh"
#include "StageObj.hh"
#include <unistd.h> // biblioteka dla usleep
#define TIME 20000

class DRONE :public StageObj, public std::enable_shared_from_this< DRONE >
{
    double range_;
    std::vector<Wektor3D> pathing;
    PzG::LaczeDoGNUPlota &Lacze;
    CUBOID orginal;
    CUBOID kopia;
    PRISM org_wir[4];
    PRISM kopia_wir[4];
    Macierz3x3 obr;
    Wektor3D path;
    double angle;
    int id; 
public:
double range(){return kopia.range();}
Wektor3D get_center() const;
 bool colisioncheck(shared_ptr <StageObj> ob);
  void usun();
  std::string get_name()const{return "DRONE";}
  int get_id(){return id; }
  DRONE(int id,PzG::LaczeDoGNUPlota &Lacze,Wektor3D position);
  void up(double path);
  void move(double path);
  void rotate(double angle); // kont podajemy w stopniach
  void rotater(); // kont podajemy w stopniach
  void zapisz();
  void control(std::list<std::shared_ptr<StageObj>> &Lista_elementow);
  void set_path(double path);
};

#endif
