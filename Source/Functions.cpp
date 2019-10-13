/* File:   Functions.cpp
 * Author: Mario Gomez
 * Created on April 8, 2017, 7:18 PM
 * Purpose: */

//user library
#include "../Headers/Functions.h"

//constructor
Functions::Functions(){

}

//destructor
Functions::~Functions(){

}

void Functions::checkLevel(){

    if(Bunny.getXP() >= Bunny.getXPup()){
        Bunny.setLevel(1);
        if(Bunny.getXP() > Bunny.getXPup()){
            int difference = Bunny.getXP() - Bunny.XP2LevelUp;

            //setting XP to Zero
            Bunny.setXP(-1*Bunny.getXP());
            Bunny.setXP(difference);

        }
        else if(Bunny.getXP() == Bunny.getXPup()){
            Bunny.setXP(-1*Bunny.getXP());
        }

        Bunny.setXPup(Bunny.getLevel());
        Bunny.setHPmax(15);
        Bunny.setHP(Bunny.getHPmax());
        Bunny.setDamageMin(15);
        Bunny.setDamageMax(15);
        Bunny.setDefense(15);

        cout<<"YOU HAVE PROMOTED TO LEVEL "<<Bunny.getLevel()<<endl;
        cout<<"NEW HP=>      "<<Bunny.getHP()<<endl;
        cout<<"CURRENT XP=>  "<<Bunny.getXP()<<endl;
        cout<<"DAMAGE MIN=>  "<<Bunny.getDamageMin()<<endl;
        cout<<"DAMAGE MAX=>  "<<Bunny.getDamageMax()<<endl;
        cout<<"DEFENSE=>     "<<Bunny.getDefense()<<endl;


        string seeResult;

        cout<<"\nPress [ENTER] to continue";
        getline(cin, seeResult);
    }
}

