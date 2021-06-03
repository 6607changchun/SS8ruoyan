#ifndef BST_H
#define BST_H

class BST{
private:
	const static int LEAF = 1;
	const static int LEFT_CHILD = 2;
	const static int RIGHT_CHILD = 3;
	struct node{
		int key;
		int value;
		node* left;
		node* right;
	};
	node* root;
	int deleteNode(node* root,node* parent,int mode);
public:
    /**
     *  类的构造函数
        @name BST(int)
        @param  arg1 最大的定点数
        @return  
    */
    BST(int max_v);

    /**
     *  类的析构函数
        @name ~BST()
        @param 
        @return 
    */
    ~BST();

    

    /**
     *  查找
    */
  int Get(int Key);
   /*
   * 插入
   */
  void BSTInsert(int Key,int Value);
  /*
  * 删除
  */
 int Delete(int key);
};
#endif
