/*******************************************************************************
* FileName:         Graph.h
* Author:           Name
* Student Number:   Student_id
* Date:             2020/04/22 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #11
*******************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H


class Graph{
private:
	const static int MAX_EDGE_NUM = 1e5;
public:
	struct edge{
		int from;
		int to;
		int val;
	};
private:
	edge e[MAX_EDGE_NUM];
	int vnum;
	int edgenum;
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
     *  向图中加入(s, t)， 权重为w的双向边
        @name addedge(int, int, int)
        @param  arg1 边的顶点1
        @param  arg2 边的顶点2
        @param  arg3 边的权重
        @return  void
    */
    void addedge(int s, int t, int w);

    /**
     *  询问这张图的最小生成树(prim算法实现)
        @name int prim()
        @param
        @return  int 最小生成树的权值
    */
    int prim();

    /**
     *  询问这张图的最小生成树(kruskal实现)
        @name int kruskal()
        @param 
        @return  int 最小生成树的权值
    */
    int kruskal();
};

#endif
