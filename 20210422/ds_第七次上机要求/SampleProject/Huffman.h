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
	
//	struct rootNode:node{
//		int num;
//		node* nodes[26];
//	} *root;
//	struct fq{
//		char info;
//		int fre;
//	};
//	struct cmp{
//		bool operator()(const fq * a, const fq* b) {
//			if(a->fre < b->fre) return true;
//			else return false;
//		}
//	};
	struct node{
		node* left;
		node* right;
		node* parent;
		string message;
	};
	node* nodes[60];
	public:
	struct cmpnode{
		node* rawnode;
		int fre;
	};
	cmpnode cmpnodes[60];
	void visit(node * root);
	string cset[30];
	int nnum = 0;
	int cnum = 0;
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
