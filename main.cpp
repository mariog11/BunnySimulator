/* File:   main.cpp
 * Author: Mario Gomez
 * Created on April 8, 2017, 7:18 PM
 * Purpose: Run instance of game program */

//User Libraries
#include "Headers/game.h"
#include "Headers/Functions.h"
#include "Headers/BunnyWomb.h"
using namespace std;

//Execution Begins here!
int main(int argc, char** argv) {
    //Seed random generator
    srand(static_cast<int>(time(0)));

    //Class instantiation
    Game start;
    start.MainMenu();

    return 0;
}