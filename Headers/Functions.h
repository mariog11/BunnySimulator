/* File:   Functions.h
 * Author: Mario Gomez
 * Created on April 8, 2017, 7:18 PM
 * Purpose:  */

//Preprocessor Directives
#ifndef BUNNYSIMULATOR_FUNCTIONS_H
#define BUNNYSIMULATOR_FUNCTIONS_H

//User Libraries
#include "BunnyWomb.h"
#include "Enemy.h"

//Class definition
class Functions{
    //Variables
protected:
    int response; //ARBITRARY (DELETE LATER)
    int travelOutcome;
    BunnyWomb Bunny;
    Enemy opponent;
public: //Constructor
    Functions();
    //Destructor
    virtual ~Functions();
    //functions
    void checkLevel();
    void saveGame();
    bool loadGame();
    void travel(); //randomly generated
    void shop();
    int fight();
    void rest();
    void bunnyEncounter();
    void reproduction();
    void itemEncounter();
    void enemyEncounter();
    //Operators

    //Accessors
    void getStats();
    void foodShop();
    void getItemInv();
    void getFoodInv();
    void getBabies();
    bool checkHealths();
    //Modifiers

};


#endif //BUNNYSIMULATOR_FUNCTIONS_H
