/*******************************************************************************
* FileName:         BinTree.cpp
* Author:           Your_name
* Student Number:   Student_Number
* Date:             2020/04/01 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #6
*******************************************************************************/


#include "BinTree.h"
#include <stack>
//initialize
BinTree::BinTree(){
	num = 0;
	root = 0;
}

//collect table
BinTree::~BinTree(){
	for(int i = 0;i < num;i++)
		delete nodes[i];
}


void BinTree::insert(int val, int parent, int flg){
	//initialize new node
	node * e = new node;
	e -> val = val;
	e -> left = 0;
	e -> right = 0;
	//root
	if(!parent){
		if(flg == -1)
			e -> left = root;
		else
			e -> right = root;
		root = e;
		//update height
		e -> height = 1;
		for(int i = 0;i < num;i++)
			nodes[i] -> height ++;
	}
	else{
		//normol node
		node *par = nodes[parent-1];
		if(flg == -1)
			par -> left = e;
		else
			par -> right = e;
		e->height = par->height+1;
	}
	//update nodes' table
	nodes[num] = e;
	num++;
}

int* BinTree::p_traversal() const{
	//simulate recursion using stack
	std::stack<node*> s;
	//result set
	int *r = new int[num];
	int i = 0;
	//prepare for loop
	if(!root) return r;
	s.push(root);
	while(!s.empty()){
		//current node
		node * t = s.top();
		s.pop();
		//add to result set
		r[i++] = t -> val;
		//because of FILO property of stack, push the right child ahead of the left
		//postorder travelling needs the right subtree last
		if(t->right)
			s.push(t->right);
		if(t->left)
			s.push(t->left);
	}
	return r;
}

int* BinTree::m_traversal() const{
	//similar to p_traversal()
    std::stack<node*> st;
	int *r = new int[num];
	int i = 0;
	if(!root) return r;
	node * r1 = root;
	while(!st.empty()||r1 != 0){
		if(r1){
			//do down the left child until one node do not have the left child
			//push the node because they are the roots of these subtrees
			//when the left has been processed, the next is the root.
			//And then prepare the right.
			st.push(r1);
			r1 = r1->left;
		}
		else{
			//left child is done.
			//it's time for root and right child.
			r1 = st.top();
			st.pop();
			//add root to the result set
			r[i++] = r1->val;
			//the process of the right child is similar to that of the left child.
			r1 = r1->right;
		}
	}
	return r;
}

int BinTree::countNode() const{
	return num;
}

int BinTree::height() const{
	//just to find the maximum height in all nodes of nodes' table 
	if(!nodes[0]) return 0;
	int h = nodes[0]->height;
	for(int i = 1;i < num;i++)
		if(nodes[i] -> height > h)
			h = nodes[i] ->height;
	return h;
}