bool Functions::loadGame(){
    int integerStore;
    string stringStore;
    char charStore;
    bool failLoad = false;
    int loadct = 3;
    bool loadGame = true;

    do{
        try{
            loadct--;
            string FileName;

            cout<<"\n(No spaces and use .txt extension)"<<endl;
            cout<<"ENTER NAME OF ''EXISTENT'' SAVE FILE: ";
            cin.ignore();
            getline(cin, FileName);


            ifstream SAVESTATES;
            SAVESTATES.open(FileName, ios::in);

            failLoad = false;
            //LOAD NAME
            getline(SAVESTATES, stringStore);
            Bunny.setName(stringStore);
            //LOAD HP
            getline(SAVESTATES, stringStore);
            integerStore = stoi(stringStore);
            Bunny.setHP(integerStore);
            //LOAD HP max
            getline(SAVESTATES, stringStore);
            integerStore = stoi(stringStore);
            Bunny.setHPmax(integerStore);
            //LOAD LEVEL
            getline(SAVESTATES, stringStore);
            integerStore = stoi(stringStore);
            Bunny.setLevel(integerStore);
            //LOAD XP
            getline(SAVESTATES, stringStore);
            integerStore = stoi(stringStore);
            Bunny.setXP(integerStore);
            //LOAD COLOR
            getline(SAVESTATES, stringStore);
            Bunny.setColor(stringStore);
            //LOAD GENDER
            getline(SAVESTATES, stringStore);
            charStore = stringStore[0];
            Bunny.setGender(charStore);
            //LOAD CHILD COUNT
            getline(SAVESTATES, stringStore);
            integerStore = stoi(stringStore);
            Bunny.setChildCount(integerStore);
            //LOAD ITEM COUNT
            getline(SAVESTATES, stringStore);
            integerStore = stoi(stringStore);
            Bunny.setItemCount(integerStore);
            //LOAD FOOD COUNT
            getline(SAVESTATES, stringStore);
            integerStore = stoi(stringStore);
            Bunny.setItemCount(integerStore);
            //LOAD FOOD SUPPLY
            getline(SAVESTATES, stringStore);
            integerStore = stoi(stringStore);
            Bunny.setItemCount(integerStore);
            //LOAD XP
            getline(SAVESTATES, stringStore);
            integerStore = stoi(stringStore);
            Bunny.setXP(integerStore);
            //LOAD XP2UP
            getline(SAVESTATES, stringStore);
            integerStore = stoi(stringStore);
            Bunny.setXPup(Bunny.getLevel());
            //LOAD DMIN
            getline(SAVESTATES, stringStore);
            integerStore = stoi(stringStore);
            Bunny.setDamageMin(integerStore);
            //LOAD DMAX
            getline(SAVESTATES, stringStore);
            integerStore = stoi(stringStore);
            Bunny.setDamageMax(integerStore);
            //LOAD DEFENSE
            getline(SAVESTATES, stringStore);
            integerStore = stoi(stringStore);
            Bunny.setDefense(integerStore);

            SAVESTATES.close();

            Bunny.setmaxChildren(41);
            Bunny.setmaxFoodSupply(310);
            Bunny.setmaxItemSupply(21);

            //STORING CHILDREN IN NAME BUFFER
            string babyName;

            ifstream MainNames;
            ofstream NameBuffer;



            MainNames.open("NAMES.txt", ios::in);

            NameBuffer.open("nameBuffer.txt", ios::out | ios::trunc);



            int j = 0;
            //spam getline to store relevant names
            while(j < Bunny.getChildCount()){
                getline(MainNames, babyName);
                Bunny.children.push(babyName);
                j++;
            }
            //store relevant names in name buffer
            for(int j = Bunny.getChildCount(); j < 41; j++ ){
                getline(MainNames, babyName);
                NameBuffer<<babyName<<"\n";
            }



            MainNames.clear();
            MainNames.seekg(0, ios::beg);

            MainNames.close();
            NameBuffer.close();

        }
        catch(exception X){
            cout<<"\nERROR: Game could NOT be Loaded"<<endl;
            failLoad = true;
            loadGame = false;
        }
    }while(failLoad && loadct > 0);

    //LOAD ITEMS
    ifstream LOADITEMS;
    LOADITEMS.open("itemBuffer.txt");
    if(LOADITEMS){

        for (int i=0; i<Bunny.getItemCount(); ++i){
            getline(LOADITEMS, stringStore);
            Bunny.itemInvAlert.insert(stringStore);
        }

        if(Bunny.itemInvAlert.count("Hat") > 0)
            Bunny.itemInv["Hat"] = Bunny.itemInvAlert.count("Hat");
        if(Bunny.itemInvAlert.count("Glasses") > 0)
            Bunny.itemInv["Glasses"]= Bunny.itemInvAlert.count("Glasses");
        if(Bunny.itemInvAlert.count("Foot") > 0)
            Bunny.itemInv["Foot"]= Bunny.itemInvAlert.count("Foot");
        if(Bunny.itemInvAlert.count("Bottle") > 0)
            Bunny.itemInv["Bottle"]= Bunny.itemInvAlert.count("Bottle");
        if(Bunny.itemInvAlert.count("Toy") > 0)
            Bunny.itemInv["Toy"]= Bunny.itemInvAlert.count("Toy");
        if(Bunny.itemInvAlert.count("Thimble") > 0)
            Bunny.itemInv["Thimble"]= Bunny.itemInvAlert.count("Thimble");

    }

    LOADITEMS.close();

    //STORE FOOD
    ifstream LOADFOOD;
    LOADFOOD.open("foodBuffer.txt");
    if(LOADFOOD){

        for (int i=0; i<Bunny.getFoodCount(); ++i){
            getline(LOADFOOD, stringStore);
            Bunny.foodInvAlert.insert(stringStore);
        }

    }
    LOADFOOD.close();

    return loadGame;
}

