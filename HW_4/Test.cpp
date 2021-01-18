/**
* Briefly explain the function of this class->
*
* @author 			游子霆
* @ID 				B07505051
* @Department 		Engineering Science and Ocean Engineering
* @Affiliation 	National Taiwan University
*
* TestHashTable.cpp
* version 1.0
*/
#include "String.h"
#include "Double.h"
#include <stdlib.h>
#include <time.h>
#include "Integer.h"
#include "HashTableChained.h"
#include "CheckerBoard.h"
#include "Entry.h"
#include "Dictionary.h"
#include "HashTableChained.cpp"

template <typename K, typename V>
void initTable(HashTableChained<K, V> *, int);
int main()
{

	// initialize random seed:
	srand((unsigned)time(NULL));

	int numBoards = 100;
	HashTableChained<String *, Integer *> *table1 = new HashTableChained<String *, Integer *>(numBoards);
	char a;
	for (int i = 0; i < 100; i++) //use random number to create a random string as the key
	{
		string x;
		for (int n = 0; n < rand() % 10 + 1; n++)
		{
			a = rand() % 26 + 97;
			x += a;
		}

		String *hi = new String(x);
		Integer *b = new Integer(i);
		table1->insert(hi, b); //insert the key and value into the table
	}
	cout << "String : " << endl
		 << endl;
	table1->print();				  //cout the table
	int count1 = table1->collision(); //cout the entries in each bucket
	cout << endl
		 << endl;
	String *hi = new String("hi");
	Integer *b = new Integer(10);
	cout << endl
		 << endl
		 << "insert,remove,find test :" << endl;
	table1->insert(hi, b);											 //insert the string "hi" into the table
	cout << "find? " << table1->find(hi) << " : should be 1" << endl; //find if the insert succeed
	table1->makeEmpty();											 //empty the table
	cout << "is it empty? " << table1->isEmpty() << " : should be 1" << endl
		 << endl;	 //cout if the table is empty now
	table1->print(); //cout the table

	HashTableChained<CheckerBoard *, Integer *> *table = new HashTableChained<CheckerBoard *, Integer *>(numBoards); //change the key type into checkboard
	initTable(table, numBoards);
	cout << endl
		 << "Checkboard : " << endl
		 << endl;
	int count = table->collision();
	cout << endl
		 << endl;

	HashTableChained<Double *, Integer *> *table2 = new HashTableChained<Double *, Integer *>(numBoards); //change the key type into double
	for (int i = 0; i < 100; i++)
	{
		int temp = rand();
		double d = (double)temp / 13;
		Double *b = new Double(d);
		Integer *t = new Integer(temp);
		table2->insert(b, t);
	}
	cout << "Double : " << endl
		 << endl;
	table2->print();
	int count2 = table2->collision();
	cout << endl
		 << endl;
	return 0;
}

/**
 *  Generates a random 8 x 8 CheckerBoard.
 **/
CheckerBoard *randomBoard()
{
	CheckerBoard *board = new CheckerBoard;
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			board->setElementAt(x, y, rand());
		}
	}
	return board;
}

/**
 *  Empties the given table, then inserts "numBoards" boards into the table.
 *  @param table is the hash table to be initialized.
 *  @param numBoards is the number of random boards to place in the table.
 **/
template <typename K, typename V>
void initTable(HashTableChained<K, V> *table, int numBoards)
{
	table->makeEmpty();
	for (int i = 0; i < numBoards; i++)
	{
		table->insert(randomBoard(), new Integer(i));
	}
}
