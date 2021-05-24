/*******************************************************************************
* FileName:         Graph.cpp
* Author:           Your_name
* Student Number:   Student_Number
* Date:             2020/04/29 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #11
*******************************************************************************/

#include "Graph.h"
#include <cstring>
#include <cmath>
#include <algorithm>
using std::abs;
using std::max;
Graph::Graph(int max_v){
	edge = 0;
	v = max_v;
	cuv = 0;
	memset(e,0,sizeof(e));
	memset(head,0,sizeof(head));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	for(int i = 1;i <= v;i++)
		pageRank[i] = 1;
}

Graph::~Graph(){

}

void Graph::addedge(int s, int t, int w){
	if(s > cuv ||t > cuv)
		cuv = max(s,t);
	edge++;
	e[edge].from = t;
	e[edge].to = s;
	e[edge].weight = w;
	e[edge].next = head[t];
	head[t] = edge;
	in[s]++;
	out[t]++;
}

int Graph::getV(){
	return cuv;
}

void Graph::PRIter(){
	for(int i = 1;i <= cuv;i++){
		pageRank[i] = 1.0 - D;
		for(int j = head[i];j;j = e[j].next){
			int t = e[j].to;
			pageRank[i] += (pageRank[t]/(double)in[t])*D;
		}
	}
}

double Graph::getPR(int nv){
	return pageRank[nv];
}