void Functions::saveGame(){
    try{

        string FileName;

        cout<<"\n(No spaces and use .txt extension)"<<endl;
        cout<<"ENTER NAME OF FILE TO SAVE TO: ";
        cin.ignore();
        getline(cin, FileName);

        ofstream SAVESTATES;
        SAVESTATES.open(FileName, ios::out);

        SAVESTATES<<Bunny.getName()<<"\n";
        SAVESTATES<<Bunny.getHP()<<"\n";
        SAVESTATES<<Bunny.getHPmax()<<"\n";
        SAVESTATES<<Bunny.getLevel()<<"\n";
        SAVESTATES<<Bunny.getXP()<<"\n";
        SAVESTATES<<Bunny.getColor()<<"\n";
        SAVESTATES<<Bunny.getGender()<<"\n";
        SAVESTATES<<Bunny.getChildCount()<<"\n";
        SAVESTATES<<Bunny.getItemCount()<<"\n";
        SAVESTATES<<Bunny.getFoodCount()<<"\n";
        SAVESTATES<<Bunny.getFoodSupply()<<"\n";
        SAVESTATES<<Bunny.getXP()<<"\n";
        SAVESTATES<<Bunny.getXPup()<<"\n";
        SAVESTATES<<Bunny.getDamageMin()<<"\n";
        SAVESTATES<<Bunny.getDamageMax()<<"\n";
        SAVESTATES<<Bunny.getDefense()<<"\n";


        SAVESTATES.close();

        cout<<"\nSAVED"<<endl;
    }
    catch(exception X){
        cout<<"\nCould not Save "<<Bunny.getName()<<"'s Game"<<endl;
    }
    //SAVE CURRENT ITEM NAMEDS
    ofstream SAVEITEMS;
    SAVEITEMS.open("itemBuffer.txt");
    if(SAVEITEMS){
        multiset<string>::iterator it;

        for (multiset<string>::iterator it=Bunny.itemInvAlert.begin(); it!=Bunny.itemInvAlert.end(); ++it)
            SAVEITEMS << *it<<"\n";

    }

    SAVEITEMS.close();

    //SAVE CURRENT FOODS
    ofstream SAVEFOODS;
    SAVEFOODS.open("foodBuffer.txt");
    if(SAVEFOODS){
        multiset<string>::iterator it;

        for (multiset<string>::iterator it=Bunny.foodInvAlert.begin(); it!=Bunny.foodInvAlert.end(); ++it)
            SAVEFOODS << *it<<"\n";

    }

    SAVEFOODS.close();

}

void Functions::travel(){
    string seeResult;

    cout<<"Traveling..."<<endl;
    cout<<"Press [ENTER] to see result";
    cin.ignore();
    getline(cin, seeResult);

    travelOutcome = rand() % 4 + 1;

    switch(travelOutcome){
        case 1: bunnyEncounter();
            break;
        case 2: itemEncounter();
            break;
        case 3: enemyEncounter();
            break;
        case 4: cout<<"\nYou found nothing on your travel."<<endl;
            cout<<"-3 XP gained"<<endl;
            Bunny.setXP(-3);
            cout<<"Press [ENTER] to resume";
            getline(cin, seeResult);
            break;
    }
}

void Functions::bunnyEncounter(){

    int procreate;
    int randBunnyGender;
    char Gender;
    string GenderOutput;
    string resume;

    randBunnyGender = rand()% 6 + 1;
    if(randBunnyGender == 1 ||randBunnyGender == 3 || randBunnyGender == 5){
        Gender = 'M';
        GenderOutput = "male";
    }
    else if(randBunnyGender == 2 ||randBunnyGender == 4 || randBunnyGender == 6){
        Gender = 'F';
        GenderOutput = "female";
    }

    cout<<"\nYou have encountered a "<<GenderOutput<<" bunny in the wild"<<endl;
    if(Gender != Bunny.getGender()){
        cout<<"It is of opposite gender, would you like to reproduce?"<<endl;
        cout<<"\n(1. = YES | 2. = NO)"<<endl;
        cout<<"ENTER CHOICE: ";
        cin>>procreate;

        while(!cin || procreate < 1 ||procreate > 2){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//discard input
            cout << "Invalid input; please re-enter: ";
            cin>>procreate;
        }

        if(procreate == 1){
            reproduction();
            cout<<"Press [ENTER] to resume";
            getline(cin, resume);
        }
        else{
            cout<<"You fled"<<endl;
            cout<<"Press [ENTER] to resume";
            cin.ignore();
            getline(cin, resume);
        }
    }
    else{
        cout<<"It is the same gender as you"<<endl
            <<"You fled.";
        cout<<"\nPress [ENTER] to resume";
        getline(cin, resume);
    }
}

void Functions::reproduction(){
    int i;
    int randLitterSize = rand()% 9 + 1;
    int XPforBabies = 25;
    string babyName;
    string resume;

    ifstream MainNames;
    fstream NameBuffer;

    cout<<"\nConceiving..."<<endl;
    cout<<"Press [ENTER] to see litter";
    getline(cin, resume);

    MainNames.open("NAMES.txt", ios::in);

    NameBuffer.open("nameBuffer.txt", ios::out | ios::trunc);


    if(Bunny.getChildCount() == 0){
        //Jam all baby names in to buffer
        for(int j = 0; j <= 41; j++){
            getline(MainNames, babyName);
            NameBuffer<<babyName<<"\n";
        }
    }
    else{
        int j = 0;
        //spam getline to store relevant names
        while(j < Bunny.getChildCount()){
            getline(MainNames, babyName);
            j++;
        }
        //store relevant names in name buffer
        for(int j = Bunny.getChildCount(); j < 41; j++ ){
            getline(MainNames, babyName);
            NameBuffer<<babyName<<"\n";
        }

    }

    MainNames.clear();
    MainNames.seekg(0, ios::beg);

    MainNames.close();
    NameBuffer.close();

    // NOTE: Open in read-mode
    NameBuffer.open("nameBuffer.txt", ios::in);
    //CurrentSpawn.open("currentChildren.txt");

    if(MainNames){
        cout<<"\n       LITTER"<<endl;
        cout<<"----------------------"<<endl;
        for(i = 0; i < randLitterSize; i++){
            getline(NameBuffer, babyName);
            Bunny.children.push(babyName);
            cout<<i<<". "<<babyName<<endl;
        }
        this->Bunny.childCount += (i);

        Bunny.setXP(XPforBabies);
        cout<<"\n+ "<<XPforBabies<<" XP gained"<<endl;
    }
    NameBuffer.close();
}


