#include "STAGE.hh"

STAGE::STAGE()
{

  Lacze.ZmienTrybRys(PzG::TR_3D);
  elementnumber = 0;
  dronenumber = 0;
  Lacze.UstawZakresY(-300, 300);
  Lacze.UstawZakresX(-300, 300);
  Lacze.UstawZakresZ(-300, 300);

  double tab_wym[3] = {600, 600, 0};
  Wektor3D wym_dna(tab_wym);
  depth = new PLANE(wym_dna, 20);
  Wektor3D cen;
  bool coli = false;
  for (int i = 0; i < 4; i++)
  {
  
    cen[0] = rand() % 400 - 200;
    cen[1] = rand() % 400 - 200;
    cen[2] = 50;
    int nr_p = rand() % 3;
    if (nr_p == 0)
      elemetnslist.push_front(std::make_shared<HILL>(cen, 100, 50, 100, "../datasets/Element" + std::to_string(elementnumber) + ".dat"));
    else if (nr_p == 1)
      elemetnslist.push_front(std::make_shared<PLATEAU>(cen, 100, 50, 100, "../datasets/Element" + std::to_string(elementnumber) + ".dat"));
    else if (nr_p == 2)
      elemetnslist.push_front(std::make_shared<RIDGE>(cen, 100, 50, 100, "../datasets/Element" + std::to_string(elementnumber) + ".dat"));
    elementnumber++;
    for (std::list<std::shared_ptr<StageObj>>::const_iterator a = elemetnslist.begin(); a != elemetnslist.end(); a++)
    {
      if ((*elemetnslist.begin())->colisioncheck(*a))
      {
        coli = true;
      }
    }
    if (coli)
    {
      i--;
      elemetnslist.erase(elemetnslist.begin());
    }
    coli = false;
  }
  for (std::list<std::shared_ptr<StageObj>>::const_iterator a = elemetnslist.begin(); a != elemetnslist.end(); a++)
  {
    Lacze.DodajNazwePliku((*a)->get_name().c_str());
    (*a)->zapisz();
    cout << (*a)->get_name() << " " << (*a)->range() << endl;
  }

  Lacze.DodajNazwePliku(depth->get_name().c_str());
  depth->zapisz();
  coli = false;
  for (int i = 0; i < N; i++)
  {
    double position[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};

    dronelist.push_front(std::make_shared<DRONE>(i, Lacze, Wektor3D(position)));

    for (std::list<std::shared_ptr<StageObj>>::const_iterator a = elemetnslist.begin(); a != elemetnslist.end(); a++)
    {
      if ((*dronelist.begin())->colisioncheck(*a))
      {
        coli = true;
      }
    }
    if (coli)
    {
      i--;
      dronelist.erase(dronelist.begin());
    }
    else
    {
      elemetnslist.push_front(*dronelist.begin());
      cout << (*dronelist.begin())->get_name() << " " << (*dronelist.begin())->range() << endl;
      (*dronelist.begin())->zapisz();
      dronenumber++;
    }
    coli = false;
  }

  Lacze.Rysuj();
}
void STAGE::rysuj()
{

  Lacze.Rysuj();
}
bool STAGE::interfejs()
{
  cout << "INPUT 1 FOR THE LIST OF DRONES 2 TO CREATE A NEW OBJECT 3 TO REMOVE AN OBJECT 4 TO REMOVE A DRONE" << endl;
  int option;
  cin >> option;
  switch (option)
  {
  case 1:
  {
    cout << "INPUT THE NUMBER " << endl;
    for (int i = 0; i < (int)dronelist.size(); i++)
    {
      cout << i << " ";
    }
    cout << ":" << endl;
    int nr;
    cin >> nr;
    std::list<std::shared_ptr<DRONE>>::const_iterator a;
    a = dronelist.begin();
    for (int i = 0; i < nr; i++)
    {
      a++;
    }

    (*a)->control(elemetnslist);
  }
  break;
  case 2:
  {
    cout << "Choose between 1. HILL 2. PLATEAU 3. RIDGE 4.DRONE" << endl;

    int nr;
    cin >> nr;
    Wektor3D cen;

    if (nr != 4)
    {
      for (int i = 0; i < 50; i++)
      {
        cen[0] = rand() % 400 - 200;
        cen[1] = rand() % 400 - 200;
        cen[2] = 50;
        bool coli = false;
        if (nr == 1)
        {

          elemetnslist.push_front(std::make_shared<HILL>(cen, 100, 50, 100, "../datasets/Element" + std::to_string(elementnumber) + ".dat"));
        }
        if (nr == 2)
        {

          elemetnslist.push_front(std::make_shared<PLATEAU>(cen, 100, 50, 100, "../datasets/Element" + std::to_string(elementnumber) + ".dat"));
        }
        if (nr == 3)
        {

          elemetnslist.push_front(std::make_shared<RIDGE>(cen, 100, 50, 100, "../datasets/Element" + std::to_string(elementnumber) + ".dat"));
        }

        elementnumber++;
        for (std::list<std::shared_ptr<StageObj>>::const_iterator a = elemetnslist.begin(); a != elemetnslist.end(); a++)
        {
          if ((*elemetnslist.begin())->colisioncheck(*a))
          {
            coli = true;
          }
        }
        if (coli)
        {
          i--;
          elemetnslist.erase(elemetnslist.begin());
        }
        else
        {
          break;
        }
      }
      (*elemetnslist.begin())->zapisz();
      Lacze.DodajNazwePliku((*elemetnslist.begin())->get_name().c_str());
    }
    else
    {
      bool coli = false;
      for (int i = 0; i < 50; i++)
      {
        double position[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};

        dronelist.push_front(std::make_shared<DRONE>(dronenumber, Lacze, Wektor3D(position)));

        for (std::list<std::shared_ptr<StageObj>>::const_iterator a = elemetnslist.begin(); a != elemetnslist.end(); a++)
        {
          if ((*dronelist.begin())->colisioncheck(*a))
          {
            coli = true;
          }
        }
        if (coli)
        {

          dronelist.erase(dronelist.begin());
        }
        else
        {
          elemetnslist.push_front(*dronelist.begin());
          cout << (*dronelist.begin())->get_name() << " " << (*dronelist.begin())->range() << endl;
          (*dronelist.begin())->zapisz();
          dronenumber++;
          break;
        }
        coli = false;
      }
    }
  }

  break;
  case 3:
  {
    int i = 0;
    for (std::list<std::shared_ptr<StageObj>>::const_iterator a = elemetnslist.begin(); a != elemetnslist.end(); a++)
    {
      cout << i << ": " << (*a)->get_name() << endl;
      i++;
    }
    cout << "INPUT THE NUMBER" << endl;

    int nr;
    cin >> nr;
    std::list<std::shared_ptr<StageObj>>::const_iterator a = elemetnslist.begin();

    for (int j = 0; j < nr; j++)
    {

      a++;
    }

    Lacze.UsunNazwePliku((*a)->get_name());
    elemetnslist.erase(a);
  }
  break;
    ////faza 3 dla niektórych///
  case 4:
  {
    int i = 0;
    for (std::list<std::shared_ptr<DRONE>>::const_iterator a = dronelist.begin(); a != dronelist.end(); a++)
    {
      cout << i << ": " << (*a)->get_id() << endl;
      i++;
    }
    cout << "INPUT THE NUMBER" << endl;

    int nr;
    cin >> nr;
    std::list<std::shared_ptr<DRONE>>::const_iterator a = dronelist.begin();

    for (int j = 0; j < nr; j++)
    {

      a++;
    }

    (*a)->usun();

    for (std::list<std::shared_ptr<StageObj>>::const_iterator b = elemetnslist.begin(); b != elemetnslist.end(); b++)
    {
      if (*a == *b)
      {
        elemetnslist.erase(b);
      }
    }
    dronelist.erase(a);
  }
  break;

  default:
    break;
  }

  return true;
}

STAGE::~STAGE()
{
  free(depth);
}