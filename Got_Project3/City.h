#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#ifndef CITY_H
#define CITY_H

class City
{
    private: //city class
        string letter;
        string name;
        int money;
        int armySize;
        int points;
    public: //public variables, all city stats
        City();
        string getCityLetter();
        string getCityName();
        int getCityMoney();
        int getCityArmySize();
        int getCityPoints();
        void setCityLetter(string);
        void setCityName(string);
        void setCityMoney(int);
        void setCityArmySize(int);
        void setCityPoints(int);
};
#endif