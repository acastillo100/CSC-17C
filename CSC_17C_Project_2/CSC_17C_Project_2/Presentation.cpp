/* 
 * File:   Presentation.cpp
 * Author: Alex
 *
 * Created on June 3, 2018, 1:00 PM
 */

#include "BlackjackGame.h"
#include "Tree.h"

//Constructor that sets the name to the protected variable
Intro::Intro(string player)
{
    player = name;

}

//Sets the user inputed name to the protected name variable
void Intro::setName(string player)
{
    name = player;
}

//Presents introduction for when the player boots up program
void Intro::Introduction()
{
    cout << "Welcome to Alex's Blackjack Cardgame!\n" << endl;
    cout << "The point of this program is to present to you, the player,\n";
    cout << "a game of Blackjack against a dealer and attempt to win by\n";
    cout << "getting a higher number count than the deal or by hitting\n";
    cout << "a total of 21.\n\n";
}

//Presents rules for a game of blackjack 
void Intro::Rules()
{
    cout << "\nBlackjack is played with one or more standard 52-card decks,\n";
    cout << "with each card assigned a point value. The cards 2 through 10 are\n";
    cout << "worth their face value. Kings, queens, and jacks are each worth 10,\n";
    cout << "and aces may be used as either 1 or 11. The object for the player\n";
    cout << "is to draw cards totaling closer to 21, without going over, \n";
    cout << "than the dealer's cards.\n\n";
}

//Presents the menu for the player to look more into a hit or stand move
void Intro::Menu()
{
    cout << "Choice #1: What does it mean to 'Hit'?\n";
    cout << "Choice #2: What does it mean to 'Stand'?\n";
    cout << "Choice #3: Start the game.\n"; 
    cout << "Choice #4: Stop the game\n\n";
}

//Presents meaning of a 'Hit' in Blackjack
void Intro::Hit()
{
   cout << "If you hit, you must take another card or cards in hopes of getting\n";
   cout << "closer to 21. If the player's total exceeds 21 after hitting, the\n";
   cout << "player is said to 'bust' and loses the game against the dealer.\n\n";
}

//Presents meaning of 'Stand' in Blackjack
void Intro::Stand()
{
    cout << "If you decide to stand then you are unable to hit and accept more\n";
    cout << "cards. Your current total will be compared to the dealer's and\n";
    cout << "a winner will be decided.\n\n";
}

//Function if the user wants to change their name after finishing a challenge
string Intro::difName(char change, string player)
{
    if (change == 'Y' || change == 'y') //Only activates on replay
        {
            cout << "Would you like to change your name? (Y or N): ";
            cin >> change;     //Character to hold player choice of name change
            cout << endl << endl;
        
            if (change == 'Y' || change == 'y') //If name wants to be changed
            {
                cin.ignore(1000,'\n');      //Prevent skipping of name on retry
                cout << "Please enter the name of the player: ";
                getline(cin,player);        //Enter new name
                Intro::setName(player);
                cout << endl << endl;
            }
        }
    return player;
}

//Get the user variable for the player choice
int Intro::getN()
{
    int inN = 0;
    cout << "Please enter a number to choose what you want: ";
    cin >> inN;
    cout << endl;
    return inN;   
}


