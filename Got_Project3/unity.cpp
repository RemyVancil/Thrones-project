#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Game.h"
#include "Map.h"
#include "Hero.h"
#include "Warrior.h"
#include "City.h"
using namespace std;

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
    //turn.setWanderingWarrior(); //sets warriors wandering
    
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
        if (turnCount >= 12 || turn.winCondition() == true)
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

//g++ -std=c++11 Player.cpp Team.cpp teamDriver.cpp -o firstclass
//g++ -std=c++11 City.cpp Hero.cpp Warrior.cpp Map.cpp Game.cpp unity.cpp split.cpp -o firstclass