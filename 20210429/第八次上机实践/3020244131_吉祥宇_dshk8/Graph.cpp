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
Graph::Graph(int max_v){
	//init
	vnum = max_v;
	edgenum = 0;
	std::memset(e,0,sizeof(e));
}

Graph::~Graph(){
	//no dynamic allocated space for collection
}

void Graph::addedge(int s, int t, int w){
	//for undirected graph, we need to store edge twice
	//because we can only store one single direction at one time
	edgenum++;
	e[edgenum].from = s;
	e[edgenum].to = t;
	e[edgenum].val = w;
	edgenum++;
	e[edgenum].from = t;
	e[edgenum].to = s;
	e[edgenum].val = w;
}

//define customized cmp function for sorting
bool cmp(const Graph::edge& a,const Graph::edge & b){
	return a.val < b.val;
}
int Graph::prim(){
	//define and initialize mininum cost, number of vextices in tree and temporary arrays
	int sum = 0;
	int treev = 1;
	int minv[vnum+1];
	int nearv[vnum+1];
	std::memset(minv,0x3f,sizeof(minv));
	std::memset(nearv,0,sizeof(nearv));
	//prepare for loop
	//start with v1
	nearv[1] = -1;
	minv[1] = 0;
	while(treev != vnum){
		//not all vextices are chosen
		for(int i = 1;i <= edgenum;i++){
			//travel through the edge list to update temporary arrays
		int f = e[i].from;
		int t = e[i].to;
		int weight = e[i].val;
		//chosen
		if(nearv[t] == -1) continue;
		//some mininum cost edge exists
		if(weight < minv[t] && nearv[f] == -1){
			minv[t] = weight;
			nearv[t] = f;
			}
		}
		int mine = 0x3f3f3f3f;
		int mini = 1;
		//find the minunum edge
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
