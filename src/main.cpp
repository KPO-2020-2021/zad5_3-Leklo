#include "STAGE.hh"

using namespace std;

int main()
{
     srand(time(NULL));
     Wektor3D wek;
   STAGE s;
   wek.informacje();
       while (s.interfejs())
       {
            s.rysuj();
            wek.informacje();
       }
}
