#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "City.h"
using namespace std; //done

City::City() //city class default constructor
{
    letter = "";
    name = "";
    money = 0;
    armySize = 0;
    points = 0;
}
string City::getCityLetter() //gets letter of city
{
    return letter;
}
string City::getCityName() //gets name of city
{
    return name;
}
int City::getCityMoney() //gets money assigned to city
{
    return money;
}
int City::getCityArmySize() //gets size of city army
{
    return armySize;
}
int City::getCityPoints() //gets city point value
{
    return points;
}
void City::setCityLetter(string new_letter) //sets letter of city
{
    letter = new_letter;
}
void City::setCityName(string new_name) //sets name of city
{
    name = new_name;
}
void City::setCityMoney(int new_money) //sets money assigned to city
{
    money = new_money;
}
void City::setCityArmySize(int new_armySize) //sets size of city army
{
    armySize = new_armySize;
}
void City::setCityPoints(int new_points) //sets city point value
{
    points = new_points;
}