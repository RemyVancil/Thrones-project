#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include "Map.h"
#include "Hero.h"
#include "Warrior.h"
#include "City.h"
using namespace std;

#ifndef GAME_H
#define GAME_H

//character preconditions (like Stannis dying) to be added in final driver

class Game //game class header
{
    private: //private, cannot be accessed
        int denyBattle;
        int heroIndex;
        bool alive;
        char gameMap[25][16]; //map matrix to read and store map data
        bool gameDragonGlass[25][16]; //dragonglass matrix for setting dragonglass
        bool gameOwnership[25][16];
        vector<Hero> heroes;
        vector<Warrior> warriors;
        int points;
        int tilesOwned;
    public: //public, available elsewhere
        Game(); //default
        int getDenyBattle(); //getter
        int getHeroIndex(); //getter
        int setDenyBattle(int); //setter
        int setHeroIndex(int); //setter
        void readMap(string); //reads map
        void miniMap(); //shows minimap
        void setDragonGlass(); //sets dragon glass location random
        void checkDragonGlass(int, int); //checks for dragonglass
        void setWanderingWarrior();
        void readHero(string);
        void createHero();
        void readWarrior(string);
        void readCity(string);
        void cityRumors();
        bool choice();
        int getPoints();
        bool getOwnership();
        int getTilesOwned();
        void setPoints(int);
        void setOwnership();
        void setTilesOwned(int);
        void updateHeroes();
        bool proximity();
        void combat();
        void enemy_combat();
        bool winCondition();
        void random();
        void mandDaenerys();
        void mandStannis();
        void mandSansa();
        void mandCersei();
        void whiteWalkers();
        bool getHeroIsAlive();
        bool getWalkersAreAlive();
        bool setWalkersAreAlive(bool);
};
#endif