#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Map.h"
#include "City.h"
#include "split.h"
using namespace std;

Map::Map(string mapFile) //reads map file
{
    //function that reads a file and outputs map
    string line;
    
    string temp[16];
    
    ifstream mapF;
    mapF.open(mapFile);
    
    int c = 0;
    
    while(getline(mapF, line))
    {
        if (line != "" && c < 25)
        {
            split(line, ',', temp, 16);
            for (int i = 0; i < 16; i++)
            {
                worldMap[c][i] = temp[i][0];
            }
            c++;
        }
    }
    
}
void Map::readCity(string cityFile) //reads city file
{
    string line;
    
    ifstream cityF;
    cityF.open(cityFile);
    
    int size = 0;
    int test = 0;
    while(getline(cityF, line) && size < 26)
    {
        istringstream stream(line);
        //<Letter>,<Name>,<$>,<army_size>,<points>
        string strToken;
        int intToken;
        City tempCity;
        
        getline(stream, strToken, ',');
        tempCity.setCityLetter(strToken); //sets city letter
        
        getline(stream, strToken, ',');
        tempCity.setCityName(strToken); //sets city name
        
        getline(stream, strToken, ',');
        intToken = stoi(strToken);
        tempCity.setCityMoney(intToken); //sets city money
        
        getline(stream, strToken, ',');
        intToken = stoi(strToken);
        tempCity.setCityArmySize(intToken); //sets army size
        
        getline(stream, strToken, ',');
        intToken = stoi(strToken);
        tempCity.setCityPoints(intToken); //sets points
        
        cities.push_back(tempCity); //sets city values within city vector
    }
}
bool Map::isWater(int row, int column) //checks if map tile is water, prevents movement there with no boat
{
    bool waterPos;
    if (worldMap[row][column] == 'w')
    {
        waterPos = true; //if water is present
    }
    else
    {
        waterPos = false;
    }
    return waterPos;
}
bool Map::isLand(int row, int column) //checks if map tile is land, permits placement of dragonglass
{
    bool landPos;
    if (worldMap[row][column] == 'p') //if land is present
    {
        landPos = true;
    }
    else
    {
        landPos = false;
    }
    return landPos;
}
bool Map::isCity(int row, int column) //checks for city
{
    bool cityPos;
    if (worldMap[row][column] != 'p' && worldMap[row][column] != 'w') //if world map is neither land nor water
    {
        cityPos = true;
    }
    else
    {
        cityPos = false;
    }
    return cityPos;
}