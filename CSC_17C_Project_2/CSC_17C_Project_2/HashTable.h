/* 
 * File:   HashTable.h
 * Author: Alex
 *
 * Created on June 3, 2018, 1:00 PM
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <cstdlib>
#include <list>

#include "GeneralHashFunctions.h"

using namespace std;

typedef unsigned int uint;


class HashTable 
{
private:
	list<string> *table;
	int SIZE;
	uint hash(string key);
public:
	HashTable(int length);
	virtual ~HashTable();
	void put(string key, string val);
	string at(string key);
	bool hashMeet(string key);
	bool exists(string key);
};

#endif /* HASHTABLE_H */