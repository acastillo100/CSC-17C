/* 
 * File:   HashTable.cpp
 * Author: Alex
 * 
 * Created on June 3, 2018, 1:00 PM
 */

#include <string>
#include <cstdlib>
#include <list>

#include "HashTable.h"

using namespace std;

HashTable::HashTable(int length) 
{
	this->table = new list<string>[length];
	this->SIZE = length;
}


HashTable::~HashTable( ) 
{
	delete [] this->table;
}


uint HashTable::hash(string key)
{
    uint hash = RSHash(key);
    uint index = hash % this->SIZE;
    return index;
}


void HashTable::put(string key, string val)
{
    uint index = hash( key );
    //If true then we have a collision
    if(this->table[index].size() > 1)
    { 
	this->table[index].push_back(val);
    } 
    else 
    { 
	//If no value here, no collision
	this->table[index].push_back(val);		
    }
}


string HashTable::at(string key)
{
    uint index = hash(key);
	
    if( this->table[index].size() > 0)
    {
	//If true return collision
	if(this->table[index].size() == 1)
            {
		return this->table[index].front();
            } 
        else 
            {
		return "collision"; 
            }
    }
    return "";
}


bool HashTable::hashMeet(string key)
{
    uint index = hash( key );
	
    if( this->table[index].size() > 1)
    {
	return true;
    } 
    else 
    {
	return false;
    }
}


bool HashTable::exists(string key)
{
    uint index = hash(key);
	
    if( this->table[index].size() > 0)
    {       
        return true;
    } 
    else 
    {
        return false;
    }
}