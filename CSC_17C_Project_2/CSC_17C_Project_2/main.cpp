/* 
 * File:   main.cpp
 * Author: Alex
 *
 * Created on June 3, 2018, 1:00 PM
 */

#include "BlackjackGame.h"
#include "GeneralHashFunctions.h"

//Function Prototypes
//    None

using namespace std;


int main(int argc, char** argv) 
{
    //Variables for the player and game 
    string player;         //Name of the player
    string passwrd;        //Player's password
    string repeat;         //Repeat password
    string inputPass;      //User input password
    string msage;          //Message for hash
    string hash1;          //Hash of message
    string hash2;          //Hash of password
    string test2;          //Hash of test password
    int Hash;              //Hash of hash1 and hash2
    int Test;              //Hash result of test
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
    cout << "Enter a Password: ";
    cin >> passwrd;
    cout << "Repeat your password: ";
    cin >> repeat;
    
    //If two input didn't match, ask for reenter
    if (repeat != passwrd) 
    {
            cout << "\n Error! Your repeat password different with your password!" << endl;
            cout << " Press enter information again." << endl;
            cin.ignore();
    }
    
    //Hash message
    msage = "This program is awesome!";
    hash1 = to_string(RSHash(msage));
    hash2 = to_string(BPHash(passwrd));
    Hash = ELFHash(hash1 + hash2);
     
    do
    {        
        player = start.difName(play, player);
       
        cout << endl << endl;        
        start.Menu();           //Display menu
        
        inN = start.getN();     //Accept user input for challenge choice
        
        switch(inN)             //Switch for deciding challenges or if misinput
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