BlkJk::Num BlkJk::BlkGame(string name)
{
    char HitPass;              //Choice to hit or pass
    char hitAgain;             //Choice to hit again
    int numOfCards = 2;        // Input number for how many cards to deal.
    int Ptotal = 0;            //Total of player hand
    int Dtotal = 0;            //Total of dealer hand
    srand(time(0));            // Initializes random "seed".
    Deck deck;                 //Deck variable to shuffle and deal
    Card card;                 //Card variable to test STL functions
    Tree tree;                 //AVL tree to display
    
//    card.SearchCard();       //Binary search algorithm test
//    card.SetCard();          //Set test for the program
//    card.QueueCard()         //Queue test for program
    
    if (numOfCards == 2) 
    {
        deck.shuffle();
        
        //Player hand
        cout << "Your hand is: ";
        for (int cardNum = 0; cardNum < numOfCards; cardNum++) 
        {
            Card c = deck.dealOneCard();  
            string suit = c.getSuit();
            string face = c.getFace();
            cout << face << suit << " ";
            if (c.getFace() == "1")
            Ptotal+=1;
        else if (c.getFace() == "2")
            Ptotal+=2;
        else if (c.getFace() == "3")
            Ptotal+=3;
        else if (c.getFace() == "4")
            Ptotal+=4;
        else if (c.getFace() == "5")
            Ptotal+=5;
        else if (c.getFace() == "6")
           Ptotal+=6;
        else if (c.getFace() == "7")
            Ptotal+=7;
        else if (c.getFace() == "8")
            Ptotal+=8;
        else if (c.getFace() == "9")
            Ptotal+=9;
        else if (c.getFace() == "10")
            Ptotal+=10;
        else if (c.getFace() == "J")
            Ptotal+=10;
        else if (c.getFace() == "Q")
            Ptotal+=10;
        else if (c.getFace() == "K")
            Ptotal+=10;
        else if (c.getFace() == "A")
        {
            Ptotal+=11;
            if (Ptotal > 21)
            {
                Ptotal - 10;
            }
        }
        else
            Ptotal+=0;
        }
        cout << endl;
    }
    
    //Dealer hand
    if (numOfCards == 2) 
    {
        for (int cardNum = 0; cardNum < numOfCards; cardNum++) 
        {
            Card c = deck.dealOneCard();  
            string suit = c.getSuit();
            string face = c.getFace();
            if (c.getFace() == "1")
            Dtotal+=1;
        else if (c.getFace() == "2")
            Dtotal+=2;
        else if (c.getFace() == "3")
            Dtotal+=3;
        else if (c.getFace() == "4")
            Dtotal+=4;
        else if (c.getFace() == "5")
            Dtotal+=5;
        else if (c.getFace() == "6")
            Dtotal+=6;
        else if (c.getFace() == "7")
            Dtotal+=7;
        else if (c.getFace() == "8")
            Dtotal+=8;
        else if (c.getFace() == "9")
            Dtotal+=9;
        else if (c.getFace() == "10")
            Dtotal+=10;
        else if (c.getFace() == "J")
            Dtotal+=10;
        else if (c.getFace() == "Q")
            Dtotal+=10;
        else if (c.getFace() == "K")
            Dtotal+=10;
        else if (c.getFace() == "A")
        {
            Dtotal+=11;
            if (Dtotal > 21)
            {
                Dtotal - 10;
            }
        }
        else
            Dtotal+=0;
        }
        cout << endl;
    }
    
    
    cout << "This is your total drawn " << name << ": "<< Ptotal << endl;
    
    cout << "\nWould you like to hit or pass? (H for hit, P for pass)? ";
    cin >> HitPass;
    
    if (HitPass == 'H' || HitPass == 'h')
    {
        do
        {
            int hit = 1;                //Access one card
            if (hit == 1) 
            {        
                //Player hand
                cout << "Your hand is: ";
                for (int cardNum = 0; cardNum < hit; cardNum++) 
                    {
                        Card c = deck.dealOneCard();  
                        string suit = c.getSuit();
                        string face = c.getFace();
                        cout << face << suit << " ";
                        int Ptotal2 = 0;
                        if (c.getFace() == "1")
                        {
                            Ptotal2+=1;
                            Ptotal = Ptotal + Ptotal2;
                        }
                        else if (c.getFace() == "2")
                        {
                            Ptotal2+=2;
                            Ptotal = Ptotal + Ptotal2;
                        }
                        else if (c.getFace() == "3")
                        {
                            Ptotal2+=3;
                            Ptotal = Ptotal + Ptotal2;
                        }
                        else if (c.getFace() == "4")
                        {
                            Ptotal2+=4;
                            Ptotal = Ptotal + Ptotal2;
                        }
                        else if (c.getFace() == "5")
                        {
                            Ptotal2+=5;
                            Ptotal = Ptotal + Ptotal2;
                        }
                        else if (c.getFace() == "6")
                        {
                            Ptotal2+=6;
                            Ptotal = Ptotal + Ptotal2;
                        }
                        else if (c.getFace() == "7")
                        {
                            Ptotal2+=7;
                            Ptotal = Ptotal + Ptotal2;
                        }
                        else if (c.getFace() == "8")
                        {
                            Ptotal2+=8;
                            Ptotal = Ptotal + Ptotal2;
                        }
                        else if (c.getFace() == "9")
                        {
                            Ptotal2+=9;
                            Ptotal = Ptotal + Ptotal2;
                        }
                        else if (c.getFace() == "10")
                        {
                            Ptotal2+=10;
                            Ptotal = Ptotal + Ptotal2;
                        }
                        else if (c.getFace() == "J")
                        {
                            Ptotal2+=10;
                            Ptotal = Ptotal + Ptotal2;
                        }
                        else if (c.getFace() == "Q")
                        {
                            Ptotal2+=10;
                            Ptotal = Ptotal + Ptotal2;
                        }
                        else if (c.getFace() == "K")
                        {
                            Ptotal2+=10;
                            Ptotal = Ptotal + Ptotal2;
                        }
                        else if (c.getFace() == "A")
                        {
                            Ptotal2+=11;
                            if ((Ptotal + Ptotal2) > 21)
                                {
                                    Ptotal += Ptotal2;
                                    Ptotal = Ptotal - 10;
                                }
                        }
                        else
                            Ptotal2+=0;
                    }
                cout << endl;
            }       
            cout << endl << endl;

            cout << "This is your total drawn " << name << ": "<< Ptotal << endl;
            if (Ptotal > 21)
            {
                cout << "Your hand has exceed the value of 21, thus you have\n";
                cout << "busted your hand. Sorry try again!\n\n";
                cout << "Press enter to continue.\n";
                cin.get();
                cin.ignore(1);
                HitPass = '1';
                hitAgain = 'N';
                
            }
            else
            {
                cout << "Would you like to hit again? (H for Hit or P for Pass)? ";
                cin >> hitAgain;
                if (hitAgain == 'P' || hitAgain == 'p')
                {
                    HitPass = 'P';
                }
            }
        }while(hitAgain == 'H' || hitAgain == 'h');
    }
    
    if (HitPass == 'P' || HitPass == 'p')
    {
        cout << "Your hand total is " << Ptotal << endl;
        
        if (Dtotal > Ptotal && Dtotal <= 21)
        {
            cout << "\nThe dealer's hand total is " << Dtotal << endl;
            cout << "Sadly your hand total is less than the dealer's, so\n";
            cout << "you lose out this round.\n\n";
        }
        else if (Dtotal == Ptotal)
        {
            cout << "\nThe dealer's hand total is " << Dtotal << endl;
            cout << "Sadly your hand total is equal to the dealer's, so\n";
            cout << "nobody wins this round.\n\n";
        }
        else if (Dtotal < Ptotal)
        {
            cout << "\nThe dealer's hand total is " << Dtotal << endl;
            cout << "Congratulations! Your hand total is more than the dealer's, so\n";
            cout << "you win out this round.\n\n";
        }
        else
        {
            cout << "\nThe dealer's hand total is " << Dtotal << endl;
            cout << "Congratulations! Since the dealer busted out his hand,\n";
            cout << "you win out this round.\n\n";
        }
    }
}