/*******************************************************************************
* FileName:         Graph.cpp
* Author:           Your_name
* Student Number:   Student_Number
* Date:             2020/04/29 09:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #11
*******************************************************************************/

#include "Graph.h"
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using std::cout;
using std::endl;
using std::max;
using std::min;

Graph::Graph(int max_v){
	edge = 0;
	memset(e,0,sizeof(e));
	memset(head,0,sizeof(head));
	memset(in,0,sizeof(in));
	memset(head_re,0,sizeof(head_re));
	memset(e_re,0,sizeof(e_re));
	memset(in_re,0,sizeof(in_re));
	v = max_v;
}

Graph::~Graph(){

}

void Graph::addedge(int s, int t, int w){
	edge++;
	e[edge].from = s;
	e[edge].to = t;
	e[edge].weight = w;
	e[edge].next = head[s];
	head[s] = edge;
	in[t]++;
	e_re[edge].from = t;
	e_re[edge].to = s;
	e_re[edge].weight = w;
	e_re[edge].next = head_re[t];
	head_re[t] = edge;
	in_re[s]++;
}

int Graph::getV(){
	return v;
}

int* Graph::topological(){
	int n = 0;
	int* result = new int[v+1];
	int* in_copy = new int[v+1];
	for(int i = 1;i <= v;i++)
		in_copy[i] = in[i];
	while(n < v){
		for(int i = 1;i <= v;i++)
		if(!in_copy[i]){
			n++;
			result[n] = i;
			in_copy[i] = -1;
			for(int j = head[i];j;j = e[j].next){
				int t = e[j].to;
				in_copy[t]--;
			}
		}
	}
	for(int i = 0;i < n;i++)
		result[i] = result[i+1];
	delete[] in_copy;
	return result;
}
int* Graph::re_topo(){
	int n = 0;
	int* result = new int[v+1];
	int* in_re_copy = new int[v+1];
	for(int i = 1;i <= v;i++){
		in_re_copy[i] = in_re[i];
	}
	while(n < v){
		for(int i = 1;i <= v;i++){
			if(!in_re_copy[i]){
				n++;
				result[n] = i;
				in_re_copy[i] = -1;
				for(int j = head_re[i];j;j = e_re[j].next){
					int t = e_re[j].to;
					in_re_copy[t]--;
				}
			}
		}
	}
	for(int i = 0;i < n;i++)
		result[i] = result[i+1];
	delete[] in_re_copy;
	return result;
}
int* Graph::ka(){
	int vl[v+1];
	int ve[v+1];
	int l[edge+1];
	int ea[edge+1];
	int keys[v+1];
	int* result = new int[v+1];
	int n = 0;
	memset(vl,0,sizeof(vl));
	memset(ve,0,sizeof(ve));
	memset(l,0,sizeof(l));
	memset(ea,0,sizeof(ea));
	memset(keys,0,sizeof(keys));
	int* topo = Graph::topological();
	int* topo_re = Graph::re_topo();
	for(int i = 0;i < v;i++){
		int s = topo[i];
		for(int j = head[s];j;j = e[j].next){
			int t = e[j].to;
			ve[t] = max(ve[t],ve[s]+e[j].weight);
		}
	}
	for(int i = 0;i < v;i++){
		vl[topo_re[i]] = 0x3f3f3f3f;
		if(!in_re[topo_re[i]])
			vl[topo_re[i]] = ve[topo_re[i]];
	}
	for(int i = 0;i < v;i++){
		int s = topo_re[i];
		for(int j = head[s];j;j = e[j].next){
			int t = e[j].to;
			vl[s] = min(vl[s],vl[t] - e[j].weight);
		}
	}
	for(int i = 1;i <= edge;i++)
		ea[i] = ve[e[i].from];
	for(int i = 1;i <= edge;i++)
		l[i] = vl[e[i].to] - e[i].weight;
	for(int i = 1;i <= edge;i++){
		if(ea[i] == l[i]){
			keys[e[i].from] = 1;
			keys[e[i].to] = 1;
		}
	}
	for(int i = 1;i <= v;i++)
		if(keys[i]){
			result[n++] = i;
		}
	delete[] topo;
	delete[] topo_re;
	return result;
}