void Functions::itemEncounter(){
    int j;
    string resume;
    string topItem;

    cout<<"\nWait... it looks like you found something"<<endl;
    cout<<"Press [ENTER] to see item";
    getline(cin, resume);



    if(!(Bunny.itemNames.empty())){
        topItem = Bunny.itemNames.front();
        Bunny.itemInvAlert.insert(topItem);
        Bunny.itemInv[topItem] += 1;

        Bunny.itemNames.pop_front();

        cout<<"\n    ITEM FOUND"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0. "<<topItem<<endl;

        this->Bunny.itemCount += 1;
    }
    else{
        cout<<"\nFalse alarm, nothing was found"<<endl;
    }
}




void Functions::enemyEncounter(){
    int enemyRandomizer = rand()% 4;
    int fightMenu;
    string resume;

    int enemyHP = Bunny.getHPmax();
    int enemyDef = Bunny.getDefense();
    int enemyDmin = Bunny.getDamageMin();
    int enemyDmax = Bunny.getDamageMax();


    if(enemyRandomizer == 0)
        opponent.setEnemy(enemyRandomizer, enemyHP, enemyDef, enemyDmin, enemyDmax);
    if(enemyRandomizer == 1)
        opponent.setEnemy(enemyRandomizer, enemyHP + 1, enemyDef + 1, enemyDmin + 1, enemyDmax + 1);
    if(enemyRandomizer == 2)
        opponent.setEnemy(enemyRandomizer, enemyHP + 2, enemyDef + 2, enemyDmin + 2, enemyDmax + 2);
    if(enemyRandomizer == 3)
        opponent.setEnemy(enemyRandomizer, enemyHP + 3, enemyDef + 3, enemyDmin + 3, enemyDmax + 3);

    cout<<"\nYou've encountered an predator..."<<endl;
    cout<<"Press [ENTER] to see opponent";
    getline(cin, resume);

    cout<<"\n\nWild "<<opponent.getEnemyName()<<" has appeared!"<<endl;
    cout<<"HP=> "<<opponent.getEnemyHP()<<endl;

    while(fightMenu != 3 ){
        if(Bunny.getHP() <= 0 || opponent.getEnemyHP() <= 0)
            break;

        cout<<"\n    FIGHT MENU"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"  1. Fight   2. Food"<<endl;
        cout<<"  3. Flee    "<<endl;
        cout<<"ENTER CHOICE: ";
        cin>>fightMenu;

        switch(fightMenu){
            case 1: fight();
                break;
            case 2: getFoodInv();
                break;
            case 3: cout<<"You cowered"<<endl;
                cout<<"Press [ENTER] to continue";
                getline(cin, resume);
                break;
        }

    }

    if(opponent.getEnemyHP() <=0){
        int XPboost = opponent.getEnemyHPmax() - Bunny.getHPmax();
        Bunny.setXP(25 + XPboost);
        Bunny.setHP(Bunny.getHPmax());
        cout<<"\nCONGRATULATIONS! You've eluded a "<<opponent.getEnemyName()<<"!"<<endl;
        cout<<"+"<<(25 + XPboost)<<" gained"<<endl;
    }
    else if(Bunny.getHP() <= 0){
        cout<<"SORRY! You've fallen prey to a "<<opponent.getEnemyName()<<"!"<<endl;
        Bunny.setHP(Bunny.getHPmax());
    }

}

