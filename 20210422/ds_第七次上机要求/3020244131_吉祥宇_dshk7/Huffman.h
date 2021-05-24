/*******************************************************************************
* FileName:         Haffman.h
* Author:           Name
* Student Number:   3020244XXX
* Date:             2021/04/22 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #7
*******************************************************************************/

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <string>
using std::string;

class HuffmanTree{
private:
	struct node{
		node* left;
		node* right;
		node* parent;
		string message;
	};
	node* nodes[60];
	public:
        //Wrap node to sort
	struct cmpnode{
		node* rawnode;
		int fre;
	};
	cmpnode cmpnodes[60];
    //generate charset for each chacater
	void visit(node * root);
    //charset
	string cset[30];
    //number of records
	int nnum = 0;
	int cnum = 0;
    //number of valid input
	int initnum = 0;
	node * root;
public:
    /**
     *  构造函数
        @name HuffmanTree(const int* Table)
        @param arg1 数字出现的频度表
        @return
        注意： 要求树的左孩子为权制较小的编码，左孩子的二进制编号为0
    */
    HuffmanTree(const int* Table);

    /**
     *  析构函数
        @name ~HuffmanTree()
        @param 
        @return
    */
    ~HuffmanTree();

    /**
     *  获取message的霍夫曼编码
        @name string Encode(string)
        @param  arg1 待编码待字符串
        @return 对应的霍夫曼编码
    */
    string Encode(string message);


    /**
     *  获取message的霍夫曼解码
        @name string Decode(stirng)
        @param 
        @return 解码出的内容
    */
    string Decode(string message);
};

#endif
