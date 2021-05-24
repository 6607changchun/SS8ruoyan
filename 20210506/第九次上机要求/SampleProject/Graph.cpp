/*******************************************************************************
* FileName:         Graph.cpp
* Author:           Your_name
* Student Number:   Student_Number
* Date:             2020/04/14 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #9
*******************************************************************************/

#include "Graph.h"
#include <queue>
#include <cstring>

Graph::Graph(int v){
	g = new node[v+1];
	this->v = v;
	edge = 0;
	in = new int[v+1];
	memset(g,0,sizeof(g));
	memset(in,0,sizeof(in));
	for(int i = 1;i <= v;i++)
		g[i].index = i;
}

Graph::~Graph(){
	delete[] g;
	delete[] in;
}

void Graph::addedge(int s, int t, int w){
	in[t]++;
	node* newNode = new node;
	newNode->from = s;
	newNode->index = t;
	newNode->weight = w;
	node* snode = &g[s];
	newNode->next = snode->next;
	snode->next = newNode;
	edge++;
}

int Graph::getInDegree(int v){
	return in[v];
}

int Graph::getOutDegree(int v){
	node* p = &g[v];
	int cnt = 0;
	while(p){
		cnt++;
		p = p->next;
	}
	return cnt-1;
}

int Graph::access(int s, int t){
	node* p = &g[s];
	while(p){
		if(p->index == t) 
			return p->weight;
		p = p->next;		
	}
	return -1;
}

int Graph::getDist(int s, int t){
	std::queue<node*> q;
	int * steps = new int[v+1];
	for(int i = 1;i <= v;i++)
		steps[i] = -1;
	q.push(&g[s]);
	steps[s] = 0;
	while(!q.empty()){
		node * temp = q.front();
		q.pop();
		int cnt = steps[temp->from];
		for(;temp;temp = temp->next){
			if(temp->index == t) {delete[] steps;return cnt+1;}
			if(steps[temp->index] != -1) continue;
			q.push(&g[temp->index]);
			steps[temp->index] = cnt+1;
		}
	}
	delete[] steps;
	return -1;
}
