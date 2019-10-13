/* File:   Game.h
 * Author: Mario Gomez
 * Created on April 8, 2017, 7:18 PM
 * Purpose: */

//Preprocessor Directives
#ifndef BUNNYSIMULATOR_GAME_H
#define BUNNYSIMULATOR_GAME_H

//User Libraries
#include "BunnyWomb.h"
#include "Functions.h"

//System Libraries
using namespace std;

//Class definition
class Game: public Functions, BunnyWomb{
    //variables
protected:
    int saveCount;
    bool playing, played;
    string newName, newColor;
    char newGender;

public: //Constructor
    Game();
    //virtual destructor
    virtual ~Game();
    //functions
    void MainMenu();
    void campaignSubMenu();
    void ActionMenu();
    //accessors
    bool getStart(){return this->playing;}
    bool getPlay(){return this->playing;}
    //mutator
    void setPlay(){this->playing = true;}
};

#endif //BUNNYSIMULATOR_GAME_H
