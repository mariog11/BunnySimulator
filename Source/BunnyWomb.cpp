/* File:   BunnyWomb.cpp
 * Author: Mario Gomez
 * Created on April 8, 2017, 7:18 PM
 * Purpose: */

//User Library
#include "../Headers/BunnyWomb.h"

//Constructor
BunnyWomb::BunnyWomb(){
    this->name = "";
    this->color = "";
    this->level = 0;
    this->XP = 0;
    this->maxChildren = 0;
    this->maxFoodSupply = 0;
    this->maxItemSupply = 0;
    this->childCount = 0;
    this->itemCount = 0;
    this->foodCount = 0;
    this->XP2LevelUp = 0;
    this->HP = 0;
    this->HPMax = 0;
    this->damageMin = 0;
    this->damageMax = 0;
    this->defense = 0;
}

//Destructor
BunnyWomb::~BunnyWomb(){

}

void BunnyWomb::setNewBunny(int level, string name, string color, char gender){
    this->name = name;
    this->color = color;
    this->gender = gender;
    this->level = level;
    this->maxChildren = 41;
    this->maxFoodSupply = 310;
    this->maxItemSupply = 21;
    this->childCount = 0;
    this->itemCount = 0;
    this->foodCount = 0;
    this->XP = 0;
    this->XP2LevelUp = ((50/3)* ((level*level*level -
            6 * level*level) + 17 * level - 12))+100;
    this->HP = 100;
    this->HPMax = 100;
    this->damageMin = 5;
    this->damageMax = 11;
    this->defense = 10;

    setItemNames(this->maxItemSupply);

    cout<<"\n\n\nWelcome, "<<this->name<<"!"
        <<"\nYou are level "<<this->level
        <<"\nYou have "<<this->XP<<" XP and need "
        <<this->XP2LevelUp<<" XP to get to level "<<level+1<<endl;
}

void BunnyWomb::setItemNames(int maxItems){

    string Hat = "Hat";
    string Glasses = "Glasses";
    string Foot = "Foot";
    string Bottle = "Bottle";
    string Toy = "Toy";
    string Thimble = "Thimble";

    //used to randomly initialize list of items
    for(int i = 0; i + getItemCount() < maxItems; i++){
        int itemAssigner = rand()%22+1;

        if(itemAssigner == 3 ||itemAssigner == 6 ||itemAssigner == 9 ||
           itemAssigner == 12||itemAssigner == 18||itemAssigner == 21){
           itemNames.push_back(Hat);
        }
       else if(itemAssigner == 1 ||itemAssigner == 7 ||itemAssigner == 13||
               itemAssigner == 19||itemAssigner == 22){
               itemNames.push_back(Glasses);
       }
       else if(itemAssigner == 2 ||itemAssigner == 5 ||itemAssigner == 8 ||
               itemAssigner == 14){
               itemNames.push_back(Foot);
       }
       else if(itemAssigner == 4 ||itemAssigner == 10||itemAssigner == 15){
               itemNames.push_back(Bottle);
       }
       else if(itemAssigner == 16||itemAssigner == 20){
               itemNames.push_back(Toy);
       }
       else if(itemAssigner == 11){
               itemNames.push_back(Thimble);
           }
    }
}