#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
//#include "Game.h"
//#include "Map.h"
//#include "Hero.h"
//#include "Warrior.h"
//#include "City.h"
//#include "Map.cpp"
using namespace std;

//////////////SPLIT FUNCTION////////////////////////////////////////////////////
int split(string toBeSplit, char delimiter, string words[], int length) //defines integer function split, with four input arguments
{
    if (toBeSplit.length() == 0) { //if the string length is 0, or nonexistent
        return 0; //returns 0
    }
    string str = ""; //defines string str, equal to empty
    int j = 0; //defines j as integer equal to 0
    toBeSplit = toBeSplit + delimiter; //sets string toBeSplit equal to itself plus delimiter
    for (int i = 0; i < toBeSplit.length(); i++) //for loop, starts integer i at 0, conditional i is less toBeSplit length, increases i by 1
    {
        if (toBeSplit[i] == delimiter) //if ith value is equal to delimiter
        {
        	if (str.length() == 0) continue; //if string length is 0, executes next iteration of loop 
            words[j] = str; //inputs string as jth value of array
            j++; //increases j by 1
            str = ""; //resets str to empty
        }
        else //else
        {
            str = str + toBeSplit[i]; //sets str equal to itself plus toBeSplit ith value
        }
    }
    return j; //returns value of j
}
////////////////////////////////////////////////////////////////////////////////

//////////////CITY CLASS////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////

//////////////WARRIOR CLASS/////////////////////////////////////////////////////
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
        void setWarName(string);
        void setWarStrength(int);
        void setWarLoyalty(int);
        void setWarMorale(int);
        void setWarFree(bool);
        void setWarShip(bool);
        void setWarDragonGlass(bool);
};

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
////////////////////////////////////////////////////////////////////////////////

