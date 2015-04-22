#ifndef FIELD_H
#define FIELD_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Field{
   public:
       Field();
       bool isHit();
       void setHit(bool x);
       int getId();
       void setId(int x);
       static void createShip(int x1, int y1, int x2, int y2, vector <vector <Field> > &f);
       static void printSea(vector <vector <Field> > &f);
       static void createShipRandom(int size, vector <vector <Field> > &f);
       static bool fieldBusy(int x1, int y1, int x2, int y2, vector <vector <Field> > &f);

   private:
       bool hit;
       int id; // Polje ima id razlicit od 0 samo ako je to polje Brod
};

#endif
