/* 
 * File:   BlackjackGame.h
 * Author: Alex
 *
 * Created on April 14, 2018, 6:00 PM
 */

#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include <iostream>                        //To accept user input
#include <cstdlib>                         //For randomized numbers  
#include <ctime>                           //For randomized numbers
#include <string>                          //For user inputed name
#include <cassert>                         //Help with error handeling 
#include <algorithm>                       //Use of binary search
#include <iterator>                        //For iterators
#include <vector>                          //Use of STL library
#include <set>                             //Use of showing off a set 
#include <queue>                           //Use of showing off a queue

using namespace std;

class Card
{  
    private:
        int card;  // range 0 to 51

        static const string CARD_FACES[];
        static const string CARD_SUITS[]; 
    public:
        Card();
        Card(int card);
        void SearchCard();
        void SetCard();
        void QueueCard();
        void ShowQue(queue <string>);
        string getSuit() const;
        string getFace() const;
};

class Deck 
{
private:
    Card cards[52];
    int nxtCrdIndex;
    
    public:
        Deck();
        Card dealOneCard();
        void shuffle();
};    

class Intro
{
protected:
    string name;         //Name of the player
    
public:
    Intro()               //Default constructor
        {name;}
    Intro(string);       //Constructor declaration
    void Introduction(); //Introduces the program and its usage to the player
    void Rules();        //Introduces the rules to the player
    void Menu();         //Presents the menu selection to the user
    void Hit();          //Presents meaning of a 'Hit' in Blackjack
    void Stand();        //Presents meaning of 'Stand' in Blackjack
    virtual void setName(string); //Set the player's name to the protected name string
    string difName(char, string); //Asks if the user wants to change their name
    int getN();          //Asks the user which challenge they want to partake in 
};

class BlkJk : public Intro
{
public:
struct Num     //Structure containing the elements for the first addition level
{
    int num1;         //First number to be created
    int num2;         //Second number to be created and added to num1
    int num3;         //Third number to be created and added if needed
    int num4;         //Fourth number to be created and added if needed
    int num5;         //Fifth number to be created and added if needed
    int num6;         //Sixth number to be created and added if needed
};

Num BlkGame (string);
};

#endif /* BLACKJACKGAME_H */