//////////////HERO CLASS////////////////////////////////////////////////////////
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
        int points;
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
        int getPoints();
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
        void setPoints(int);
        bool setIsAlive(bool);
        int calcPoints(char);
        int calcMoney(char);
        int calcArmy(char);
};

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
int Hero::getPoints() //getter
{
    return points;
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
void Hero::setPoints(int new_points) //setter
{
    points = new_points;
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
////////////////////////////////////////////////////////////////////////////////

//////////////MAP CLASS/////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////

//////////////GAME CLASS////////////////////////////////////////////////////////
class Game //game class header
{
    private: //private, cannot be accessed
        int denyBattle;
        int heroIndex;
        bool alive;
        char gameMap[25][16]; //map matrix to read and store map data
        bool gameDragonGlass[25][16]; //dragonglass matrix for setting dragonglass
        vector<Hero> heroes;
        vector<Warrior> warriors;
    public: //public, available elsewhere
        Game(); //default
        int getDenyBattle(); //getter
        int getHeroIndex(); //getter
        int setDenyBattle(int); //setter
        int setHeroIndex(int); //setter
        void readMap(string); //reads map
        void miniMap(); //shows minimap
        void setDragonGlass(); //sets dragon glass location random
        bool checkDragonGlass(int, int); //checks for dragonglass
        void readHero(string);
        void createHero();
        void readWarrior(string);
        void readCity(string);
        bool choice();
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

Game::Game() //default constructor
{
    denyBattle = 0;
    heroIndex = -1;
    alive = true;
}
int Game::getDenyBattle() //getter
{
    return denyBattle;
}
int Game::getHeroIndex() //getter
{
    return heroIndex;
}
int Game::setDenyBattle(int new_denyBattle) //setter
{
    denyBattle = new_denyBattle;
}
int Game::setHeroIndex(int new_heroIndex) //setter
{
    heroIndex = new_heroIndex;
}
void Game::readMap(string mapFile) //function that reads file map
{
    //function that reads a file and outputs map
    string line;
    
    string temp[16];
    
    ifstream mapF;
    mapF.open(mapFile);
    
    int c = 0;
    
    while(getline(mapF, line)) //getline to read map file
    {
        if (line != "" && c < 25)
        {
            split(line, ',', temp, 16);
            for (int i = 0; i < 16; i++)
            {
                gameMap[c][i] = temp[i][0]; //reads the map row by row and stores it in gameMap
            }
            c++;
        }
    }
    
}
void Game::miniMap() //minimap function, displays 7x7 map
{
    int coordY = heroes[heroIndex].getRow(); //retrieves hero coordinates
    int coordX = heroes[heroIndex].getColumn();
    
    int i;
    int j;
    
    int rowStart = coordY - 3; //checks a range around the hero, forming a 7x7 square
    int rowEnd = coordY + 3;
    int colStart = coordX - 3;
    int colEnd = coordX + 3;
    
    if (rowStart < 0) //these prevent a seg fault if the hero is too close to the border(s)
    {
        rowStart = 0;
    }
    if (rowEnd > 24)
    {
        rowEnd = 24;
    }
    if (colStart < 0)
    {
        colStart = 0;
    }
    if (colEnd > 15)
    {
        colEnd = 15;
    }
    for (i = rowStart; i <= rowEnd; i++) //nested for loop, checks every tile in the hero proximity
    {
        for (j = colStart; j <= colEnd; j++)
        {
            if (gameMap[i][j] == 'w') //if a water tile outputs tilde
            {
                cout << '~' << " ";
            }
            else if (gameMap[i][j] == 'p') //if a land tile outputs asterisk
            {
                cout << '*' << " ";
            }
            else //otherwise, just outputs map tile (i.e. city letter)
            {
                cout << gameMap[i][j] << " ";
            }
        }
        cout << endl;
    }
}
void Game::setDragonGlass() //sets dragonglass randomly
{
    srand(time(NULL));
    int randRow;
    int randCol;
    int count = 0;
    Map tile("mapGOT.txt");
    
    while (count < 5) //while there are less than 5 pieces
    {
        randRow = rand() % 25; //gives random y val
        randCol = rand() % 16; //gives random x val
        if (tile.isWater(randRow, randCol) == false && gameDragonGlass[randRow][randCol] == false) //if coordinate is not water and does not contain dragonglass
        {
            gameDragonGlass[randRow][randCol] = true; //sets location to true for dragonglass
            count++; //increase count
        }
    }
}
bool Game::checkDragonGlass(int row, int col) //checks for dragonglass
{
    string number;
    if (gameDragonGlass[row][col] == true)
    {
        heroes[heroIndex].setHeroDrag(1 + heroes[heroIndex].getHeroDrag()); //increase your dragon glass by 1
        cout << "Great news! You have stumbled upon Dragonglass." << endl;
        do{
            cout << "Choose which one of your warriors would you like to equip with Dragonglass (enter their number):" << endl;
            cin >> number; //function to decide which hero gets the dragonglass
            if (number == "1")
            {
                
            }
            if (number == "2")
            {
                
            }
            if (number == "3")
            {
                
            }
            if (number == "4")
            {
                
            }
        }
        while(number != "1" && number != "2" && number != "3" && number != "4");
    }
}
void Game::readHero(string heroFile) //function to read hero file
{
    string line;
    
    ifstream heroF;
    heroF.open(heroFile);
    
    int size = 0;
    int test = 0;
    while(getline(heroF, line) && size < 6)
    {
        istringstream stream(line);
        
        string strToken;
        int intToken;
        Hero tempHero;
        
        //basically, everything below here iterates through the hero file and sets values in a temp array
        getline(stream, strToken, ',');
        tempHero.setName(strToken);
        
        getline(stream, strToken, ',');
        intToken = stoi(strToken);
        tempHero.setMoney(intToken);
        
        getline(stream, strToken, ',');
        intToken = stoi(strToken);
        tempHero.setInfluence(intToken);
        
        getline(stream, strToken, ',');
        intToken = stoi(strToken);
        tempHero.setArmySize(intToken);
        
        //here, the warriors are repeated 4 times to fill completely
        //consider for loop in future
        int warNumber = 0;
        getline(stream, strToken, ',');
        tempHero.setWarriors(strToken, warNumber);
        warNumber++;
        
        getline(stream, strToken, ',');
        tempHero.setWarriors(strToken, warNumber);
        warNumber++;
        
        getline(stream, strToken, ',');
        tempHero.setWarriors(strToken, warNumber);
        warNumber++;
        
        getline(stream, strToken, ',');
        tempHero.setWarriors(strToken, warNumber);
        warNumber++;
        
        getline(stream, strToken, ',');
        intToken = stoi(strToken);
        tempHero.setRow(intToken);
        
        getline(stream, strToken, ',');
        intToken = stoi(strToken);
        tempHero.setColumn(intToken);
        
        getline(stream, strToken);
        bool shipToken;
        if (strToken == "no")
        {
            shipToken = false;
            tempHero.setShip(shipToken); //sets your ship
        }
        else if (strToken == "yes")
        {
            shipToken = true;
            tempHero.setShip(shipToken); //sets your ship
        }
        
        //at the end, pushes back the hero vector with the information accrued in temp hero
        heroes.push_back(tempHero);
    }
}
void Game::createHero() //function to create a hero
{
    //code to set stats
    
    Hero tempPlayer;
    Map tile("mapGOT.txt");
    
    string heroName;
    int inputMoney = 0;
    int inputInfluence = 0;
    int inputArmySize = 0;
    int inputRow = 0;
    int inputColumn = 0;
    
    cout << "Enter hero name:" << endl;
    cin >> heroName;
    tempPlayer.setName(heroName); //sets hero name
    
    do{
        cout << "Enter money value (0 - 10000):" << endl;
        cin >> inputMoney;
        if(inputMoney >= 0 && inputMoney <= 10000) //checks that within range
        {
            tempPlayer.setMoney(inputMoney); //sets hero money
        }
    }
    while(inputMoney < 0 || inputMoney > 10000);
    
    do{
        cout << "Enter influence value (0 - 10000):" << endl;
        cin >> inputInfluence;
        if(inputInfluence >= 0 && inputInfluence <= 10000) //checks that within range
        {
            tempPlayer.setInfluence(inputInfluence); //sets hero influence
        }
    }
    while(inputInfluence < 0 || inputInfluence > 10000);
    
    do{
        cout << "Enter army size value (0 - 10000):" << endl;
        cin >> inputArmySize;
        if(inputArmySize >= 0 && inputArmySize <= 10000) //checks that within range
        {
            tempPlayer.setArmySize(inputArmySize); //sets hero army size
        }
    }
    while(inputArmySize < 0 || inputArmySize > 10000);
    
    do{
        cout << "Enter row value (0 - 24):" << endl;
        cin >> inputRow;
        if(inputRow >= 0 && inputRow <= 24) //checks that within range
        {
            tempPlayer.setRow(inputRow); //sets hero row
        }
    }
    while(inputRow < 0 || inputRow > 24);
    
    do{
        cout << "Enter column value (0 - 15):" << endl;
        cin >> inputColumn;
        if(inputColumn >= 0 && inputColumn <= 15) //checks that within range
        {
            tempPlayer.setColumn(inputColumn); //sets hero column
        }
    }
    while(inputColumn < 0 || inputColumn > 15);
    
    bool shipToken = false;
    if (tile.isWater(inputRow, inputColumn) == true) //if created hero has start tile of water 
    {
        shipToken = true;
        tempPlayer.setShip(shipToken); //gives hero a boat
    }
    
    heroes.push_back(tempPlayer);
}
void Game::readWarrior(string warFile) //function to read warrior file
{
    string line;
    
    ifstream warF;
    warF.open(warFile);
    
    //same deal here; this reads a file of warriors, and fills in a temp
    int size = 0;
    int test = 0;
    while(getline(warF, line) && size < 14)
    {
        istringstream stream(line);
        
        string strToken;
        int intToken;
        Warrior tempWarrior;
        
        //sets name, strength, loyalty, and morale
        getline(stream, strToken, ',');
        tempWarrior.setWarName(strToken);
        
        getline(stream, strToken, ',');
        intToken = stoi(strToken);
        tempWarrior.setWarStrength(intToken);
        
        getline(stream, strToken, ',');
        intToken = stoi(strToken);
        tempWarrior.setWarLoyalty(intToken);
        
        getline(stream, strToken, ',');
        intToken = stoi(strToken);
        tempWarrior.setWarMorale(intToken);
        
        //sets the bools, so freedom, boat, and dragonglass
        getline(stream, strToken, ',');
        bool boolToken1;
        if (strToken == "no")
        {
            boolToken1 = false;
        }
        if (strToken == "yes")
        {
            boolToken1 = true;
        }
        tempWarrior.setWarFree(boolToken1);
        
        getline(stream, strToken, ',');
        bool boolToken2;
        if (strToken == "no")
        {
            boolToken2 = false;
        }
        if (strToken == "yes")
        {
            boolToken2 = true;
        }
        tempWarrior.setWarShip(boolToken2);
        
        getline(stream, strToken);
        bool boolToken3;
        if (strToken == "no")
        {
            boolToken3 = false;
        }
        if (strToken == "yes")
        {
            boolToken3 = true;
        }
        tempWarrior.setWarDragonGlass(boolToken3);
        
        //at the end, fills warrior vector with the information from temp
        warriors.push_back(tempWarrior);
    }
}
bool Game::choice() //function to give movement and rest options
{
    string action;
    string cardinal;
    Hero position;
    int r;
    int c;
    
    int index = getHeroIndex();
    if (heroes[4].getName() == "Euron Greyjoy")
    {
        heroes[4].setShip(true); //code to give Euron a ship
    }
    for (int i = 0; i < warriors.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (warriors[i].getWarName() == heroes[heroIndex].getWarriors(j))
            {
                if (warriors[i].getWarShip() == true)
                {
                    heroes[heroIndex].setShip(true); //code to update hero boats for warriors with boats
                }
            }
        }
    }
    
    for (int i = 0; i < heroes.size(); i++) //gets hero player row
    {
        if (i == getHeroIndex())
        {
            r = heroes[i].getRow();
            break;
        }
        else
        {
            continue;
        }
    }
    for (int j = 0; j < heroes.size(); j++) //gets hero player column
    {
        if (j == getHeroIndex())
        {
            c = heroes[j].getColumn();
            break;
        }
        else
        {
            continue;
        }
    }
    
    Map tile("mapGOT.txt");
    
    int menuRow; //row and column to be updated
    int menuColumn;

    do{
        cout << "What shall we do now, Your Grace?" << endl;
        cout << "Shall we travel (1), or rest (2), or consult the gods (3)?" << endl;
        cin >> action;
        if (action == "1") //if player chooses to travel
        {
            do{
                if (heroes[index].getShip() == true) //returns message if water travel is possible
                {
                    cout << "You have a ship at your disposal, Your Grace." << endl;
                }
                cout << "Shall we travel North, East, South, or West?" << endl;
                cin >> cardinal; //option to go NEWS
                
                if (cardinal == "N" || cardinal == "n") //north
                {
                    cout << "North!" << endl;
                    menuRow = r - 1;
                    //change row count by 1, provided that size is not exceeded
                    if (heroes[index].getShip() == true || tile.isWater(menuRow, c) == false) //if player has ship or location is not water
                    {
                        if (r > 1) //if there is space north
                        {
                            heroes[index].setRow(menuRow);
                            cout << "Row: " << heroes[index].getRow() << " " << "Column: " << heroes[index].getColumn() << endl;
                        }
                        if (r <= 1) //if no space north
                        {
                            cout << "There is nothing for us further north." << endl;
                        }
                    }
                    else //if water body north and no ship
                    {
                        cout << "We cannot go further north." << endl;
                    }
                }
                
                if (cardinal == "E" || cardinal == "e")
                {
                    cout << "East!" << endl;
                    menuColumn = c + 1;
                    //change column count by 1, provided that size is not exceeded
                    if (heroes[index].getShip() == true || tile.isWater(r, menuColumn) == false) //if player has ship or location is not water
                    {
                        if (c < 16) //if there is space east
                        {
                            heroes[index].setColumn(menuColumn);
                            cout << "Row: " << heroes[index].getRow() << " " << "Column: " << heroes[index].getColumn() << endl;
                        }
                        if (c >= 16) //if there is space east
                        {
                            cout << "There is nothing for us further east." << endl;
                            cout << endl;
                        }
                    }
                    else
                    {
                        cout << "We cannot go further east." << endl;
                        cout << endl;
                    }
                }
                
                if (cardinal == "S" || cardinal == "s")
                {
                    cout << "South!" << endl;
                    menuRow = r + 1;
                    //change row count by 1, provided that size is not exceeded
                    if (heroes[index].getShip() == true || tile.isWater(menuRow, c) == false) //if player has ship or location is not water
                    {
                        if (r < 25) //if there is space south
                        {
                            heroes[index].setRow(menuRow);
                            cout << "Row: " << heroes[index].getRow() << " " << "Column: " << heroes[index].getColumn() << endl;
                        }
                        if (r >= 25) //if there is space south
                        {
                            cout << "There is nothing for us further south." << endl;
                            cout << endl;
                        }
                    }
                    else
                    {
                        cout << "We cannot go further south." << endl;
                        cout << endl;
                    }
                }
                
                if (cardinal == "W" || cardinal == "w")
                {
                    cout << "West!" << endl;
                    menuColumn = c - 1;
                    //change column count by 1, provided that size is not exceeded
                    if (heroes[index].getShip() == true || tile.isWater(r, menuColumn) == false) //if player has ship or location is not water
                    {
                        if (c > 1)
                        {
                            heroes[index].setColumn(menuColumn);
                            cout << "Row: " << heroes[index].getRow() << " " << "Column: " << heroes[index].getColumn() << endl;
                        }
                        if (c <= 1)
                        {
                            cout << "There is nothing for us further east." << endl;
                            cout << endl;
                        }
                    }
                    else
                    {
                        cout << "We cannot go further east." << endl;
                        cout << endl;
                    }
                }
            }
            while (cardinal != "N" && cardinal != "n" && cardinal != "E" && cardinal != "e" && cardinal != "W" && cardinal != "w" && cardinal != "S" && cardinal != "s");
        }
        if (action == "2")
        {
            //function that does not change hero location, increases strength, and increases turn count
            cout << "The men are tired, Your Grace, you are so wise to see it." << endl;
            for (int i = 0; i < warriors.size(); i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (warriors[i].getWarName() == heroes[heroIndex].getWarriors(j))
                    {
                        warriors[i].setWarStrength(1 + warriors[i].getWarStrength());
                        cout << warriors[i].getWarName() << "'s strength: " << warriors[i].getWarStrength() << endl;
                    }
                }
            }
        }
        if (action == "3")
        {
            //function that does not change hero location, increases morale, and increases turn count
            cout << "Wisdom through piety, Your Grace. The gods will surely know what to do." << endl;
            cout << endl;
            for (int i = 0; i < warriors.size(); i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (warriors[i].getWarName() == heroes[heroIndex].getWarriors(j))
                    {
                        warriors[i].setWarMorale(1 + warriors[i].getWarMorale());
                        cout << warriors[i].getWarName() << "'s morale: " << warriors[i].getWarMorale() << endl;
                    }
                }
            }
        }
    }
    while(action != "1" && action != "2" && action != "3");
}
void Game::updateHeroes() //updates other hero locations
{
    srand(time(0)); //seeds random
    int moveRand; //defines move rand
    Map tile("mapGOT.txt");
    
    if (heroes[4].getName() == "Euron Greyjoy")
    {
        heroes[4].setShip(true); //code to give Euron a boat
    }
    for (int k = 0; k < heroes.size(); k++)
    {
        for (int i = 0; i < warriors.size(); i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (warriors[i].getWarName() == heroes[k].getWarriors(j))
                {
                    if (warriors[i].getWarShip() == true)
                    {
                        heroes[k].setShip(true); //code to update hero ships if they have a warrior with a boat
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < heroes.size(); i++) //checks all heroes
    {
        if (i == heroIndex)
        {
            continue; //skips player hero
        }
        else
        {
            if (heroes[i].getIsAlive() == true)
            {
                moveRand = 1 + rand() % 4; //otherwise, gives a random value 1 - 4
                if (moveRand == 1) //if 1, sends hero north if they have open space to north, otherwise go south
                {
                    if (heroes[i].getShip() == true || tile.isWater((-1 + heroes[i].getRow()), heroes[i].getColumn()) == false)
                    {
                        if (heroes[i].getRow() > 1)
                        {
                            heroes[i].setRow(-1 + heroes[i].getRow());
                        }
                    }
                }
                if (moveRand == 2) //if 2, sends hero south if they have open space to south, otherwise go north
                {
                    if (heroes[i].getShip() == true || tile.isWater((1 + heroes[i].getRow()), heroes[i].getColumn()) == false)
                    {
                        if (heroes[i].getRow() < 25)
                        {
                            heroes[i].setRow(1 + heroes[i].getRow());
                        }
                    }
                }
                if (moveRand == 3) //if 3, sends hero west if they have open space to west, otherwise go east
                {
                    if (heroes[i].getShip() == true || tile.isWater(heroes[i].getRow(), (-1 + heroes[i].getColumn())) == false)
                    {
                        if (heroes[i].getColumn() > 1)
                        {
                            heroes[i].setColumn(-1 + heroes[i].getColumn());
                        }
                    }
                }
                if (moveRand == 4) //if 4, sends hero east if they have open space to east, otherwise go west
                {
                    if (heroes[i].getShip() == true || tile.isWater(heroes[i].getRow(), (1 + heroes[i].getColumn())) == false)
                    {
                        if (heroes[i].getColumn() < 16)
                        {
                            heroes[i].setColumn(1 + heroes[i].getColumn());
                        }
                    }
                }
            }
        }
    }
}
bool Game::proximity() //function to determine proximity of other heroes in area
{
    //function that checks proximity to NPCs to initiate fight if true
    bool fight = false;
    
    for (int i = 0; i < heroes.size(); i++) //for loop checks every hero position
    {
        if (i == heroIndex) //ignores player hero
        {
            continue;
        }
        else
        {
            if (heroes[i].getIsAlive() == true)
            {
                if (heroes[i].getRow() >= (heroes[heroIndex].getRow() - 3) && heroes[i].getRow() <= (heroes[heroIndex].getRow() + 3)) //if enemy hero row is in range
                {
                    if (heroes[i].getColumn() >= (heroes[heroIndex].getColumn() - 3) && heroes[i].getColumn() <= (heroes[heroIndex].getColumn() + 3)) //if enemy hero column is in range
                    {
                        fight = true; //sets fight to true
                        cout << heroes[i].getName() << " approches! Prepare for combat!" << endl; //output fight message
                        break; //ends for loop
                    }
                }
            }
        }
    }
    if (fight == false)
    {
        cout << "No one is nearby at the moment." << endl; //output peace message
    }
    return fight; //returns bool to determine fight status
}
void Game::combat() //function for combat choice and outcome
{
    //function that gives a result depending on player values
    string combatChoice;
    srand(time(0)); //seeds random
    
    double probSpeech;
    double probBuy;
    int probFight;
    bool winLose;
    
    int enemyIndex;
    for (int i = 0; i < heroes.size(); i++) //repeat of proximity basically, but just verifies enemy hero index
    {
        if (i == heroIndex)
        {
            continue;
        }
        else
        {
            if (heroes[i].getIsAlive() == true)
            {
                if (heroes[i].getRow() >= (heroes[heroIndex].getRow() - 3) && heroes[i].getRow() <= (heroes[heroIndex].getRow() + 3))
                {
                    if (heroes[i].getColumn() >= (heroes[heroIndex].getColumn() - 3) && heroes[i].getColumn() <= (heroes[heroIndex].getColumn() + 3))
                    {
                        enemyIndex = i;
                        break;
                    }
                }
            }
        }
    }
    
    cout << "How will you proceed?" << endl;
    cout << "Money: " << heroes[heroIndex].getMoney() << endl;
    cout << "Influence: " << heroes[heroIndex].getInfluence() << endl;
    cout << "Army Size: " << heroes[heroIndex].getArmySize() << endl;
    cout << endl;
    do{
        cout << "Give a speech (1), buy them outright (2), or fight (3)?" << endl;
        cout << endl;
        cin >> combatChoice; //gives player choice in how they fight enemy
        
        if (combatChoice == "1")
        {
            cout << "Perhaps words will convince the enemy hero not to kill you." << endl;
            int enemyMorale;
            for (int a = 0; a < warriors.size(); a++)
            {
                for (int b = 0; b < 1; b++)
                {
                    if (warriors[a].getWarName() == heroes[enemyIndex].getWarriors(b))
                    {
                        enemyMorale = warriors[a].getWarMorale(); //goes through warriors and finds enemy first warrior morale
                    }
                    if (heroes[enemyIndex].getWarriors(b) == "NULL")
                    {
                        enemyMorale = -1; //if no warriors, sets to dead man's value
                    }
                }
            }
            if (enemyMorale >= 0) //calculate prob speech based on warrior morale
            {
                probSpeech = (1 - (1.0 * enemyMorale / 100)) * (1.0 * heroes[heroIndex].getInfluence() / 1600);
            }
            if (enemyMorale < 0) //if no warrior, loses
            {
                probSpeech = 1;
            }
            cout << "Probability of successful speech is " << probSpeech * 100 << " percent." << endl; //outputs odds of winning
            if (probSpeech <= 0)
            {
                //lose
                cout << "Your speech completely failed!" << endl;
                cout << "You survived the encounter, but your reputation lies in ruins." << endl;
                heroes[heroIndex].setInfluence(heroes[heroIndex].getInfluence() / 2); //outputs info to show that failure was critical, halves influence
                cout << "Influence: " << heroes[heroIndex].getInfluence() << endl;
            }
            if (probSpeech >= 1)
            {
                //win
                cout << "Impressive! Your speech succeeded!" << endl; //distinguishes critical victory
                cout << heroes[enemyIndex].getName() << " has retired." << endl;
                cout << "You have gained control of their warriors, money, influence, and army!" << endl;
                //transfer warriors to party
                heroes[heroIndex].setMoney(heroes[heroIndex].getMoney() + heroes[enemyIndex].getMoney()); //sets values to yours plus enemy's
                heroes[heroIndex].setInfluence(heroes[heroIndex].getInfluence() + heroes[enemyIndex].getInfluence());
                heroes[heroIndex].setArmySize(heroes[heroIndex].getArmySize() + heroes[enemyIndex].getArmySize());
                cout << "Money: " << heroes[heroIndex].getMoney() << endl;
                cout << "Influence: " << heroes[heroIndex].getInfluence() << endl;
                cout << "Army Size: " << heroes[heroIndex].getArmySize() << endl;
                heroes[enemyIndex].setIsAlive(false); //remove other hero from game
            }
            else if (probSpeech > 0 && probSpeech < 1)
            {
                winLose = (rand() % 100) < (probSpeech * 100); //calculates victory based on probability
                if (winLose == true) //if win
                {
                    //win
                    cout << "Your speech succeeded!" << endl;
                    cout << heroes[enemyIndex].getName() << " has retired." << endl;
                    cout << "You have gained control of their warriors, money, influence, and army!" << endl;
                    //transfer warriors to party
                    heroes[heroIndex].setMoney(heroes[heroIndex].getMoney() + heroes[enemyIndex].getMoney()); //sets values to yours plus enemy's
                    heroes[heroIndex].setInfluence(heroes[heroIndex].getInfluence() + heroes[enemyIndex].getInfluence());
                    heroes[heroIndex].setArmySize(heroes[heroIndex].getArmySize() + heroes[enemyIndex].getArmySize());
                    cout << "Money: " << heroes[heroIndex].getMoney() << endl;
                    cout << "Influence: " << heroes[heroIndex].getInfluence() << endl;
                    cout << "Army Size: " << heroes[heroIndex].getArmySize() << endl;
                    heroes[enemyIndex].setIsAlive(false); //remove other hero from game
                }
                if (winLose == false) //if lose
                {
                    //lose
                    cout << "Your speech failed!" << endl;
                    cout << "You survived the encounter, but your reputation has taken a hit." << endl;
                    heroes[heroIndex].setInfluence(heroes[heroIndex].getInfluence() / 2); //halves influence
                    cout << "Influence: " << heroes[heroIndex].getInfluence() << endl;
                }
            }
        }
        
        if (combatChoice == "2")
        {
            cout << "Bribery would certainly win over a sellsword. Will it work on a hero, I wonder?" << endl;
            
            int enemyLoyalty;
            for (int a = 0; a < warriors.size(); a++)
            {
                for (int b = 0; b < 1; b++)
                {
                    if (warriors[a].getWarName() == heroes[enemyIndex].getWarriors(b))
                    {
                        enemyLoyalty = warriors[a].getWarLoyalty(); //sets enemy loyalty based on their first warrior
                    }
                    if (heroes[enemyIndex].getWarriors(b) == "NULL") //if no warriors
                    {
                        enemyLoyalty = -1;
                    }
                }
            }
            if (enemyLoyalty >= 0) //finds odds of winning
            {
                probBuy = (1 - (1.0 * enemyLoyalty / 100)) * (1.0 * heroes[heroIndex].getMoney() / 17800); //finds probability of a buyout
            }
            if (enemyLoyalty == -1) //if no warrior, loses
            {
                probBuy = 1;
            }
            cout << "Probability of successful buyout is " << probBuy * 100 << " percent." << endl; //output probability
            if (probBuy <= 0)
            {
                //lose
                cout << "Your bribe completely failed!" << endl; //crit failure
                cout << "You survived the encounter, but at the expense of your gold." << endl;
                heroes[heroIndex].setMoney(heroes[heroIndex].getMoney() / 2); //outputs info to show that failure was critical, halves money
                cout << "Money: " << heroes[heroIndex].getMoney() << endl;
            }
            if (probBuy >= 1)
            {
                //win
                cout << "Wow! Your bribe succeeded!" << endl; //critical victory
                cout << heroes[enemyIndex].getName() << " has retired." << endl;
                cout << "You have gained control of their warriors, money, influence, and army!" << endl;
                //transfer warriors to party
                heroes[heroIndex].setMoney(heroes[heroIndex].getMoney() + heroes[enemyIndex].getMoney());
                heroes[heroIndex].setInfluence(heroes[heroIndex].getInfluence() + heroes[enemyIndex].getInfluence());
                heroes[heroIndex].setArmySize(heroes[heroIndex].getArmySize() + heroes[enemyIndex].getArmySize());
                cout << "Money: " << heroes[heroIndex].getMoney() << endl; //get money
                cout << "Influence: " << heroes[heroIndex].getInfluence() << endl; //
                cout << "Army Size: " << heroes[heroIndex].getArmySize() << endl;
                heroes[enemyIndex].setIsAlive(false); //remove other hero from game
            }
            else if (probBuy > 0 && probBuy < 1)
            {
                winLose = (rand() % 100) < (probBuy * 100);
                if (winLose == true)
                {
                    //win
                    cout << "Your bribe succeeded!" << endl;
                    cout << heroes[enemyIndex].getName() << " has retired." << endl;
                    cout << "You have gained control of their warriors, money, influence, and army!" << endl;
                    //transfer warriors to party
                    heroes[heroIndex].setMoney(heroes[heroIndex].getMoney() + heroes[enemyIndex].getMoney());
                    heroes[heroIndex].setInfluence(heroes[heroIndex].getInfluence() + heroes[enemyIndex].getInfluence());
                    heroes[heroIndex].setArmySize(heroes[heroIndex].getArmySize() + heroes[enemyIndex].getArmySize());
                    cout << "Money: " << heroes[heroIndex].getMoney() << endl;
                    cout << "Influence: " << heroes[heroIndex].getInfluence() << endl;
                    cout << "Army Size: " << heroes[heroIndex].getArmySize() << endl;
                    heroes[enemyIndex].setIsAlive(false); //remove other hero from game
                }
                if (winLose == false)
                {
                    //lose
                    cout << "Your bribe failed!" << endl;
                    cout << "You survived the encounter, but your gold is halved." << endl;
                    heroes[heroIndex].setMoney(heroes[heroIndex].getMoney() / 2);
                    cout << "Money: " << heroes[heroIndex].getMoney() << endl;
                }
            }
        }
        
        if (combatChoice == "3")
        {
            cout << "Perhaps our axes will make the enemy see reason." << endl;
            cout << "Which warrior will be your champion?" << endl;
            int heroWins;
            int enemyWins;
            string warriorNumber;
            int count = 1;
            int numHeroWarriors = 0;
            int numEnemyWarriors = 0;
            
            for (int i = 0; i < warriors.size(); i++) //finds num of hero warriors and outputs their place value
            {
                for (int j = 0; j < 4; j++)
                {
                    if (warriors[i].getWarName() == heroes[heroIndex].getWarriors(j))
                    {
                        cout << warriors[i].getWarName() << " (" << count << ")" << endl;
                        count++;
                        numHeroWarriors++;
                    }
                }
            }
            for (int i = 0; i < warriors.size(); i++) //finds num of enemy warriors
            {
                for (int j = 0; j < 4; j++)
                {
                    if (warriors[i].getWarName() == heroes[enemyIndex].getWarriors(j))
                    {
                        numEnemyWarriors++;
                    }
                }
            }
            
            if (numHeroWarriors == 0 && numEnemyWarriors != 0) //if hero has no warriors and enemy has warriors
            {
                cout << "Oh, that's right...you don't have any warriors. Do you?" << endl;
                heroes[heroIndex].setIsAlive(false); //hero loses the game
            }
            if (numHeroWarriors != 0 && numEnemyWarriors == 0) //if hero has warriors and enemy has no warriors
            {
                cout << "The enemy has no warriors. You should be able to make short work of them." << endl;
                cout << heroes[enemyIndex].getName() << " has retired." << endl;
                cout << "You have gained control of their warriors, money, influence, and army!" << endl;
                //transfer warriors to party
                heroes[heroIndex].setMoney(heroes[heroIndex].getMoney() + heroes[enemyIndex].getMoney()); //get enemy hero stats added on to yours
                heroes[heroIndex].setInfluence(heroes[heroIndex].getInfluence() + heroes[enemyIndex].getInfluence());
                heroes[heroIndex].setArmySize(heroes[heroIndex].getArmySize() + heroes[enemyIndex].getArmySize());
                cout << "Money: " << heroes[heroIndex].getMoney() << endl;
                cout << "Influence: " << heroes[heroIndex].getInfluence() << endl;
                cout << "Army Size: " << heroes[heroIndex].getArmySize() << endl;
                heroes[enemyIndex].setIsAlive(false); //remove other hero from game
            }
            else{
                int heroStrength;
                int enemyStrength;
                if (numHeroWarriors == 1){
                    do{
                        cin >> warriorNumber; //input value
                        if (warriorNumber == "1")
                        {
                            for (int a = 0; a < warriors.size(); a++)
                            {
                                for (int b = 0; b < 1; b++)
                                {
                                    if (warriors[a].getWarName() == heroes[heroIndex].getWarriors(b))
                                    {
                                        heroStrength = warriors[a].getWarStrength(); //gets strength of warrior 1
                                    }
                                }
                            }
                            heroWins = heroes[heroIndex].getArmySize() * heroStrength; //calc overall power of hero
                        }
                    }
                    while (warriorNumber != "1"); //while value isn't 1
                } //if number of warriors for hero is 1
                if (numHeroWarriors == 2){
                    do{
                        cin >> warriorNumber; //input value
                        if (warriorNumber == "1")
                        {
                            for (int a = 0; a < warriors.size(); a++)
                            {
                                for (int b = 0; b < 1; b++)
                                {
                                    if (warriors[a].getWarName() == heroes[heroIndex].getWarriors(b))
                                    {
                                        heroStrength = warriors[a].getWarStrength(); //gets strength of warrior 1
                                    }
                                }
                            }
                            heroWins = heroes[heroIndex].getArmySize() * heroStrength; //calc overall power of hero
                        }
                        if (warriorNumber == "2")
                        {
                            for (int a = 0; a < warriors.size(); a++)
                            {
                                for (int b = 0; b < 2; b++)
                                {
                                    if (warriors[a].getWarName() == heroes[heroIndex].getWarriors(b))
                                    {
                                        heroStrength = warriors[a].getWarStrength(); //gets strength of warrior 2
                                    }
                                }
                            }
                            heroWins = heroes[heroIndex].getArmySize() * heroStrength; //calc overall power of hero
                        }
                    }
                    while (warriorNumber != "1" && warriorNumber != "2");
                } //if number of warriors for hero is 2
                if (numHeroWarriors == 3){
                    do{
                        cin >> warriorNumber; //input value
                        if (warriorNumber == "1")
                        {
                            for (int a = 0; a < warriors.size(); a++)
                            {
                                for (int b = 0; b < 1; b++)
                                {
                                    if (warriors[a].getWarName() == heroes[heroIndex].getWarriors(b))
                                    {
                                        heroStrength = warriors[a].getWarStrength(); //gets strength of warrior 1
                                    }
                                }
                            }
                            heroWins = heroes[heroIndex].getArmySize() * heroStrength; //calc overall power of hero
                        }
                        if (warriorNumber == "2")
                        {
                            for (int a = 0; a < warriors.size(); a++)
                            {
                                for (int b = 0; b < 2; b++)
                                {
                                    if (warriors[a].getWarName() == heroes[heroIndex].getWarriors(b))
                                    {
                                        heroStrength = warriors[a].getWarStrength(); //gets strength of warrior 2
                                    }
                                }
                            }
                            heroWins = heroes[heroIndex].getArmySize() * heroStrength; //calc overall power of hero
                        }
                        if (warriorNumber == "3")
                        {
                            for (int a = 0; a < warriors.size(); a++)
                            {
                                for (int b = 0; b < 3; b++)
                                {
                                    if (warriors[a].getWarName() == heroes[heroIndex].getWarriors(b))
                                    {
                                        heroStrength = warriors[a].getWarStrength(); //gets strength of warrior 3
                                    }
                                }
                            }
                            heroWins = heroes[heroIndex].getArmySize() * heroStrength; //calc overall power of hero
                        }
                    }
                    while (warriorNumber != "1" && warriorNumber != "2" && warriorNumber != "3");
                } //if number of warriors for hero is 3
                if (numHeroWarriors == 4){
                    do{
                        cin >> warriorNumber; //input value
                        if (warriorNumber == "1")
                        {
                            for (int a = 0; a < warriors.size(); a++)
                            {
                                for (int b = 0; b < 1; b++)
                                {
                                    if (warriors[a].getWarName() == heroes[heroIndex].getWarriors(b))
                                    {
                                        heroStrength = warriors[a].getWarStrength(); //gets strength of warrior 1
                                    }
                                }
                            }
                            heroWins = heroes[heroIndex].getArmySize() * heroStrength; //calc overall power of hero
                        }
                        if (warriorNumber == "2")
                        {
                            for (int a = 0; a < warriors.size(); a++)
                            {
                                for (int b = 0; b < 2; b++)
                                {
                                    if (warriors[a].getWarName() == heroes[heroIndex].getWarriors(b))
                                    {
                                        heroStrength = warriors[a].getWarStrength(); //gets strength of warrior 2
                                    }
                                }
                            }
                            heroWins = heroes[heroIndex].getArmySize() * heroStrength; //calc overall power of hero
                        }
                        if (warriorNumber == "3")
                        {
                            for (int a = 0; a < warriors.size(); a++)
                            {
                                for (int b = 0; b < 3; b++)
                                {
                                    if (warriors[a].getWarName() == heroes[heroIndex].getWarriors(b))
                                    {
                                        heroStrength = warriors[a].getWarStrength(); //gets strength of warrior 3
                                    }
                                }
                            }
                            heroWins = heroes[heroIndex].getArmySize() * heroStrength; //calc overall power of hero
                        }
                        if (warriorNumber == "4")
                        {
                            for (int a = 0; a < warriors.size(); a++)
                            {
                                for (int b = 0; b < 4; b++)
                                {
                                    if (warriors[a].getWarName() == heroes[heroIndex].getWarriors(b))
                                    {
                                        heroStrength = warriors[a].getWarStrength(); //gets strength of warrior 4
                                    }
                                }
                            }
                            heroWins = heroes[heroIndex].getArmySize() * heroStrength; //calc overall power of hero
                        }
                    }
                    while (warriorNumber != "1" && warriorNumber != "2" && warriorNumber != "3" && warriorNumber != "4");
                } //if number of warriors for hero is 4
                
                for (int a = 0; a < warriors.size(); a++)
                {
                    for (int b = 0; b < 1; b++)
                    {
                        if (warriors[a].getWarName() == heroes[enemyIndex].getWarriors(b))
                        {
                            enemyStrength = warriors[a].getWarStrength(); //gets strength of warrior 1
                        }
                    }
                }
                enemyWins = heroes[enemyIndex].getArmySize() * enemyStrength;
                if (enemyWins > heroWins) //if you are more powerful
                {
                    cout << "The enemy has won." << endl;
                    heroes[heroIndex].setIsAlive(false); //kills main hero, game ends
                }
                if (enemyWins < heroWins) //if enemy is less powerful
                {
                    cout << "The enemy has lost." << endl;
                    cout << heroes[enemyIndex].getName() << " has retired." << endl;
                    cout << "You have gained control of their warriors, money, influence, and army!" << endl;
                    //transfer warriors to party
                    heroes[heroIndex].setMoney(heroes[heroIndex].getMoney() + heroes[enemyIndex].getMoney()); //take enemy stats
                    heroes[heroIndex].setInfluence(heroes[heroIndex].getInfluence() + heroes[enemyIndex].getInfluence());
                    heroes[heroIndex].setArmySize(heroes[heroIndex].getArmySize() + heroes[enemyIndex].getArmySize());
                    cout << "Money: " << heroes[heroIndex].getMoney() << endl;
                    cout << "Influence: " << heroes[heroIndex].getInfluence() << endl;
                    cout << "Army Size: " << heroes[heroIndex].getArmySize() << endl;
                    heroes[enemyIndex].setIsAlive(false); //remove other hero from game
                }
                else if (enemyWins == heroWins) //if even power
                {
                    cout << "You are evenly matched. The fight ends in stalemate." << endl; //does nothing
                }
            }
        }
    }
    while (combatChoice != "1" && combatChoice != "2" && combatChoice != "3"); //while choice is not 1 or 2 or 3
}
void Game::enemy_combat() //function for battling amongst enemy heroes
{
    bool fight = false;
    
    for (int i = 0; i < heroes.size(); i++) //for loop checks every hero position
    {
        if (i == heroIndex) //ignores player hero
        {
            continue;
        }
        if (heroes[i].getIsAlive() == false) //ignores dead heroes
        {
            continue;
        }
        for (int j = 0; j < heroes.size(); j++) //ignores player hero
        {
            if (j == heroIndex)
            {
                continue;
            }
            if (heroes[j].getIsAlive() == false) //ignores dead heroes
            {
                continue;
            }
            if (heroes[i].getRow() >= heroes[j].getRow() - 3 && heroes[i].getRow() <= heroes[j].getRow() + 3) //if within proximity to each other
            {
                if (heroes[i].getColumn() >= heroes[j].getColumn() - 3 && heroes[i].getColumn() <= heroes[j].getColumn() + 3)
                {
                    if(heroes[i].getArmySize() > heroes[j].getArmySize()) //if army size i is bigger than army size j
                    {
                        heroes[j].setIsAlive(false); //kills hero j
                        cout << heroes[j].getName() << " has been retired by " << heroes[i].getName() << endl;
                        cout << endl;
                    }
                    if(heroes[i].getArmySize() < heroes[j].getArmySize()) //if army size i is smaller than army size j
                    {
                        heroes[i].setIsAlive(false); //kills hero i
                        cout << heroes[i].getName() << " has been retired by " << heroes[j].getName() << endl;
                        cout << endl;
                    }
                }
            }
        }
    }
}
bool Game::winCondition() //checks if player meets any white walker conditions
{
    //checks if the player fails any conditions to keep playing or has won
    int count = 0;
    for (int i = 0; i < heroes.size(); i++)
    {
        if (heroes[i].getIsAlive() == true)
        {
            count++;
        }
    }
    if (heroes[heroIndex].getArmySize() >= 2000 || count == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Game::random() //checks for random events, and determines nature of event
{
    //checks for and causes random events
    //predetermined events are in driver
    srand(time(0)); //seeds random
    int probRand = 1 + rand() % 10; //return random value in 1 - 10
    if (probRand >= 1 && probRand <= 3) //if random is within 1 - 3, ie 30%
    {
        int typeRand = 1 + rand() % 4; //determines type of event by giving each 25% chance of occuring
        if (typeRand == 1) //drought
        {
            cout << endl;
            cout << "A drought ravages the landscape." << endl;
            cout << "There has been no rain in days and the army has very little food left." << endl;
            cout << endl;
            
            for (int i = 0; i < warriors.size(); i++) //nested for loop, only adjusts player hero warriors
            {
                for (int j = 0; j < 4; j++)
                {
                    if (warriors[i].getWarName() == heroes[heroIndex].getWarriors(j))
                    {
                        if (warriors[i].getWarStrength() >= 10) //adjusts warrior strength, with check to prevent negative values
                        {
                            warriors[i].setWarStrength(-10 + warriors[i].getWarStrength());
                        }
                        if (warriors[i].getWarStrength() < 10)
                        {
                            warriors[i].setWarStrength(0);
                        }
                        if (warriors[i].getWarMorale() >= 10) //adjusts warrior morale, with check to prevent negative values
                        {
                            warriors[i].setWarMorale(-10 + warriors[i].getWarMorale());
                        }
                        if (warriors[i].getWarMorale() < 10)
                        {
                            warriors[i].setWarMorale(0);
                        }
                        cout << warriors[i].getWarName() << "'s strength down to " << warriors[i].getWarStrength() << endl;
                        cout << warriors[i].getWarName() << "'s morale down to " << warriors[i].getWarMorale() << endl;
                    }
                }
            }
            cout << endl;
        }
        if (typeRand == 2) //desertion
        {
            cout << endl;
            cout << "Your men speak of desertion." << endl;
            cout << "This campaign is taking a very long time and the soldiers are tired and sad. Some decide to leave." << endl;
            cout << endl;
            
            if (heroes[heroIndex].getArmySize() >= 10) //adjusts hero army size, with check to prevent negative values
            {
                heroes[heroIndex].setArmySize(-10 + heroes[heroIndex].getArmySize());
            }
            if (heroes[heroIndex].getArmySize() < 10) //check for no seg fault
            {
                heroes[heroIndex].setArmySize(0);
            }
            cout << "Your army size is down to " << heroes[heroIndex].getArmySize() << endl;
            
            for (int i = 0; i < warriors.size(); i++)
            {
                for (int j = 0; j < 4; j++) //nested for loop, again checking for player hero warriors
                {
                    if (warriors[i].getWarName() == heroes[heroIndex].getWarriors(j)) //if names are consistent
                    {
                        if (warriors[i].getWarLoyalty() >= 10) //adjusts warrior loyalty
                        {
                            warriors[i].setWarLoyalty(-10 + warriors[i].getWarLoyalty());
                        }
                        if (warriors[i].getWarLoyalty() < 10) //check to ensure no negatives or seg faults
                        {
                            warriors[i].setWarLoyalty(0);
                        }
                        cout << warriors[i].getWarName() << "'s loyalty down to " << warriors[i].getWarLoyalty() << endl;
                    }
                }
            }
            cout << endl;
        }
        if (typeRand == 3)
        {
            cout << endl;
            cout << "Your heroic cause has won the hearts of many noble and wealthy benefactors!" << endl;
            cout << "They generously donate funds to your cause." << endl;
            cout << endl;
            
            heroes[heroIndex].setMoney(heroes[heroIndex].getMoney() * 2); //pretty simple, just doubles player hero money value
            cout << "Your funds are now " << heroes[heroIndex].getMoney() << "!" << endl;
            cout << endl;
        }
        if (typeRand == 4)
        {
            cout << endl;
            cout << "The war effort has taken its toll on the smallfolk. Many seek alms or aid." << endl;
            cout << "You decide to offer shelter to some refugees." << endl;
            cout << endl;
            
            heroes[heroIndex].setArmySize(10 + heroes[heroIndex].getArmySize()); //increases army size by 10
            cout << "Your army size has increased to " << heroes[heroIndex].getArmySize() << endl;
            for (int i = 0; i < warriors.size(); i++)
            {
                for (int j = 0; j < 4; j++) //nested for loop, again checking for player hero warriors
                {
                    if (warriors[i].getWarName() == heroes[heroIndex].getWarriors(j)) //if name match
                    {
                        warriors[i].setWarLoyalty(10 + warriors[i].getWarLoyalty()); //increases warrior loyalty by 10
                        cout << warriors[i].getWarName() << "'s loyalty rose to " << warriors[i].getWarLoyalty() << endl;
                    }
                }
            }
            cout << endl;
        }
    }
    else //otherwise, does nothing (70% chance this being the case)
    {
        
    }
}
void Game::mandDaenerys() //function for daenerys dragon warriors
{
    if (heroes[5].getIsAlive() == true)
    {
        heroes[5].setArmySize(heroes[5].getArmySize() + 5000); //increase her army size by 5000
        if (heroes[5].getName() == heroes[heroIndex].getName()) //if players is Daenerys
        {
            cout << "Your army increased in size to " << heroes[heroIndex].getArmySize() << "!" << endl;
        }
    }
}
void Game::mandStannis() //function to kill stannis
{
    if (heroes[1].getIsAlive() == true) //if stannis is alive
    {
        string F_respect;
        cout << "Stannis has retired. Press F to pay respects." << endl;
        do{
            cin >> F_respect; //player can input F or f
            if (F_respect == "F" || F_respect == "f")
            {
                cout << "Mood." << endl; //outputs mood
            }
            else //otherwise
            {
                cout << "Have you no respect?! Press F to pay respects." << endl; //forces player to try again
            }
        }
        while (F_respect != "F" && F_respect != "f"); //prevents the user from continuing onwards until they have payed respect
        
        for (int i = 0; i < warriors.size(); i++) //nested for loop, iterates through the warriors
        {
            for (int j = 0; j < 4; j++)
            {
                if (warriors[i].getWarName() == heroes[1].getWarriors(j)) //if warrior name matches up
                {
                    if (warriors[i].getWarName() == "Davos Seaworth") //if Stannis has the warrior named Davos
                    {
                        warriors[i].setWarFree(true); //frees Davos
                        cout << "Davos Seaworth now roams free." << endl;
                    }
                    if (warriors[i].getWarName() == "Melisandre") //if Stannis has the warrior named Melisandre
                    {
                        warriors[i].setWarFree(true); //frees Melisandre
                        cout << "The red witch Melisandre has left Stannis to search for Azor Ahai." << endl;
                    }
                }
            }
        }
    }
    heroes[1].setIsAlive(false); //kills stannis
    cout << endl;
}
void Game::mandSansa() //function for arya joining sansa
{
    if (heroes[3].getIsAlive() == true) //function to check if Sansa is alive, then give her Arya as a warrior
    {
        cout << "Arya Stark has reunited with her sister, Sansa Stark." << endl;
        cout << endl;
    }
}
void Game::mandCersei() //function to free Jaime from Cersei
{
    if (heroes[0].getIsAlive() == true) //if Cersei is alive
    {
        for (int i = 0; i < warriors.size(); i++) //nested for loop to find Jaime amongst Cersei's warriors
        {
            for (int j = 0; j < 4; j++)
            {
                if (warriors[i].getWarName() == heroes[0].getWarriors(j)) //checks for
                {
                    if (warriors[i].getWarName() == "Jaime Lannister") //when Jaime is encountered
                    {
                        warriors[i].setWarFree(true); //frees Jaime
                        cout << "Jaime Lannister has left Cersei. He is now a roaming warrior." << endl;
                        cout << endl;
                    }
                }
            }
        }
    }
}
void Game::whiteWalkers() //function for white walkers to fight
{
    //checks player condition
    //gives player opportunity not to fight Walkers for 5 turns
    //starts fight
    double heroPower;
    double StrMor;
    double CitInf;
    double HasDra;
    string yesOrNo;
    srand(time(0));
    
    do{
        cout << "Sad news! The WHITE WALKERS are approaching our location. Would you like to battle them now? (Y/N):" << endl;
        cin >> yesOrNo;
        if (yesOrNo == "Y" || yesOrNo == "y") //if choose to battle
        {
            heroPower = 1.0 * heroes[heroIndex].getArmySize(); //sets hero power to army size
            for (int i = 0; i < warriors.size(); i++) //iterate through warriors
            {
                for (int j = 0; j < 4; j++)
                {
                    if (warriors[i].getWarName() == heroes[heroIndex].getWarriors(j))
                    {
                        StrMor += (1.0 * warriors[i].getWarStrength()) * (1.0 * warriors[i].getWarMorale() / 50); //find value from warrior morale/strength
                        if (warriors[i].getWarDragonGlass() == true)
                        {
                            HasDra = 1.0 * 10000; //gets your warriors dragonglass
                        }
                    }
                }
            }
            CitInf = 1.0 * heroes[heroIndex].getInfluence();
            heroPower += CitInf + StrMor + HasDra; //combines previous values to get new hero power
            cout << "Your hero power is " << heroPower << "!" << endl;
            cout << endl;
            double doYouWin = ((1 - exp(-(heroPower / 30000)))) * 100; //calculates winning chance
            cout << "Odds of winning are: " << doYouWin << " percent." << endl;
            bool probWin = (1 + rand() % 100) < doYouWin; //true if random number (1-100) is less than win chance
            
            int lossCount = 0;
            do{
                if (probWin == true) //if rand was less than num losses
                {
                    cout << "The White Walkers are defeated! Congratulations!" << endl;
                    setWalkersAreAlive(false); //walkers die
                    break; //ends loop
                }
                if (probWin == false) //if rand was greater than num losses
                {
                    lossCount++; //increment number of losses
                    cout << "Attempt #" << lossCount << " has failed..." << endl;
                }
            }
            while (lossCount < 3); //gives three chances to win
            if (lossCount >= 3) //if lost three times
            {
                cout << "I'm terribly sorry, Your Grace." << endl;
                cout << endl;
                heroes[heroIndex].setIsAlive(false); //retires main hero
            }
        }
        if (yesOrNo == "N" || yesOrNo == "n") //if no battle
        {
            setDenyBattle(getDenyBattle() + 1); //increases denial by 1
            if (getDenyBattle() < 4) //gives number of denies left
            {
                cout << "You can only stave off the dead for " << (5 - getDenyBattle()) << " more turns..." << endl;
            }
            if (getDenyBattle() == 4) //warns hero if denying again will lose them the game
            {
                cout << "The dead are very nearby." << endl;
            }
        }
    }
    while(yesOrNo != "Y" && yesOrNo != "y" && yesOrNo != "N" && yesOrNo != "n"); //while answer is invalid
    
    if (getDenyBattle() >= 5) //if player has denied 5 times
    {
        cout << "Too late! They are upon us!" << endl;
        cout << endl;
        heroes[heroIndex].setIsAlive(false); //retires player, ends game
    }
}
bool Game::getHeroIsAlive() //getter, finds if main hero is alive
{
    if (heroes[heroIndex].getIsAlive() == true)
    {
        return true;
    }
    if (heroes[heroIndex].getIsAlive() == false)
    {
        return false;
    }
}
bool Game::getWalkersAreAlive() //getter
{
    return alive;
}
bool Game::setWalkersAreAlive(bool new_alive) //setter
{
    alive = new_alive;
}
////////////////////////////////////////////////////////////////////////////////

int main()
{
    vector<Hero> heroes;
    heroes.resize(6); //makes size of heroes vector 6
    
    bool whiteWalkersAlive = true;
    int turnCount = 1;
    
    Map mapGot("mapGOT.txt"); //map object
    mapGot.readCity("citiesGOT.txt"); //reads cities file and fills vector
    
    Game turn; //game object
    
    turn.setDragonGlass(); //sets dragonglass
    turn.readHero("heroesGOT.txt"); //reads hero file
    turn.readWarrior("warriorsGOT.txt"); //reads warriors file
    turn.readMap("mapGOT.txt"); //reads map file
    
    string playerName;
    string yesNo;
    string playerChoice;
    
    
    cout << "          ######                                   " << endl;
    cout << "         #      #                                  " << endl;
    cout << "         #          ####   ##     ##  #####        " << endl;
    cout << "         #  #####  #    #  # #   # #  #            " << endl;
    cout << "         #      #  ######  #  # #  #  ####         " << endl;
    cout << "         #      #  #    #  #   #   #  #            " << endl;
    cout << "          ######   #    #  #       #  #####        " << endl;     
    cout << "                                                   " << endl;
    cout << "                     #####  ######                 " << endl;
    cout << "                     #   #  #                      " << endl;
    cout << "                     #   #  ####                   " << endl;
    cout << "                     #   #  #                      " << endl;
    cout << "                     #####  #                      " << endl;
    cout << "##########                                         " << endl;
    cout << "    #                                              " << endl;
    cout << "    #  #    #  #####   ######  #    #  #####  #####" << endl;
    cout << "    #  #    #  #    #  #    #  # #  #  #      #    " << endl;
    cout << "    #  ######  #####   #    #  #  # #  ####   #####" << endl;
    cout << "    #  #    #  #  #    #    #  #   ##  #          #" << endl;
    cout << "    #  #    #  #   #   ######  #    #  #####  #####" << endl;
    cout << endl;
    
    cout << "Welcome to the G A M E of T H R O N E S!" << endl;
    cout << "State your name, Your Grace:" << endl;
    cin >> playerName;
    do{
        cout << "Would you like to choose a hero " << playerName << ", Your Grace?(Y/N):" << endl;
        cin >> yesNo;
        if (yesNo == "Y" || yesNo == "y") //sets players hero index to chosen hero
        {
            do{
                cout << "Please choose from the following heroes:" << endl;
                cout << "1. Cersei Lannister" << endl;
                cout << "2. Stannis Baratheon" << endl;
                cout << "3. Jon Snow" << endl;
                cout << "4. Sansa Stark" << endl;
                cout << "5. Euron Greyjoy" << endl;
                cout << "6. Daenerys Targaryen" << endl;
                cin >> playerChoice;
                cout << endl;
                if (playerChoice == "1")
                {
                    cout << "'I am a lioness. I will not cringe for them.'" << endl;
                    cout << "You have chosen Cersei Lannister." << endl;
                    cout << endl;
                    turn.setHeroIndex(0);
                    break;
                }
                if (playerChoice == "2")
                {
                    cout << "'Kings have no friends, only subjects and enemies.'" << endl;
                    cout << "You have chosen Stannis Baratheon." << endl;
                    cout << endl;
                    turn.setHeroIndex(1);
                    break;
                }
                if (playerChoice == "3")
                {
                    cout << "'There's no shame in fear, my father told me, what matters is how we face it.'" << endl;
                    cout << "You have chosen Jon Snow." << endl;
                    cout << endl;
                    turn.setHeroIndex(2);
                    break;
                }
                if (playerChoice == "4")
                {
                    cout << "'My skin has gone from porcelain, to ivory, to steel.'" << endl;
                    cout << "You have chosen Sansa Stark." << endl;
                    cout << endl;
                    turn.setHeroIndex(3);
                    break;
                }
                if (playerChoice == "5")
                {
                    cout << "'I am the storm, my Lord. The first storm, and the last.'" << endl;
                    cout << "You have chosen Euron Greyjoy." << endl;
                    cout << endl;
                    turn.setHeroIndex(4);
                    break;
                }
                if (playerChoice == "6")
                {
                    cout << "'I'm not going to stop the wheel. I'm going to break the wheel.'" << endl;
                    cout << "You have chosen Daenerys Targaryen." << endl;
                    turn.setHeroIndex(5);
                    break;
                }
            }
            while (playerChoice != "1" && playerChoice != "2" && playerChoice != "3" && playerChoice != "4" && playerChoice != "5" && playerChoice != "6");
        }
        if (yesNo == "N" || yesNo == "n") //sets player values to chosen values
        {
            cout << "Your Grace " << playerName << ", you have chosen to go on this journey alone." << endl;
            cout << "Please provide starting values for your adventure." << endl;
            turn.createHero();
            turn.setHeroIndex(6);
        }
    }
    while (yesNo != "Y" && yesNo != "y" && yesNo != "N" && yesNo != "n");
    
    int index = turn.getHeroIndex();
    heroes[index].setIsAlive(true);
    
    //while player is alive
    do{
        cout << "-----------------------------------------------" << endl;
        cout << "This is the start of turn " << turnCount << ": " << endl;
        cout << endl;
        
        //display minimap
        turn.miniMap();
        cout << endl;
        
        //ask what to do
        turn.choice();
        cout << endl;
        
        //update other heroes locations
        turn.updateHeroes();
        
        //check encounters main hero
        //turn.proximity();
        if (turn.proximity() == true)
        {
            turn.combat();
        }
        
        //check encounters other heroes
        turn.enemy_combat();
        
        //update points and ownership
        
        
        //random events
        turn.random();
        cout << endl;
        
        //mandatory events
        if (turnCount == 9)
        {
            turn.mandDaenerys();
            turn.mandStannis();
            turn.mandSansa();
            turn.mandCersei();
        }
        
        //if meet conditions, battle white walkers
        if (turnCount >= 1 || turn.winCondition() == true)
        {
            turn.whiteWalkers();
        }
        
        //update game turn
        turnCount++;
    }
    while(turn.getHeroIsAlive() == true && turn.getWalkersAreAlive() == true);
    
    if (turn.getHeroIsAlive() == false) //if game is lost
    {
        cout << "/////////////////////////////////" << endl;
        cout << "/                               /" << endl;
        cout << "/           GAME OVER           /" << endl;
        cout << "/                               /" << endl;
        cout << "/  RETURN OF THE WHITE WALKERS  /" << endl;
        cout << "/                               /" << endl;
        cout << "/////////////////////////////////" << endl;
    }
    
    if(turn.getHeroIsAlive() == true) //if game is won
    {
        cout << "_______________                                      " << endl;
        cout << "                                                     " << endl;
        cout << "         It was in the War of the Five Kings         " << endl;
        cout << " that the aforesaid personages lived and quarrelled; " << endl;
        cout << "     good or bad, handsome or ugly, rich or poor,    " << endl;
        cout << "             they are all equal now.                 " << endl;
        cout << "                                                     " << endl;
        cout << "                                      _______________" << endl;
    }
}