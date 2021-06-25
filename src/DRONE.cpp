
#include "DRONE.hh"

DRONE::DRONE(int id, PzG::LaczeDoGNUPlota &Lacze, Wektor3D position) : Lacze(Lacze)
{
    angle = 0;
    this->id = id;

    orginal.set_name("../datasets/korpus" + std::to_string(id) + ".dat");

    for (int i = 0; i < 4; i++)
        org_wir[i].set_name("../datasets/wirnik" + std::to_string(i) + std::to_string(id) + ".dat");

    Lacze.DodajNazwePliku(orginal.get_name().c_str());
    for (int i = 0; i < 4; i++)
        Lacze.DodajNazwePliku(org_wir[i].get_name().c_str());
    kopia = orginal;
    range_ = kopia.range();
    kopia.move(position);
    for (int i = 0; i < 4; i++)
        kopia_wir[i] = org_wir[i];

    for (int i = 0; i < 4; i++)
        kopia_wir[i].move(orginal[i * 2] + position);

    this->path = this->path + position;
}

void DRONE::up(double path)
{
    Wektor3D path_o;
    path_o[2] = path;

    this->path = this->path + path_o;
    kopia.translacja(obr);
    kopia.move(this->path);
}

void DRONE::move(double path)
{
    Wektor3D path_o;
    path_o[0] = path * cos(angle * M_PI / 180);
    path_o[1] = path * sin(angle * M_PI / 180);
    this->path = this->path + path_o;
    kopia.translacja(obr);
    kopia.move(this->path);
}

void DRONE::rotate(double angle)
{
    this->angle += angle;
    Macierz3x3 new1;
    obr = new1 * mac_obr_z(this->angle);
    kopia.translacja(obr);
    kopia.move(this->path);
}
void DRONE::rotater()
{
    static int angle = 0;
    angle += 3;
    if (angle == 360)
        angle = 0;

    Macierz3x3 new1, new2;

    for (int i = 0; i < 4; i++)
    {
        if ((i + 1) % 2 == 0)
        {
            new1 = new1 * mac_obr_z(angle);
            kopia_wir[i].translacja(new1);
        }
        else
        {
            new2 = new2 * mac_obr_z(-angle);
            kopia_wir[i].translacja(new2);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        kopia_wir[i].move(kopia[i * 2]);
    }
}

void DRONE::zapisz()
{
    kopia.zapisz();
    for (int i = 0; i < 4; i++)
        kopia_wir[i].zapisz();
}

void DRONE::control(std::list<std::shared_ptr<StageObj>> &elemetnslist)
{
    double path;
    double angle;
    char option;

    zapisz();
    cout << "Options :";
    cin >> option;
    switch (option)
    {
    case 'p':
    {
        cout << "INPUT THE DESIRED PATH :";
        cin >> path;
        set_path(path);
        Lacze.DodajNazwePliku("../datasets/path.dat");
        for (int i = 0; i < 100; i++)
        {
            kopia = orginal;
            for (int j = 0; j < 4; j++)
                kopia_wir[j] = org_wir[j];
            up(1);
            rotater();
            zapisz();
            Lacze.Rysuj();
            usleep(TIME);
        }
        bool coli = false;
        while (1)
        {

            for (int i = 0; i < path; i++)
            {
                kopia = orginal;
                for (int j = 0; j < 4; j++)
                    kopia_wir[j] = org_wir[j];
                move(1);
                rotater();
                zapisz();
                Lacze.Rysuj();
                usleep(TIME);
            }

            for (std::list<std::shared_ptr<StageObj>>::const_iterator a = elemetnslist.begin(); a != elemetnslist.end(); a++)
            {
                kopia = orginal;
                up(-100);
                if (colisioncheck(*a))
                {
                    cout << (*a)->get_name() << endl;
                    coli = true;
                }
                kopia = orginal;
                up(100);
            }

            if (!coli)
            {
                break;
            }
            coli = false;
            path = 40;
            set_path(path);
        }
        for (int i = 0; i < 100; i++)
        {
            kopia = orginal;
            for (int j = 0; j < 4; j++)
                kopia_wir[j] = org_wir[j];
            up(-1);
            rotater();
            zapisz();
            Lacze.Rysuj();
            usleep(TIME);
        }
        Lacze.UsunNazwePliku("../datasets/path.dat");
    }
    break;
    case 'o':
        cout << "INPUT THE DESIRED ANGLE :";
        cin >> angle;
        if (angle > 0)
        {
            for (int i = 0; i < angle; i++)
            {
                kopia = orginal;
                for (int i = 0; i < 4; i++)
                    kopia_wir[i] = org_wir[i];
                rotate(1);
                rotater();
                zapisz();
                Lacze.Rysuj();
                usleep(TIME);
            }
        }
        else
        {
            for (int i = 0; i > angle; i--)
            {
                kopia = orginal;
                rotate(-1);
                rotater();
                zapisz();
                Lacze.Rysuj();
                usleep(TIME);
            }
        }

        break;
    default:
        break;
    }
}
Wektor3D DRONE::get_center() const
{
    return kopia.get_center();
}
bool DRONE::colisioncheck(shared_ptr<StageObj> ob)
{
    std::shared_ptr<DRONE> self = shared_from_this();

    if (ob != self)
    {

        Wektor3D DRONE_CENTER = kopia.get_center();
        Wektor3D OBJ_CENTER = ob->get_center();
        double l = sqrt(pow(DRONE_CENTER[0] - OBJ_CENTER[0], 2) + pow(DRONE_CENTER[1] - OBJ_CENTER[1], 2) + pow(DRONE_CENTER[2] - OBJ_CENTER[2], 2));
        if (range_ + ob->range() >= l)
        {
            return true;
        }
    }
    return false;
}

void DRONE::set_path(double path)
{
    Wektor3D next = kopia.get_center();
    next[2] = 0;
    pathing.push_back(next);
    next[2] = 100;
    pathing.push_back(next);
    next[0] += path * cos(angle * M_PI / 180);
    next[1] += path * sin(angle * M_PI / 180);
    pathing.push_back(next);
    next[2] = 0;
    pathing.push_back(next);

    std::fstream plik;

    plik.open("../datasets/path.dat", std::ios::out);
    for (int i = 0; i < (int)pathing.size(); i++)
    {

        plik << pathing[i] << std::endl;
    }
    plik.close();
}

void DRONE::usun()
{
    Lacze.UsunNazwePliku(orginal.get_name().c_str());
    for (int i = 0; i < 4; i++)
        Lacze.UsunNazwePliku(org_wir[i].get_name().c_str());
}