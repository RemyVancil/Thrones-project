#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include "Game.h"
#include "Map.h"
#include "Hero.h"
#include "Warrior.h"
#include "City.h"
#include "split.h"
using namespace std;

Game::Game() //default constructor
{
    denyBattle = 0;
    heroIndex = -1;
    alive = true;
    points = 0;
    tilesOwned = 0;
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
void Game::checkDragonGlass(int row, int col) //checks for dragonglass
{
    string number;
    if (gameDragonGlass[row][col] == true)
    {
        cout << "Great news! You have stumbled upon Dragonglass." << endl;
        cout << "Choose which one of your warriors would you like to equip with Dragonglass (enter their number):" << endl;
        
        int count = 0;;
        for (int i = 0; i < warriors.size(); i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (warriors[i].getWarName() == heroes[heroIndex].getWarriors(j))
                {
                    count++;
                    cout << warriors[i].getWarName() << " (" << j + 1 << ")" << endl;
                }
            }
        }
        if (count == 0)
        {
            cout << "I doesn't look like you have any warriors with you." << endl;
            cout << "We'll just stash the dragonglass here for now. Come back for it later!" << endl;
        }
        if (count == 1)
        {
            do{
                cin >> number; //function to decide which hero gets the dragonglass
                if (number == "1")
                {
                    for (int f = 0; f < warriors.size(); f++)
                    {
                        if (warriors[f].getWarName() == heroes[heroIndex].getWarriors(0))
                        {
                            warriors[f].setWarDragonGlass(true);
                            cout << warriors[f].getWarName() << " obtained the dragonglass!" << endl;
                        }
                    }
                    gameDragonGlass[row][col] = false;
                }
            }
            while(number != "1");
        }
        if (count == 2)
        {
            do{
                cin >> number; //function to decide which hero gets the dragonglass
                if (number == "1")
                {
                    for (int f = 0; f < warriors.size(); f++)
                    {
                        if (warriors[f].getWarName() == heroes[heroIndex].getWarriors(0))
                        {
                            warriors[f].setWarDragonGlass(true);
                            cout << warriors[f].getWarName() << " obtained the dragonglass!" << endl;
                        }
                    }
                    gameDragonGlass[row][col] = false;
                }
                if (number == "2")
                {
                    for (int f = 0; f < warriors.size(); f++)
                    {
                        if (warriors[f].getWarName() == heroes[heroIndex].getWarriors(1))
                        {
                            warriors[f].setWarDragonGlass(true);
                            cout << warriors[f].getWarName() << " obtained the dragonglass!" << endl;
                        }
                    }
                    gameDragonGlass[row][col] = false;
                }
            }
            while(number != "1" && number != "2");
        }
        if (count == 3)
        {
            do{
                cin >> number; //function to decide which hero gets the dragonglass
                if (number == "1")
                {
                    for (int f = 0; f < warriors.size(); f++)
                    {
                        if (warriors[f].getWarName() == heroes[heroIndex].getWarriors(0))
                        {
                            warriors[f].setWarDragonGlass(true);
                            cout << warriors[f].getWarName() << " obtained the dragonglass!" << endl;
                        }
                    }
                    gameDragonGlass[row][col] = false;
                }
                if (number == "2")
                {
                    for (int f = 0; f < warriors.size(); f++)
                    {
                        if (warriors[f].getWarName() == heroes[heroIndex].getWarriors(1))
                        {
                            warriors[f].setWarDragonGlass(true);
                            cout << warriors[f].getWarName() << " obtained the dragonglass!" << endl;
                        }
                    }
                    gameDragonGlass[row][col] = false;
                }
                if (number == "3")
                {
                    for (int f = 0; f < warriors.size(); f++)
                    {
                        if (warriors[f].getWarName() == heroes[heroIndex].getWarriors(2))
                        {
                            warriors[f].setWarDragonGlass(true);
                            cout << warriors[f].getWarName() << " obtained the dragonglass!" << endl;
                        }
                    }
                    gameDragonGlass[row][col] = false;
                }
            }
            while(number != "1" && number != "2" && number != "3");
        }
        if (count == 4)
        {
            do{
                cin >> number; //function to decide which hero gets the dragonglass
                if (number == "1")
                {
                    for (int f = 0; f < warriors.size(); f++)
                    {
                        if (warriors[f].getWarName() == heroes[heroIndex].getWarriors(0))
                        {
                            warriors[f].setWarDragonGlass(true);
                            cout << warriors[f].getWarName() << " obtained the dragonglass!" << endl;
                        }
                    }
                    gameDragonGlass[row][col] = false;
                }
                if (number == "2")
                {
                    for (int f = 0; f < warriors.size(); f++)
                    {
                        if (warriors[f].getWarName() == heroes[heroIndex].getWarriors(1))
                        {
                            warriors[f].setWarDragonGlass(true);
                            cout << warriors[f].getWarName() << " obtained the dragonglass!" << endl;
                        }
                    }
                    gameDragonGlass[row][col] = false;
                }
                if (number == "3")
                {
                    for (int f = 0; f < warriors.size(); f++)
                    {
                        if (warriors[f].getWarName() == heroes[heroIndex].getWarriors(2))
                        {
                            warriors[f].setWarDragonGlass(true);
                            cout << warriors[f].getWarName() << " obtained the dragonglass!" << endl;
                        }
                    }
                    gameDragonGlass[row][col] = false;
                }
                if (number == "4")
                {
                    for (int f = 0; f < warriors.size(); f++)
                    {
                        if (warriors[f].getWarName() == heroes[heroIndex].getWarriors(3))
                        {
                            warriors[f].setWarDragonGlass(true);
                            cout << warriors[f].getWarName() << " obtained the dragonglass!" << endl;
                        }
                    }
                    gameDragonGlass[row][col] = false;
                }
            }
            while(number != "1" && number != "2" && number != "3" && number != "4");
        }
    }
}
// void Game::setWanderingWarrior()
// {
//     srand(time(NULL));
//     int randRow;
//     int randCol;
//     Map tile("mapGOT.txt");
    
