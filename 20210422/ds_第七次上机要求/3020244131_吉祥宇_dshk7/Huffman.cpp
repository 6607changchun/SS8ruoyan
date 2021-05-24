/*******************************************************************************
* FileName:         Haffman.cpp
* Author:           Your_name
* Student Number:   Student_Number
* Date:             2020/04/08 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #10
*******************************************************************************/

#include "Huffman.h"
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

//overload operator in order to sort weight
bool operator<(const HuffmanTree::cmpnode& a, const HuffmanTree::cmpnode& b){
	int af = a.fre;
	int bf = b.fre;
	if(af <= bf) return true;
	else return false;
}
HuffmanTree::HuffmanTree(const int* Table){
	for(int i = 0;i < 26;i++){
		//skip zero value
		if(!Table[i]) continue;
		//construct a new node instance
		node * t = new node;
		t->left = 0;
		t->right = 0;
		t->parent = 0;
		t->message = "";
		//record node
		nodes[nnum] = t;
		nnum++;
		//Wrap the node and record the wrapper
		cmpnode* temp = new cmpnode;
		cmpnode tc = *temp;
		tc.rawnode = t;
		tc.fre = Table[i];
		cmpnodes[cnum] = tc;
		cnum++;
	}
	//copy number of valid input for future use
	initnum = nnum;
	for(int i = 1;i <= initnum-1;i++){
		//for each turn(initnum-1 in all for initnum-1 times to add one node to target tree),
		//sort the weight(also called frequency), and find the node with minimum weight
		std::sort(cmpnodes,cmpnodes+cnum);
		int j = 0;
		//notice that some nodes may have been added to the tree before, in this case, skip it
		//free nodes' parent pointer must be null
		while((cmpnodes[j].rawnode)->parent)
			j++;
		//Similarly, find minimum just next to the above one
		int k = j+1;
		while((cmpnodes[k].rawnode)->parent)
			k++;
		//get and unwrap these two nodes
		node* min1 = cmpnodes[j].rawnode;
		node* min2 = cmpnodes[k].rawnode;
		//construct a new node to be the parent node of the above nodes
		node* newNode = new node;
		newNode->left = min1;
		newNode->right = min2;
		newNode->parent = 0;
		newNode->message = "";
		//reset parent pointer of child nodes
		min1->parent = newNode;
		min2->parent = newNode;
		//record new node
		nodes[nnum] = newNode;
		nnum++;
		//Wrap new node and record
		cmpnode* newCmpt = new cmpnode;
		cmpnode newCmp = *newCmpt;
		newCmp.rawnode = newNode;
		newCmp.fre = cmpnodes[j].fre + cmpnodes[k].fre;
		cmpnodes[cnum] = newCmp;
		cnum++;
	}
	//to start travelling, we have to find the root
	for(int i = 0;i < nnum;i++)
		if(!nodes[i]->parent){
			root = nodes[i];
			break;
		}
	//travel through the Huffman Tree to generate charset
	visit(root);
}

HuffmanTree::~HuffmanTree(){
	//recycle arrays of pointer
	for(int i = 0;i < nnum;i++)
		delete nodes[i];
	for(int i = 0;i < cnum;i++)
		delete &cmpnodes[i];
}
void HuffmanTree::visit(node* root){
	//generally, any type of trvelling are supposed to work correctly
	//here, we choose a bit low-speed but simple BFS
	if(!root->left&&!root->right){
		for(int i = 0;i < initnum;i++){
			//when we reach leaf, it's time to store certain charset, and build a mapping from character to message
			if(nodes[i] == root)
				cset[i] = root->message;
		}
		return;
	}
	if(root->left){
		//recurse to travel left subtree
		//remember to set or update internal nodes' encoding.
		string pending = "0";
		(root->left)->message = root->message+pending;
		visit(root->left);
	} 
	if(root->right){
		//Similarly, recurse to travel right subtree
		string pending = "1";
		(root->right)->message = root->message+pending;
		visit(root->right);
	} 
	
}
string HuffmanTree::Encode(string mess){
	//just to find every character and call append encoding mapping to concat result string
	string result = "";
	for(int i = 0;i < mess.length();i++){
		result = result.append(cset[mess[i]-'a']);
	}
	return result;
}

string HuffmanTree::Decode(string message){
	//just reverse the operations of encoding
	//find the first valid character encoding and add to result
	//after each search, truncate used substring 
	string result = "";
	while(!message.empty()){
		for(int i = 0;i < initnum;i++){
			if(!message.find(cset[i])){
				char s[] = {i+'a','\0'};
				result.append(s);
				message = message.substr(cset[i].length());
				break;
			}
		}
	}
	return result;
}
