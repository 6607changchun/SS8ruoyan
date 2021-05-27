/*******************************************************************************
* FileName:         Graph.cpp
* Author:           Your_name
* Student Number:   Student_Number
* Date:             2021/05/23 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #13
*******************************************************************************/

#include "Graph.h"
#include <cstring>
#include <cstdio>

Graph::Graph(int max_v){
	v = max_v;
	edge = 0;
	memset(e,0,sizeof(e));
	memset(head,0,sizeof(head));
	memset(dis,0x3f,sizeof(dis));
	dis[0] = 0;
}

Graph::~Graph(){
	
}

void Graph::addedge(int s, int t, int w){
	dis[0] = 0;
	edge++;
	e[edge].from = s;
	e[edge].to = t;
	e[edge].w = w;
	e[edge].next = head[s];
	head[s] = edge;
}

int Graph::getV(){
	return this->v;
}

int Graph::getdist(int k){
	if(dis[0]) return dis[k];
	dis[0] = 1;
	dis[1] = 0;
	int in[v+1];
	memset(in,0,sizeof(in));
	in[1] = 1;
	for(int i = head[1];i;i = e[i].next){
		int t = e[i].to;
		dis[t] = e[i].w;
	}
	for(int i = 2;i <= v;i++){
		int mini = 1;
		int minw = 0x3f3f3f3f;
		for(int j = 2;j <= v;j++){
			if(dis[j] < minw && !in[j]){
				mini = j;
				minw = dis[j];
			}
		}
		in[mini] = 1;
		for(int j = head[mini];j;j = e[j].next){
			int t = e[j].to;
			int w = e[j].w;
			if(minw + w < dis[t])
				dis[t] = minw + w;
		}
	}
	for(int i = 1;i <= v;i++)
		if(dis[i] == 0x3f3f3f3f)
			dis[i] = -1;
	return dis[k];
}
