/* 
 * File:   Deck.cpp
 * Author: Alex
 *
 * Created on April 15, 2018, 10:00 AM
 */

#include "BlackjackGame.h"

//Constructor
Deck::Deck() 
{
    // Initialize the array to the nums 0-51
    for (int i=0; i < 52; i++) 
    {
        cards[i] = Card(i);
    }
    shuffle();
    nxtCrdIndex = 0;  // index of next available card
}    


//dealOneCard
//Returns random Card.

Card Deck::dealOneCard() 
{
    assert(nxtCrdIndex >= 0 && nxtCrdIndex<52);
    return cards[nxtCrdIndex++];
}


//shuffle
//Shuffles the Deck.
void Deck::shuffle() 
{
    // Shuffle by exchanging each element randomly
    for (int i=0; i<52; i++) 
    {
        int randnum = rand() % 52;
        swap(cards[i], cards[randnum]);
    }
    nxtCrdIndex = 0;
}