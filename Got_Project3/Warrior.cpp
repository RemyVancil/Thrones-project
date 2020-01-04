#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Warrior.h"
using namespace std;

Warrior::Warrior() //default constructor
{
    warName = "";
    warStrength = 0;
    warLoyalty = 0;
    warMorale = 0;
    warFree = true;
    warShip = false;
    warDragonGlass = false;
}
string Warrior::getWarName() //getter
{
    return warName;
}
int Warrior::getWarStrength() //getter
{
    return warStrength;
}
int Warrior::getWarLoyalty() //getter
{
    return warLoyalty;
}
int Warrior::getWarMorale() //getter
{
    return warMorale;
}
bool Warrior::getWarFree() //getter
{
    return warFree;
}
bool Warrior::getWarShip() //getter
{
    return warShip;
}
bool Warrior::getWarDragonGlass() //getter
{
    return warDragonGlass;
}
void Warrior::setWarName(string new_warName) //setter
{
    warName = new_warName;
}
void Warrior::setWarStrength(int new_warStrength) //setter
{
    warStrength = new_warStrength;
}
void Warrior::setWarLoyalty(int new_warLoyalty) //setter
{
    warLoyalty = new_warLoyalty;
}
void Warrior::setWarMorale(int new_warMorale) //setter
{
    warMorale = new_warMorale;
}
void Warrior::setWarFree(bool new_warFree) //setter
{
    warFree = new_warFree;
}
void Warrior::setWarShip(bool new_warShip) //setter
{
    warShip = new_warShip;
}
void Warrior::setWarDragonGlass(bool new_warDragonGlass) //setter
{
    warDragonGlass = new_warDragonGlass;
}