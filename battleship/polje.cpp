
#include "Polje.h"

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <ctime>	// Seme za rand()
#include <vector>
#include <Windows.h>

using namespace std;

// Ako se ne stavi u konstruktoru, hit nece biti false podrazumevano
Field::Field()
{
    hit = false;
    id = 0;
}


// getters & setters
bool Field::isHit()
{
    return hit;
}

void Field::setHit(bool x)
{
    hit = x;
}


int Field::getId()
{
    return id;
}

void Field::setId(int x)
{
    id = x;
}

// Kako da izbegnemo unosenje dimenzija matrice?
void Field::createShip(int x1, int y1, int x2, int y2, vector <vector <Field> > &f)
{
    /* Kreiranje broda s datim koordinatama pocetka i kraja */

    // ako x1 > x2 ====> for petlja ima drugaciji uslov (i = x2; i <= x1; i++)
    if((x1 > x2) || (y1 > y2))
    {
        swap(x1, x2);
        swap(y1, y2);
    }

    // Bar jedan par clanova koordinata mora biti isti
    if((x1 != x2) & (y1 != y2))
    {
        cout << "Pogresan unos koordinata!" << endl;
        system("PAUSE");
        // Ovde moze neki exception ili nekako drugacije da se resi
    }

    int i = 0;
    // Kreiranje broda
    if(y1 == y2)
        for(i = x1; i <= x2; i++)
            f[i][y1].setId(1);
    else
        for(i = y1; i <= y2; i++)
            f[x1][i].setId(1);

    cout << "Brod je kreiran!" << endl;
}

// Kreiranje broda zadate velicine na nepoznatim koordinatama
void Field::createShipRandom(int size, vector <vector <Field> > &f)
{
    srand(time(0));

    int x1, x2, y1, y2;
    bool vertical = false;

    if((rand() % 12) > 5)
        vertical = true;


    x1 = ((rand()*150 + 16) * 21 + 3) % 8;
    y1 = ((rand()*150 + 16) * 21 + 3) % 8;

    // Provera da li su koordinate pocetka negde gde mora da bude brod horizontalan/vertikalan
    // Ovo cu veceras da dopunim ;)

    // Random da li ce biti horizontalan ili vertikalan brod
    if(vertical)
    {
        if((x1 + size) > 7)
        {
            x2 = x1 - size + 1;
        }
        else
            x2 = x1 + size - 1;

        y2 = y1;
    }
    else
    {
        if((y1 + size) > 7)
        {
            y2 = y1 - size + 1;
        }
        else
            y2 = y1 + size - 1;

        x2 = x1;
    }
    // Sledeci problem: brod nikad nece biti u malim koordinatama osim ako mu nije pocetak tu???!

    /*
    if(x1 < (rand()%8))
    {
        x2 = x1;
        y2 = y1 + size - 1;
    }
    else
    {
        y2 = y1;
        x2 = x1 + size - 1;
    }
    */
    cout << "Za pocetak da vidimo kako radi:" << endl;
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

    Field::createShip(x1, y1, x2, y2, f);

}


// Crtanje matrice (nakon svakog gadjanja)
void Field::printSea(vector <vector <Field> > &f)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    // Kad se ubace koordinate 7, 7 ostane neka boja aktivna

    for(unsigned int i = 0; i < f.size(); i++)
    {
        for(unsigned int j = 0; j < f[0].size(); j++)
        {

            if(f[i][j].isHit())					// Provera da li je dato Polje pogodjeno
                if(f[i][j].getId() != 0)		// Provera da li je dato Polje zauzeto Brodom
                {
                    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    cout << "x ";
                }
                else
                {
                    SetConsoleTextAttribute(h, FOREGROUND_RED |
                        FOREGROUND_INTENSITY);
                    cout << "x ";
                }
            else
            {
                SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED |
                    FOREGROUND_INTENSITY);
                cout << "o ";
            }
        }
        cout << endl;
    }
    // Ukoliko se unesu koordinate 7, 7 poslednja promena boje moze biti RED ili GREEN
    // Resenje: na kraju uvek vracanje na staro ====>
    SetConsoleTextAttribute(h, FOREGROUND_BLUE |
                FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

}


// NE radi, treba da se zavrsi
//int Field::zauzeto(int x1, int y1, int x2, int y2, vector <vector <Field> > &f);
//{
//      int i1,i2,j1,j2;
//      // Mora da proverimo da li se brod nalazi na ivici mora.  Mora vaziti x1 < x2 i y1 < y2

//      if(x1>x2)
//      {
//          int pom=x1;
//          x1=x2;
//          x2=pom;
//      }

//      if(y1>y2)
//      {
//          int pom=y1;
//          y1=y2;
//          y2=pom;
//      }



//      if(x1-1<0)
//        i1=x1;
//      else i1=x1+1;

//      if(x2+1>7)
//        i2=x2;
//      else i2=x2+1;

//      if(y1-1<0)
//        j1=y1;
//      else j1=y1+1;

//      if(y2+1>7)
//        j2=y2;
//      else j2=y2+1;

//    for(int i1;i<i2;i1++)
//       for(j1;j<j2;j1++)
//        {
//         if(f[i1][j1].getid!=0 )
//             return 1;
//        }


//    return 0;
//}
