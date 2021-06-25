#ifndef StageObj_HH
#define StageObj_HH
#include  <string>
#include <memory>


class StageObj
{

public:

virtual bool colisioncheck(shared_ptr <StageObj> ob)=0;
virtual std::string get_name() const=0;
virtual void zapisz()=0;
virtual Wektor3D get_center() const=0;
virtual double range()=0;
};





#endif
