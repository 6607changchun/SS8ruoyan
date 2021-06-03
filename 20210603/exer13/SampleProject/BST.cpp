#include "BST.h"
#include <queue> 
#include<cstdio>

BST::BST(int max_v){
	root = 0;
}

BST::~BST(){
	std::queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* p = q.front();
		q.pop();
		if(p->left) q.push(p->left);
		if(p->right) q.push(p->right);
		delete p;
	}
}

int BST::Get(int Key){
	node* p = root;
	while(p){
		if(p->key == Key) return p->value;
		if(p->key < Key)
			p = p->right;
		else
			p = p->left;
	}
	return -1;
}

   
void BST::BSTInsert(int Key, int Value){
	node * p = root;
	node * q = 0;
	while(p){
		if(p->key == Key) break;
		if(p->key < Key){
			q = p;
			p = p->right;
		}
		else{
			q = p;
			p = p->left;
		}
	}
	if(p) return;
	node* newNode = new node;
	newNode->key = Key;
	newNode->value = Value;
	newNode->left = 0;
	newNode->right = 0;
	if(!q){
		root = newNode;
		return;
	}
	if(Key > q->key)
		q->right = newNode;
	else 
		q->left = newNode;
}

int BST::deleteNode(node * root,node* parent,int mode){
	int r;
	switch(mode){
		case LEAF:
			if(parent->left == root)
				parent -> left = 0;
			if(parent->right == root)
				parent -> right = 0;
			r = root->value;
			delete root;
			break;
		case LEFT_CHILD:
			if(parent->left == root){
				parent -> left = root->left;
				root->left = 0;
			}
			if(parent->right == root){
				parent -> right = root->left;
				root->left = 0;
			}
			r = root->value;
			delete root;
			break;
		case RIGHT_CHILD:
				if(parent->left == root){
				parent -> left = root->right;
				root->right = 0;
			}
			if(parent->right == root){
				parent -> right = root->right;
				root->right = 0;
			}
			r = root->value;
			delete root;
			break;
	}
	return r;
}

int BST::Delete(int Key){
	node * p = root;
	node * q = 0;
	while(p){
		if(p->key == Key) break;
		if(p->key < Key){
			q = p;
			p = p->right;
		}
		else{
			q = p;
			p = p->left;
		}
	}
	if(!p) return -1;
	if(!p->left&&!p->right)
		return deleteNode(p,q,LEAF);
	if(!p->left) 
		return deleteNode(p,q,RIGHT_CHILD);
	if(!p->right)
		return deleteNode(p,q,LEFT_CHILD);
	node* t = p->right;
	node* tp = p;
	while(t->left){
		tp = t;
		t = t->left;
	}
	int r = p->value;
	p->value = t->value;
	p->key = t->key;
	deleteNode(t,tp,RIGHT_CHILD);
	return r;
}
