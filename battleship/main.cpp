// Potapanje brodova.cpp : main project file.


#include "Polje.h"

#include <iostream>
#include <cstdlib>
#include <array>
#include <vector>

using namespace std;

void swap(int& a, int& b);

int main()
{

   vector <Field> row(8, Field());
   vector <vector <Field> > sea(8, row);
   // Prvobitan izgled
   Field::printSea(sea);





   /*
   // Unos koordinata pocetka i kraja
   cout << "Unesite koordinate pocetka:" << endl;
   cin >> x1 >> y1;
   cout << "Unesite koordinate kraja:" << endl;
   cin >> x2 >> y2;

   // Kreiranje broda
   Field::createShip(x1, y1, x2, y2, sea);

   */
   Field::createShipRandom(4, sea);
   Field::createShipRandom(2, sea);

   int x1, y1, x2, y2;
   // Unos koordinata pocetka i kraja
   cout << "Unesite koordinate pocetka:" << endl;
   cin >> x1 >> y1;
   cout << "Unesite koordinate kraja:" << endl;
   cin >> x2 >> y2;

   // Kreiranje broda
   Field::createShip(x1, y1, x2, y2, sea);



   int x = 0;
   int y = 0;

   // Gadjanje
   for(int i = 1; i < 64; i++)
   {
       cout << endl;
       cout << "Pokusaj " << i << ':' << endl;
       cout << "Ubaci koordinate x i y:" << endl;
       cin >> x >> y;


       if(x > 7 || y > 7)
       {
           cout << "Pogresne koordinate!" << endl;
           system("PAUSE");
           return 0;
       }

       sea[x][y].setHit(true);

       Field::printSea(sea);
       cout << endl;

   }

    system("PAUSE");
    return EXIT_SUCCESS;

}

void swap(int& a, int& b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
