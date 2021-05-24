/*******************************************************************************
* FileName:         SPMatrix.cpp
* Author:           Your_name
* Student Number:   3019244XXX
* Date:             2020/03/20 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #7
*
*******************************************************************************/

#include "SPMatrix.h"
#include <algorithm>

SPMatrix::SPMatrix(int r, int c){
	this->r = r;
	this->c = c;
	notZero = 0;
	elements = new triple[r * c * SP_FACTOR];
}

SPMatrix::SPMatrix(int r, int c, int max_element){
	this->r = r;
	this->c = c;
	notZero = 0;
	elements = new triple[max_element];
}

int SPMatrix::get(int i, int j)const{
	for(int k = 0;k < notZero;k++)
		if(elements[k].i == i && elements[k].j == j)
			return elements[k].value;
	return 0;
}

void SPMatrix::set(int i, int j, int val){
	if(!val) return;
	for(int k = 0;k < notZero;k++)
		if(elements[k].i == i && elements[k].j == j)
			{elements[k].value = val;return;}
	elements[notZero].i = i;
	elements[notZero].j = j;
	elements[notZero].value = val;
	notZero++;
}

void SPMatrix::rotate(){
	for(int k = 0;k < notZero; k++)
		std::swap(elements[k].i,elements[k].j);
}

SPMatrix SPMatrix::operator+(const SPMatrix& b){
	SPMatrix* result = new SPMatrix(r,c);
	for(int i = 0; i < c;i++)
		for(int j = 0; j < r; j++){
			int value = this -> get(i,j) + b.get(i,j);
			result -> set(i,j,value);
		}
	return *result;
}

SPMatrix SPMatrix::operator-(const SPMatrix& b){
	SPMatrix* result = new SPMatrix(r,c);
	for(int i = 0; i < r;i++)
		for(int j = 0; j < c; j++){
			int value = this -> get(i,j) - b.get(i,j);
			result -> set(i,j,value);
		}
	return *result;
}

SPMatrix SPMatrix::operator*(const SPMatrix& b){
	int resultColumn = this->r;
	int resultRow = b.row();
	SPMatrix* result = new SPMatrix(resultColumn,resultRow);
	for(int k = 0;k < notZero;k++){
		int xk = elements[k].i;
		int yk = elements[k].j;
		int vk = elements[k].value;
		for(int l = 0;l < b.row();l++){
			int val = b.get(xk,l);
			if(!val) continue;
			int pending = result->get(xk,l);
			result->set(xk,l,pending+val*vk);
		}
	}
	return *result;
}
int SPMatrix::row()const{return this->r;}
int SPMatrix::column()const{return this->c;}
SPMatrix::~SPMatrix(){
	delete elements;
}
