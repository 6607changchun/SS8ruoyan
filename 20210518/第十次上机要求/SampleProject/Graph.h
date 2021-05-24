/*******************************************************************************
* FileName:         Graph.h
* Author:           Name
* Student Number:   Student_id
* Date:             2020/04/29 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #11
*******************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

class Graph{
private:
	const static int MAX_V = 110;
	const static int MAX_E = 1.1e4; 
	const static double D = 0.5;
	struct node{
		int from;
		int to;
		int weight;
		int next;
	};
	int edge;
	node e[MAX_E];
	int head[MAX_V];
	int in[MAX_V];
	int out[MAX_V];
	int v;
	double pageRank[MAX_V];
	int cuv;
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
     *  向图中加入(s, t)， 权重为w的单向
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
    *  进行一次PR迭代
       @name void PRIter()
       @param  null
       @return  void
   */
   void PRIter();

   /**
    *  获得顶点nv的PR值
       @name int getPR(int nv)
       @param 
       @return  double, 节点的PR值
   */
   double getPR(int nv);

};
#endif
