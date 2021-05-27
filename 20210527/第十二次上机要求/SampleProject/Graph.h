/*******************************************************************************
* FileName:         Graph.h
* Author:           Name
* Student Number:   Student_id
* Date:             2021/05/06 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #13
*******************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

class Graph{
private:
	const static int MAX_N = 1.1e3;
	const static int MAX_V = 1.1e2;
	struct node{
		int from;
		int to;
		int w;
		int next;
	};
	node e[MAX_N];
	int v;
	int edge;
	int head[MAX_V];
	int dis[MAX_V];
public:
    /**
     *  类的构造函数
        @name Graph(int)
        @param  arg1 最大的定点数
        @return  
    */
    Graph(int max_v);

    /**
     *  类的析构函数
        @name ~Graph()
        @param 
        @return 
    */
    ~Graph();

    /**
     *  向图中加入(s, t)， 权重为w的单向边
        @name addedge(int, int, int)
        @param  arg1 边的顶点1
        @param  arg2 边的顶点2
        @param  arg3 边的权重
        @return  void
    */
    void addedge(int s, int t, int w);

    /**
     *  询问图中节点的个数
        @name int getV()
        @param 
        @return  int 图中节点的个数
    */
    int getV();

   /**
    *  询问从1出发，到达点k的最短路
       @name int getdist(int k)
       @param 
       @return  int 从点1到点k的最短路
   */
   int getdist(int k);
};
#endif
