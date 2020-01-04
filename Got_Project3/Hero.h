#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Warrior.h"
using namespace std;

#ifndef HERO_H
#define HERO_H

class Hero
{
    private:
        string name; //hero class, statistics here
        int money;
        int influence;
        int armySize;
        string warriors[4]; //warrior string array allows for accessing specific warriors that hero owns
        int row;
        int column;
        bool ship; //hero automatically acquires ship if they acquire a warrior who marks 'true' for ship
        int heroDrag;
        bool isAlive;
    public:
        Hero(); //public variables are setters, getters
        string getName();
        int getMoney();
        int getInfluence();
        int getArmySize();
        string getWarriors(int);
        int getRow();
        int getColumn();
        bool getShip();
        int getHeroDrag();
        bool getIsAlive(); //checks if hero is alive, allows for game to be continued
        void setName(string);
        void setMoney(int);
        void setInfluence(int);
        void setArmySize(int);
        void setWarriors(string, int);
        void setRow(int);
        void setColumn(int);
        void setShip(bool);
        void setHeroDrag(int);
        bool setIsAlive(bool);
        int calcPoints(char);
        int calcMoney(char);
        int calcArmy(char);
};
#endif