#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "City.h"
#include "split.h"
using namespace std;

#ifndef MAP_H
#define MAP_H

class Map
{
    private:
        char worldMap[25][16]; //grid for worldmap
        vector<City> cities; //vector of cities, used for storage of city values
    public:
        Map(string);
        void readCity(string);
        bool isWater(int, int);
        bool isLand(int, int);
        bool isCity(int, int);
};
#endif