int Functions::fight(){
    int attackSelector;
    int defenseSelector;
    int OPattackSelector= rand()% 6 + 1;
    int OPdefenseSelector= rand()% 6 + 1;
    int damageDelivery;

    cout<<"\nEnter a value (1-6) to attack: ";
    cin>>attackSelector;

    while(!cin || attackSelector < 1 ||attackSelector > 6){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//discard input
        cout << "\nInvalid input; please re-enter: ";
        cin>>attackSelector;
    }

    if(OPdefenseSelector < attackSelector){
        damageDelivery = attackSelector - (OPdefenseSelector*2);
        opponent.damage(Bunny.getDamageMax() - damageDelivery);
        cout<<"Predator lost "<<Bunny.getDamageMax() - damageDelivery<<"HP"<<endl;
        cout<<"Predator's HP => "<<opponent.getEnemyHP()<<"HP"<<endl;
    }
    else if(OPdefenseSelector > attackSelector){
        damageDelivery = OPdefenseSelector - (attackSelector*2);
        opponent.damage(Bunny.getDamageMax() - damageDelivery);
        cout<<"Predator lost "<<Bunny.getDamageMax() - damageDelivery<<"HP"<<endl;
        cout<<"Predator's HP => "<<opponent.getEnemyHP()<<"HP"<<endl;
    }
    else if(OPdefenseSelector == attackSelector){
        cout<<"You dealt no damage, the predator read your attack"<<endl;
    }

    if(checkHealths() == false)
        return 0;

    cout<<"\nEnter a value (1-6) to defend: ";
    cin>>defenseSelector;

    while(!cin || defenseSelector < 1 ||defenseSelector > 6){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//discard input
        cout << "\nInvalid input; please re-enter: ";
        cin>>defenseSelector;
    }

    if(defenseSelector < OPattackSelector){
        damageDelivery = OPattackSelector -(OPdefenseSelector*2);
        Bunny.damage(opponent.getDamageMax() - damageDelivery);
        cout<<"You lost "<<opponent.getDamageMax() - damageDelivery<<"HP"<<endl;
        cout<<"Your HP => "<<Bunny.getHP()<<"HP"<<endl;
    }
    else if(defenseSelector > OPattackSelector){
        damageDelivery = defenseSelector - (OPattackSelector*2);
        Bunny.damage(opponent.getDamageMax() - damageDelivery);
        cout<<"You lost "<<opponent.getDamageMax() - damageDelivery<<"HP"<<endl;
        cout<<"Your HP => "<<Bunny.getHP()<<"HP"<<endl;
    }
    else if(defenseSelector == OPattackSelector){
        cout<<"Predator dealt no damage, you read predator's attack"<<endl;
    }

    return 0;
}

bool Functions::checkHealths(){
    if(opponent.getEnemyHP() <=0){
        return false;
    }
    return true;
}

void Functions::shop(){
    string carrot = "Carrot";
    string lettuce = "Letuce";
    string cabbage = "Cabbage";
    string basil = "Basil";
    string parsley = "Parsley";
    string celery = "Celery";
    int choice;
    string purchase;

    cout<<"          SHOP      "<<endl;
    cout<<"------------------------"<<endl;
    cout<<"1."<<carrot<<"  5 XP"<<endl;
    cout<<"2."<<lettuce<<"  5 XP"<<endl;
    cout<<"3."<<cabbage<<" 5 XP"<<endl;
    cout<<"4."<<basil<<"   5 XP"<<endl;
    cout<<"5."<<parsley<<" 5 XP"<<endl;
    cout<<"6."<<celery<<"  5 XP"<<endl;

    cout<<"What would you like to buy?"<<endl;
    cout<<"ENTER CHOICE: ";
    cin>>choice;

    switch(choice){
        case 1: purchase = carrot;
            Bunny.foodInvAlert.insert(purchase);
            --Bunny.maxFoodSupply;
            ++Bunny.foodCount;
            break;
        case 2: purchase = lettuce;
            Bunny.foodInvAlert.insert(purchase);
            --Bunny.maxFoodSupply;
            ++Bunny.foodCount;
            break;
        case 3: purchase = cabbage;
            Bunny.foodInvAlert.insert(purchase);
            --Bunny.maxFoodSupply;
            ++Bunny.foodCount;
            break;
        case 4: purchase = basil;
            Bunny.foodInvAlert.insert(purchase);
            --Bunny.maxFoodSupply;
            ++Bunny.foodCount;
            break;
        case 5: purchase = parsley;
            Bunny.foodInvAlert.insert(purchase);
            --Bunny.maxFoodSupply;
            ++Bunny.foodCount;
            break;
        case 6: purchase = celery;
            Bunny.foodInvAlert.insert(purchase);
            --Bunny.maxFoodSupply;
            ++Bunny.foodCount;
            break;
    }

}

