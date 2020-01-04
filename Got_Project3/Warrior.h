#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior
{
    private: //warrior class privates, most default stats
        string warName;
        int warStrength;
        int warLoyalty;
        int warMorale;
        bool warFree;
        bool warShip;
        bool warDragonGlass;
    public: //setters, getters, control warrior stats
        Warrior();
        string getWarName();
        int getWarStrength();
        int getWarLoyalty();
        int getWarMorale();
        bool getWarFree();
        bool getWarShip();
        bool getWarDragonGlass();
        int getWarRow();
        int getWarColumn();
        void setWarName(string);
        void setWarStrength(int);
        void setWarLoyalty(int);
        void setWarMorale(int);
        void setWarFree(bool);
        void setWarShip(bool);
        void setWarDragonGlass(bool);
        void setWarRow(int);
        void setWarColumn(int);
};
#endif