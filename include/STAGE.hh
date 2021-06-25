#ifndef STAGE_HH
#define STAGE_HH
#include <iostream>
#include <iomanip>
#include <memory>
#include <fstream>
#include <list>
#include "PLATEAU.hh"
#include "RIDGE.hh"
#include "HILL.hh"
#include "PRISM.hh"
#include "lacze_do_gnuplota.hh"
#include "DRONE.hh"
#include "PLANE.hh"
#include "StageObj.hh"

#define N 2

class STAGE
{
    std::list<std::shared_ptr<StageObj>> elemetnslist;
    PzG::LaczeDoGNUPlota Lacze;
    std::list<std::shared_ptr<DRONE>> dronelist; /// element fazy3
    int elementnumber;
    int dronenumber;
    PLANE *depth;

public:
    STAGE();
    void rysuj();
    bool interfejs();
    ~STAGE();
};

#endif
