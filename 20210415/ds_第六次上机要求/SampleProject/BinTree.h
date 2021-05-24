/*******************************************************************************
* FileName:         BinTree.h
* Author:           Your_Name
* Student Number:   3019244xxx
* Date:             2020/04/01 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #6
*******************************************************************************/

#ifndef BinTree_H
#define BinTree_H

class BinTree{
private:
    struct node{
    	node* left;
    	node* right;
    	int val;
    	int height;
    };
    const static int MAX_ELEMENTS = 11000;
    node * nodes[MAX_ELEMENTS];
    int num;
    node* root;
public:
    /**
     *  构造函数，初始化二叉排序树
        @name BinTree();
        @param
        @return 
    */
    BinTree();


    /**
     *  析构函数，销毁二叉排序树
        @name ~BinTree();
        @param 
        @return 
    */
    ~BinTree();

    /**
     *  在二叉排序树中插入元素val，在插入过程中，节点编号从1开始逐渐递增。
        @name insert(int val)
        @param arg1  需要插入的元素值.
        @param arg2  插入元素的父亲节点编号，如果此项值为0，则表示为根结点。
        @param arg3  此元素是左子还是右子。 -1表示左子，1表示右子。
        @return  void
    */
    void insert(int val, int parent, int flg);


    /**
     *  使用前序遍历遍历二叉排序树
        @name p_traversal() const
        @param 
        @return  int*
                 二叉排序树遍历结果,结果需要保存在int数组中。
    */
    int* p_traversal() const;


    /**
     *  使用前序遍历遍历二叉排序树
        @name p_traversal() const
        @param 
        @return  int*
                 二叉排序树遍历结果,结果需要保存在int数组中。
    */
    int* m_traversal() const;

    /**
     *  获得二叉树节点总数
        @name countNode() const
        @param 
        @return  int 二叉树节点数量
    */
    int countNode() const;

    /**
     *  获得二叉树高度
        @name height() const
        @param 
        @return  int 二叉树高度
    */
    int height() const;
};

#endif
