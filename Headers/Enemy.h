/* File:   BunnyWomb.h
 * Author: Mario Gomez
 * Created on April 8, 2017, 7:18 PM
 * Purpose: */

//Preprocessor Directives
#ifndef BUNNYSIMULATOR_ENEMY_H
#define BUNNYSIMULATOR_ENEMY_H


//System libraries
#include <string>
using namespace std;

//Class definition
class Enemy{
private:    string creature;
    int HP;
    int HPmax;
    int defense;
    int damageMin;
    int damageMax;
public: //Constructor
    Enemy();
    //Destructor
    virtual ~Enemy();
    //Accessors
    const string &getEnemyName() const{return this->creature;}
    const int &getEnemyHP() const{return this->HP;}
    const int &getEnemyHPmax() const{return this->HPmax;}
    const int &getEnemyDefense() const{return this->defense;}
    const int &getDamageMin() const{return this->damageMin;}
    const int &getDamageMax() const{return this->damageMax;}
    //Mutators (Mostly For Battle)
    void setEnemy(int, int, int, int, int);
    void damage(int damage){this->HP -= damage;}
    void heal(int);

};

#endif //BUNNYSIMULATOR_ENEMY_H
