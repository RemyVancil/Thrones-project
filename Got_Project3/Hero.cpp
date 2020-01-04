#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Hero.h"
#include "Warrior.h"
using namespace std;

Hero::Hero() //default constructor
{
    name = "";
    for (int i = 0; i < 4; i++)
    {
        warriors[i] = "-1";
    }
    money = 0;
    influence = 0;
    armySize = 0;
    row = -1;
    column = -1;
    ship = false;
    heroDrag = 0;
    isAlive = true;
}
string Hero::getName() //getter
{
    return name;
}
int Hero::getMoney() //getter
{
    return money;
}
int Hero::getInfluence() //getter
{
    return influence;
}
int Hero::getArmySize() //getter
{
    return armySize;
}
string Hero::getWarriors(int i) //getter
{
    return warriors[i];
}
int Hero::getRow() //getter
{
    return row;
}
int Hero::getColumn() //getter
{
    return column;
}
bool Hero::getShip() //getter
{
    return ship;
}
int Hero::getHeroDrag() //getter
{
    return heroDrag;
}
bool Hero::getIsAlive() //getter
{
    return isAlive;
}
void Hero::setName(string new_name) //setter
{
    name = new_name;
}
void Hero::setMoney(int new_money) //setter
{
    money = new_money;
}
void Hero::setInfluence(int new_influence) //setter
{
    influence = new_influence;
}
void Hero::setArmySize(int new_armySize) //setter
{
    armySize = new_armySize;
}
void Hero::setWarriors(string warriorName, int index) //setter
{
    warriors[index] = warriorName;
}
void Hero::setRow(int new_row) //setter
{
    row = new_row;
}
void Hero::setColumn(int new_column) //setter
{
    column = new_column;
}
void Hero::setShip(bool new_ship) //setter
{
    ship = new_ship;
}
void Hero::setHeroDrag(int new_DG) //setter, activated also by warriors with dragonglass
{
    heroDrag = new_DG;
}
bool Hero::setIsAlive(bool new_alive) //setter, determines if hero is alive
{
    isAlive = new_alive;
}
int Hero::calcPoints(char letter) //these will calculate points for touching tiles
{
    //create a switch statement function
    //checks letter and awards corresponding number of points
    //1 for water
    //2 for land
    //3-30 depending on city character
}
int Hero::calcMoney(char letter)
{
    //create a function which depends on tile player is on
    //location affected by whether the player has been there
}
int Hero::calcArmy(char letter)
{
    //create a function which depends on tile player is on
    //location affected by whether the player has been there
}