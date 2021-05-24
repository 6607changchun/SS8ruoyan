/*******************************************************************************
* FileName:         Graph.cpp
* Author:           Your_name
* Student Number:   Student_Number
* Date:             2020/04/22 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #11
*******************************************************************************/

#include "Graph.h"
#include <cstring>
#include <algorithm>
#include <cstdio>
Graph::Graph(int max_v){
	vnum = max_v;
	edgenum = 0;
	std::memset(e,0,sizeof(e));
}

Graph::~Graph(){
	
}

void Graph::addedge(int s, int t, int w){
	edgenum++;
	e[edgenum].from = s;
	e[edgenum].to = t;
	e[edgenum].val = w;
	edgenum++;
	e[edgenum].from = t;
	e[edgenum].to = s;
	e[edgenum].val = w;
}

bool cmp(const Graph::edge& a,const Graph::edge & b){
	return a.val < b.val;
}
int Graph::prim(){
//	printf("prim:\n");
//	for(int i = 1;i <= edgenum;i++)
//		printf("from:%d,to:%d,weight:%d\n",e[i].from,e[i].to,e[i].val);
	int sum = 0;
	int treev = 1;
	int minv[vnum+1];
	int nearv[vnum+1];
	std::memset(minv,0x3f,sizeof(minv));
	std::memset(nearv,0,sizeof(nearv));
	nearv[1] = -1;
	minv[1] = 0;
	while(treev != vnum){
//		printf("treev:%d,sum:%d\n",treev,sum);
		for(int i = 1;i <= edgenum;i++){
		int f = e[i].from;
		int t = e[i].to;
		int weight = e[i].val;
		if(nearv[t] == -1) continue;
		if(weight < minv[t] && nearv[f] == -1){
			minv[t] = weight;
			nearv[t] = f;
			}
		}
		int mine = 0x3f3f3f3f;
		int mini = 1;
		for(int i = 2;i <= vnum;i++)
			if(minv[i] < mine && nearv[i] != -1){
				mine = minv[i];
				mini = i;
			}
		nearv[mini] = -1;
		sum += mine;
		treev++; 
	}
	return sum;
}
int Graph::kruskal(){
//	printf("kruskal:\n");
//	for(int i = 1;i <= edgenum;i++)
//		printf("from:%d,to:%d,weight:%d\n",e[i].from,e[i].to,e[i].val);
	int inTree[vnum+1];
	std::memset(inTree,0,sizeof(inTree));
	int treee = 0;
	int i = 0;
	int sum = 0;
	std::sort(e,e+edgenum,cmp);
	while(treee != vnum - 1){
		if(!e[i].val) {i++;continue;}
		if(inTree[e[i].from] && inTree[e[i].to]){
			i++;continue;
		}
		sum += e[i].val;
		inTree[e[i].from] = 1;
		inTree[e[i].to] = 1;
		i++;
		treee++;
	}
	return sum;
}
