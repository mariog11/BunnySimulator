/* File:   BunnyWomb.h
 * Author: Mario Gomez
 * Created on April 8, 2017, 7:18 PM
 * Purpose: */

//Preprocessor Directives
#ifndef BUNNYSIMULATOR_BUNNYWOMB_H
#define BUNNYSIMULATOR_BUNNYWOMB_H


//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;

//Class definitions
class BunnyWomb{
    //Variables
protected: char gender;
    string name, color;
    string childFile;
    int level, XP, XP2LevelUp;
    int HP, HPMax, damageMin, damageMax, defense;
    int maxItemSupply, maxFoodSupply, maxChildren;
    int itemCount, foodCount, childCount;
    list <string> itemNames;
    multiset<string> itemInvAlert, foodInvAlert;
    map<string, int> itemInv, foodInv;
    stack<string> children;
    friend class Functions;
public:
    //Constructor
    BunnyWomb();
    //Destructor
    virtual ~BunnyWomb();
    //used to initialize all data fields
    BunnyWomb(int, string, string, char);

    //Operators

    //Accessors
    const string &getName()const{return this->name;}
    const string &getColor()const{return this->color;}
    const char &getGender() const{return this->gender;}
    const int &getLevel()const{return this->level;}
    const int &getXP()const{return this->XP;}
    const int &getXPup()const{return this->XP2LevelUp;}
    const int &getHP()const{return this->HP;}
    const int &getHPmax()const{return this->HPMax;}
    const int &getDamageMin()const{return this->damageMin;}
    const int &getDamageMax()const{return this->damageMax;}
    const int &getDefense()const{return this->defense;}
    const int &getChildCount()const{return this->childCount;}
    const int &getFoodCount()const{return this->foodCount;}
    const int &getFoodSupply()const{return this->maxFoodSupply;}
    const int &getItemCount()const{return this->itemCount;}
    const int &getmaxChildren(){return this->maxChildren;}
    const int &getmaxFoodSupply(){return this->maxFoodSupply;}
    const int &getmaxItemSupply(){return this->maxItemSupply;}
    //Modifiers
    void setItemNames(int);
    void setNewBunny(int, string, string, char);
    void setName(string arg){this->name = arg;}
    void setLevel(int arg){this->level += arg;}
    void setChildCount(int arg){this->childCount = arg;}
    void setItemCount(int arg){this->itemCount = arg;}
    void setFoodCount(int arg){this->itemCount = arg;}
    void setFoodSupply(int arg){this->itemCount = arg;}
    void setXP(int arg){this->XP+=arg;}
    void setColor(string arg){this->color = arg;}
    void setGender(char arg){this->gender = arg;}
    void setXPup(int level){this->XP2LevelUp = ((50/3)* ((level*level*level -
                                                          6 * level*level) + 17 * level - 12))+100;}
    void setHP(int arg){this->HP = arg;}
    void setHPmax(int arg){this->HPMax = HP;}
    void setDamageMin(int arg){this->damageMin += arg;}
    void setDamageMax(int arg){this->damageMax += arg;}
    void setDefense(int arg){this->defense += arg;}
    void damage(int damage){this->HP -= damage;}
    void setmaxChildren(int arg){ this->maxChildren = arg;}
    void setmaxFoodSupply(int arg){this->maxFoodSupply = arg;}
    void setmaxItemSupply(int arg){this->maxItemSupply = arg;}

};


#endif //BUNNYSIMULATOR_BUNNYWOMB_H
