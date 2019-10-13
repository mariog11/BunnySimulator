/* File:   Game.cpp
 * Author: Mario Gomez
 * Created on April 8, 2017, 7:18 PM
 * Purpose: */

//user library
#include "../Headers/game.h"

Game::Game(){
    played = false;
    playing = true;
    saveCount = 0;
}

Game::~Game(){}

//Serves as Main menu, return value for decision structure in main()
void Game::MainMenu(){
    int scrapGame, mainMenuChoice;

    //GAME START MENU
    while(playing == true){
        cout<<"\nWELCOME TO BUNNY SIMULATOR"<<endl;
        cout<<"1. Campaign"<<endl;
        cout<<"2. Settings"<<endl;
        cout<<"3. About"<<endl;
        cout<<"4. Quit Game"<<endl;

        cout<<"ENTER CHOICE: ";
        cin>>mainMenuChoice;

        //Input validation for main menu
        while(!cin || mainMenuChoice < 1 ||mainMenuChoice > 4){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//discard input
            cout << "Invalid input; please re-enter: ";
            cin>>mainMenuChoice;
        }

        //MENU SELECTOR
        switch(mainMenuChoice){
        case 1:
            campaignSubMenu();
            break;
        case 2:
            cout<<endl<<"   SETTINGS"<<endl<<"--------------"<<endl;
            break;
        case 3:
            cout<<endl<<"This game puts you in the shoes of a rabbit."<<endl
            <<"While bringing to light notions of bunny life"<<endl
            <<"from an ignorant CS student. "<<endl;
            break;
        case 4:
            //Request user decision for if they want to end game
            //with or without a save (terminating decision)
            if(played && saveCount == 0){
                cout<<"\nAre you SURE you want to quit without saving?"<<endl
                    <<"(1. = QUIT | 2. = SAVE/QUIT)"<<endl
                    <<"Enter (1-2): ";
                cin>>scrapGame;

                //Input validation for terminating decision
                while(!cin || scrapGame < 1 ||scrapGame > 2){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');//discard input
                    cout << "Invalid input; please re-enter: ";
                    cin>>scrapGame;
                }

                //User opted to save the game
                if(scrapGame == 2)
                    saveGame();
            }
            //User has quit; Initial game loop is terminated
            playing = false;
            break;
        }
    }
}

void Game::campaignSubMenu(){
    int scrapGame = 0;
    int subMenuChoice = 0;
    do{
        //CAMPAIGN SUB MENU
        cout<<"\nCAMPAIGN"<<endl;
        if(played){
            cout<<"0. Resume Game"<<endl;
        }
        cout<<"1. New Game"<<endl;
        cout<<"2. Save Game"<<endl;
        cout<<"3. Load Game"<<endl;
        cout<<"4. Back to Menu"<<endl;

        cout<<"ENTER CHOICE: ";
        cin>>subMenuChoice;

        int subMenuLowBound = (played) ? 0 : 1;

        //Input Validation
        while(!cin || subMenuChoice < subMenuLowBound || subMenuChoice > 4){
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(), '\n');//discard input
           cout << "Invalid input; please re-enter: ";
           cin>>subMenuChoice;
        }

        if(subMenuChoice == 1 && played){
            cout<<"Are you SURE you want to start a new Game?"<<endl
            <<"You already have a game going on"<<endl
            <<"(1. = YES | 2. = NO)"<<endl
            <<"Enter (1-2): ";
            cin>>scrapGame;

            while(!cin || scrapGame < 1 ||scrapGame > 2){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');//discard input
                cout << "Invalid input; please re-enter: ";
                cin>>scrapGame;
            }
        }
    }while(scrapGame == 2);

    switch(subMenuChoice){
        //RESUME GAME
        case 0:
            setPlay();
            ActionMenu();
            break;
        //NEW GAME
        case 1:
            played = true;
            cin.ignore();

            cout<<"\nEnter bunny name: ";
            getline(cin, newName);

            cout<<"\nEnter bunny color: ";
            getline(cin, newColor);

            do{
                cout<<"\nEnter bunny gender (M/F): ";
                cin>>newGender;
                newGender = toupper(newGender);
            }while(!cin || !(newGender == 'M' || newGender == 'F'));

            Bunny.setNewBunny(1, newName, newColor, newGender);
            setPlay();
            ActionMenu();
            break;
        case 2:
            saveGame();
            break;
        //LOAD GAME
        case 3:
            if(loadGame()){
                setPlay();
                ActionMenu();
            }
            break;
        //BACK TO MENU
        case 4: break;
    }
}

void Game::ActionMenu(){
    int actionMenuChoice;
    do{
        cout<<"\n ACTION"<<endl;
        cout<<"0. Back to Menu"<<endl;
        cout<<"1. Save Game "<<endl;
        cout<<"2. Travel "<<endl;
        cout<<"3. Shop "<<endl;
        cout<<"4. Rest"<<endl;
        cout<<"5. View Stats"<<endl;
        cout<<"6. View Inventory"<<endl;
        cout<<"7. View Food"<<endl;
        cout<<"8. View Spawn"<<endl;

        cout<<"\nENTER CHOICE: ";
        cin>>actionMenuChoice;

        //Input Validation for action menu
        while(!cin || actionMenuChoice < 0 || actionMenuChoice > 8){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//discard input
            cout << "Invalid input; please re-enter: ";
            cin>>actionMenuChoice;
        }

        switch(actionMenuChoice){
            case 0:
                break;
            case 1:
               saveCount++;
               saveGame();
               break;
            case 2:
               travel();
               checkLevel();
               break;
            case 3:
               shop();
               break;
            case 4:
               rest();
               break;
            case 5:
               getStats();
               break;
            case 6:
               getItemInv();
               break;
            case 7:
               getFoodInv();
               break;
            case 8:
               getBabies();
               break;
        }
    }while(actionMenuChoice != 0);
}