//     for (int i = 0; i < warriors.size(); i++)
//     {
//         if (warriors[i].getWarFree() == true)
//         {
//             randRow = rand() % 25; //gives random y val
//             randCol = rand() % 16; //gives random x val
//             warriors[i].setWarRow(randRow);
//             warriors[i].setWarColumn(randCol);
//             if (tile.isWater(randRow, randCol) == true)
//             {
//                 warriors[i].setWarShip(true);
//             }
//         }
//     }
// }
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
void Game::cityRumors() //function for actions within a city
{
    string choice;
    int distance = 1000;
    int new_distance;
    string buyKnights;
    
    cout << "You have arrived in a city. What would you like to do?" << endl;
    cout << "Listen to rumors (1), buy knights (2), search for dragonglass (3), or do nothing (4)?" << endl;
    do{
        cin >> choice;
        if (choice == "1") //listen to rumors
        {
            
        }
        if (choice == "2")
        {
            do{
                cout << "Would you like to buy a knight for 20 gold (Y/N)?" << endl; //allows the user to exchange money for a larger army size
                cin >> buyKnights;
                if (buyKnights == "Y" || buyKnights == "y")
                {
                    if (heroes[heroIndex].getMoney() >= 20) //verifies that user has enough money to buy knights
                    {
                        heroes[heroIndex].setArmySize(heroes[heroIndex].getArmySize() + 1);
                        heroes[heroIndex].setMoney(heroes[heroIndex].getMoney() - 20);
                        cout << "Your army size is " << heroes[heroIndex].getArmySize() << " and your gold is down to " << heroes[heroIndex].getMoney() << endl;
                        cout << endl;
                    }
                    else{
                        cout << "You don't have enough money." << endl;
                        buyKnights = "n"; //breaks the do while loop
                    }
                }
            }
            while (buyKnights != "N" && buyKnights != "n"); //while the player has not said that they don't want to buy more knights
        }
        if (choice == "3") //search for dragonglass
        {
            
        }
        if (choice == "4") //do nothing
        {
            
        }
    }
    while (choice != "1" && choice != "2" && choice != "3" && choice != "4");
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
                            checkDragonGlass(heroes[index].getRow(), heroes[index].getColumn());
                            if (tile.isCity(menuRow, c) == true) //if in city, allow to check for rumors
                            {
                                cityRumors();
                            }
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
                            checkDragonGlass(heroes[index].getRow(), heroes[index].getColumn());
                            if (tile.isCity(r, menuColumn) == true) //if in city, allow to check for rumors
                            {
                                cityRumors();
                            }
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
                            checkDragonGlass(heroes[index].getRow(), heroes[index].getColumn());
                            if (tile.isCity(menuRow, c) == true) //if in city, allow to check for rumors
                            {
                                cityRumors();
                            }
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
                            checkDragonGlass(heroes[index].getRow(), heroes[index].getColumn());
                            if (tile.isCity(r, menuColumn) == true) //if in city, allow to check for rumors
                            {
                                cityRumors();
                            }
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
                if (moveRand == 1) //if 1, sends hero north if they have open space to north
                {
                    if (heroes[i].getShip() == true || tile.isWater((-1 + heroes[i].getRow()), heroes[i].getColumn()) == false)
                    {
                        if (heroes[i].getRow() > 1)
                        {
                            heroes[i].setRow(-1 + heroes[i].getRow());
                        }
                    }
                }
                if (moveRand == 2) //if 2, sends hero south if they have open space to south
                {
                    if (heroes[i].getShip() == true || tile.isWater((1 + heroes[i].getRow()), heroes[i].getColumn()) == false)
                    {
                        if (heroes[i].getRow() < 25)
                        {
                            heroes[i].setRow(1 + heroes[i].getRow());
                        }
                    }
                }
                if (moveRand == 3) //if 3, sends hero west if they have open space to west
                {
                    if (heroes[i].getShip() == true || tile.isWater(heroes[i].getRow(), (-1 + heroes[i].getColumn())) == false)
                    {
                        if (heroes[i].getColumn() > 1)
                        {
                            heroes[i].setColumn(-1 + heroes[i].getColumn());
                        }
                    }
                }
                if (moveRand == 4) //if 4, sends hero east if they have open space to east
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
            
            int lossCount = 0;
            do{
                bool probWin = (1 + rand() % 100) < doYouWin; //true if random number (1-100) is less than win chance
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