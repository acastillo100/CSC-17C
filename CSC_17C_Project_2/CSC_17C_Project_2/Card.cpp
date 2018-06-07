/* 
 * File:   Card.cpp
 * Author: Alex
 *
 * Created on June 3, 2018, 1:00 PM
 */

#include "BlackjackGame.h"

// Static Constants
const string Card::CARD_FACES[] =  {"A", "2", "3", "4", "5", "6", "7"
                                    , "8", "9", "10", "J", "Q", "K"};
const string Card::CARD_SUITS[] = {"S", "H", "C", "D"};

//Constructor
Card::Card() 
{
    card = 0;         // Should initialize to a Joker.
}    


// Constructor
Card::Card(int _card) 
{
    card = _card;
}    
    

//getFace
//Returns face value of card.
//and a string representing card face

string Card::getFace() const 
{
    return CARD_FACES[card%13];
}


//getSuit
//Returns suit of a card value.
// a string "S" (Spades), "H", (Hearts),
// "C" (Clubs), or "D" (Diamonds).

string Card::getSuit() const 
{ 
    return CARD_SUITS[card/13];
}

void Card::SearchCard()
{
    int n = sizeof(CARD_FACES)/sizeof(CARD_FACES[0]);     //Number of cards
    vector<string> vect(CARD_FACES, CARD_FACES+n);
    
    // Sort the array to make sure that lower_bound()
    // and upper_bound() work.
    sort(vect.begin(), vect.end());
 
    // Returns the first occurrence of 10
    auto f = lower_bound(vect.begin(), vect.end(), "10");
    
    // Returns the last occurrence of J
    auto l = upper_bound(vect.begin(), vect.end(), "J");
 
    cout << "The lower bound is at position: ";
    cout << f-vect.begin() << endl;
 
    cout << "The upper bound is at position: ";
    cout << l-vect.begin() << endl;
    
    //Show begin() return the beginning position of the container.
    //and end() used to return the end position of the container.
    vector<string> ar = {"A", "2", "3", "4", "5", "6", "7",
                         "8", "9", "10", "J", "Q", "K"};
    
    // Declaring iterator to a vector
    vector<string>::iterator ptr;
     
    // Displaying vector elements using begin() and end()
    cout << "The vector elements are : ";
    for (ptr = ar.begin(); ptr < ar.end(); ptr++)
        cout << *ptr << " ";
}

void Card::SetCard()
{
    // empty set container
    set <string, greater <string> > pcard1;        
 
    // insert elements in random order
    pcard1.insert("2");
    pcard1.insert("7");
    pcard1.insert("5");
    pcard1.insert("1");
    pcard1.insert("3");
    pcard1.insert("2");        // only one 2 should be added to the set
    pcard1.insert("4");
    pcard1.insert("6");
    pcard1.insert("10");
    pcard1.insert("8");
    pcard1.insert("9");
 
    // printing set pcard1
    set <string, greater <string> > :: iterator itr;
    cout << "\nThe set pcard1 is : ";
    for (itr = pcard1.begin(); itr != pcard1.end(); ++itr)
    {
        cout << '\t' << *itr;
    }
    cout << endl;
 
    // assigning the elements from pcard1 to pcard2
    set <string> pcard2(pcard1.begin(), pcard1.end());
 
    // print all elements of the set gquiz2
    cout << "\nThe set pcard2 after assign from pcard1 is : ";
    for (itr = pcard2.begin(); itr != pcard2.end(); ++itr)
    {
        cout << '\t' << *itr;
    }
    cout << endl;
 
    // remove all elements up to 30 in pcard2
    cout << "\npcard2 after removal of elements less than '5' : ";
    pcard2.erase(pcard2.begin(), pcard2.find("5"));
    for (itr = pcard2.begin(); itr != pcard2.end(); ++itr)
    {
        cout << '\t' << *itr;
    }
 
    // remove all elements with value 50 in pcard2
    string num;
    num = pcard2.erase ("8");
    cout << "\npcard2.erase('8') : ";
    cout << num << " removed \t" ;
    for (itr = pcard2.begin(); itr != pcard2.end(); ++itr)
    {
        cout << '\t' << *itr;
    }
 
    cout << endl;
 
    //lower bound and upper bound for set pcard1
    cout << "pcard1.lower_bound('7') : "
         << *pcard1.lower_bound("7") << endl;
    cout << "pcard1.upper_bound('7') : "
         << *pcard1.upper_bound("7") << endl;
 
    //lower bound and upper bound for set pcard2
    cout << "pcard2.lower_bound('7') : "
         << *pcard2.lower_bound("7") << endl;
    cout << "pcard2.upper_bound('7') : "
         << *pcard2.upper_bound("7") << endl;
}

void Card::ShowQue(queue <string> cardQ)
{
    queue <string> c = cardQ;
    while (!c.empty())
    {
        cout << '\t' << c.front();
        c.pop();
    }
    cout << '\n';
}

void Card::QueueCard()
{
    queue <string> cQue;
    cQue.push("A");
    cQue.push("B");
 
    cout << "The queue cQue is : ";
    ShowQue(cQue);
 
    cout << "\ncQue.size() : " << cQue.size();
    cout << "\ncQue.front() : " << cQue.front();
    cout << "\ncQue.back() : " << cQue.back();
 
    cout << "\ncQue.pop() : ";
    cQue.pop();
    ShowQue(cQue);
}

void Card::recSort(string ary[], int n)
{
    // Base case
    if (n == 1)
        return;
 
    // One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.
    for (int index=0; index < n-1; index++)
        if (ary[index] > ary[index+1])
            swap(ary[index], ary[index+1]);
 
    // Largest element is fixed,
    // recur for remaining array
    recSort(ary, n-1);
}

//Function to print recursive sorted array 
void Card::prtSort(string ary[], int n)
{
    for (int index=0; index < n; index++)
        cout << ary[index] << endl;
}