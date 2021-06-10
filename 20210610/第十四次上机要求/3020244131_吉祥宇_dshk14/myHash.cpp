/*******************************************************************************
* FileName:         myHash.cpp
* Author:           Your_name
* Student Number:   Student_Number
* Date:             2020/05/20 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #15
*******************************************************************************/

#include "myHash.h"
#include "BST.h"

MyHash::MyHash(int max_element){
	maxE = max_element;
	map = new BST[maxE];
	int mul = 1;
	for(int i = 0;i < 9 && mul * primeTable[i+1] < maxE;i++)
		mul *= primeTable[i];
	m = mul + 1;
}

MyHash::~MyHash(){
	delete[] map;
}

void MyHash::setvalue(int key, int value){
	long realKey = 0;
	int tempKey = key;
	while(key != 0){
		realKey += (key % 10);
		realKey %= m;
		realKey *= hashFactor;
		realKey %= m;
		key /= 10;
	}
	map[realKey].BSTInsert(tempKey,value);
}

int MyHash::getvalue(int key){
	long realKey = 0;
	int tempKey = key;
	while(key != 0){
		realKey += (key % 10);
		realKey %= m;
		realKey *= hashFactor;
		realKey %= m;
		key /= 10;
	}
	return map[realKey].Get(tempKey);
}
