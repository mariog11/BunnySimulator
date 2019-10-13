/* File:   Functions.cpp
 * Author: Mario Gomez
 * Created on April 8, 2017, 7:18 PM
 * Purpose: */

//user library
#include "../Headers/Enemy.h"
//constructor
Enemy::Enemy(){
    this->creature = "";
    this->HP = 0;
    this->HPmax = 0;
    this->defense = 0;
    this->damageMin =0;
    this->damageMax =0;
}

//destructor
Enemy::~Enemy(){

}

//Enemy creator
void Enemy::setEnemy(int name, int newHP, int newDef, int newDmin, int newDmax){
    string Enemies[] = {"Falcon", "Fox", "Wolf", "Human"};

    if(name == 0)
        this->creature = Enemies[0];
    else if(name == 1)
        this->creature = Enemies[1];
    else if(name == 2)
        this->creature = Enemies[2];
    else if(name == 3)
        this->creature = Enemies[3];

    this->HP = newHP;
    this->HPmax = newHP;
    this->defense = newDef;
    this->damageMin = newDmin;
    this->damageMax = newDmax;
}