void Functions::rest(){
    cout<<"Resting"<<endl;
    cout<<"ENTER #: ";
    cin>>response;
    Bunny.setHP(Bunny.getHPmax());
    cout<<"HP restored: "<<Bunny.getHP()<<"HP";

}

void Functions::getBabies(){
    string resume;
    stack<string> tempKids;
    int i = 0;


    cout<<"\n       SPAWN"<<endl;
    cout<<"----------------------"<<endl;
    while(!(Bunny.children.empty())){
        cout<<i<<". "<<Bunny.children.top()<<endl;
        tempKids.push(Bunny.children.top());
        Bunny.children.pop();
        i++;
    }

    cout<<"Press [ENTER] to continue";
    getline(cin, resume);

    while(!(tempKids.empty())){
        Bunny.children.push(tempKids.top());
        tempKids.pop();
    }
}

void Functions::getStats(){
    cout<<"NAME: "<<Bunny.getName()<<"   HP: "<<Bunny.getHP()<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"COLOR=>         "<<Bunny.getColor()<<endl;
    cout<<"GENDER=>        "<<Bunny.getGender()<<endl;
    cout<<"LEVEL=>         "<<Bunny.getLevel()<<endl;
    cout<<"SPAWN=>         "<<Bunny.getChildCount()<<endl;
    cout<<"CURRENT XP=>    "<<Bunny.getXP()<<endl;
    cout<<"XP TO PROMOTE=> "<<Bunny.getXPup()<<endl;
    cout<<"DAMAGE MIN=>    "<<Bunny.getDamageMin()<<endl;
    cout<<"DAMAGE MAX=>    "<<Bunny.getDamageMax()<<endl;
    cout<<"DEFENSE=>       "<<Bunny.getDefense()<<endl;
}

void Functions::getItemInv(){
    string resume;

    cout<<"           ITEMS"<<endl;
    cout<<"-------------------------------"<<endl;
    if(Bunny.itemInvAlert.count("Hat") > 0)
        cout<<"Hat(s)=>        "<<Bunny.itemInv["Hat"]<<endl;
    if(Bunny.itemInvAlert.count("Glasses") > 0)
        cout<<"Glasses=>       "<<Bunny.itemInv["Glasses"]<<endl;
    if(Bunny.itemInvAlert.count("Foot") > 0)
        cout<<"Foot(s)=>       "<<Bunny.itemInv["Foot"]<<endl;
    if(Bunny.itemInvAlert.count("Bottle") > 0)
        cout<<"Bottle(s)=>     "<<Bunny.itemInv["Bottle"]<<endl;
    if(Bunny.itemInvAlert.count("Toy") > 0)
        cout<<"Toy(s)=>        "<<Bunny.itemInv["Toy"]<<endl;
    if(Bunny.itemInvAlert.count("Thimble") > 0)
        cout<<"Thimble(s)=>    "<<Bunny.itemInv["Thimble"]<<endl;

    cout<<"\nPress [ENTER] to continue";
    getline(cin, resume);
}

void Functions::getFoodInv(){
    string resume;

    cout<<"           Food"<<endl;
    cout<<"-------------------------------"<<endl;
    if(Bunny.foodInvAlert.count("Lettuce") > 0)
        cout<<"Lettuce(s)=>      "<<Bunny.foodInvAlert.count("Lettuce")<<endl;
    if(Bunny.foodInvAlert.count("Cabbage") > 0)
        cout<<"Cabbage(s)=>      "<<Bunny.foodInvAlert.count("Cabbage")<<endl;
    if(Bunny.foodInvAlert.count("Basil") > 0)
        cout<<"Basil(s)=>        "<<Bunny.foodInvAlert.count("Basil")<<endl;
    if(Bunny.foodInvAlert.count("Parsley") > 0)
        cout<<"Parsley(s)=>      "<<Bunny.foodInvAlert.count("Parsley")<<endl;
    if(Bunny.foodInvAlert.count("Celery") > 0)
        cout<<"Celery(s)=>       "<<Bunny.foodInvAlert.count("Celery")<<endl;
    if(Bunny.foodInvAlert.count("Carrot") > 0)
        cout<<"Carrot(s)=>       "<<Bunny.foodInvAlert.count("Carrot")<<endl;

    cout<<"\nPress [ENTER] to continue";
    getline(cin, resume);
}
