/* 
 * File:   main.cpp
 * Author: Alex
 *
 * Created on April 14, 2018, 4:00 PM
 */

#include "BlackjackGame.h"

//Function Prototypes
//    None

using namespace std;


int main(int argc, char** argv) 
{
    //Variables for the player and game 
    string player;         //Name of the player
    char play = 'N';       //Character to hold player voice to replay
    int inN;               //Holds player choice
    Intro start;           //start variable for the intro class to present info
    BlkJk game;            //Variable to access the game
    
    //Initialize the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    cout << "Press enter to begin.\n";
    cin.get();
    
    start.Introduction();
    start.Rules();
     
    cout << "Press enter to continue.\n";
    cin.ignore(1,'\n');         //Pause screen
    cout << "Please enter the name of the player: " << endl;
    getline(cin,player);       //Enter name
    cout << "\nThis is name: " << player << endl;
    start.setName(player);     //Send name to class
     
    do
    {        
        player = start.difName(play, player);
       
        cout << endl << endl;        
        start.Menu();         //Display menu
        
        inN = start.getN();     //Accept user input for challenge choice
        
        switch(inN)          //Switch for deciding challenges or if misinput
        {
          case 1:   start.Hit();break;
          case 2:   start.Stand();break;
          case 3:   game.BlkGame(player);break;
          case 4:   break;
          default:  start.getN();
        }     
        
        cout << "Would you like to go back to the menu or quit? (Y for menu or N for quit): "; //Ask to play again
        cin >> play;               //User input for replay
        cout << endl << endl;       
    }while (play == 'Y' || play == 'y');
    
    //Exit stage right
    return 0;
}