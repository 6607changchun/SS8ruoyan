#ifndef DuLink_H
#define DuLink_H

class DuLink
{
private:
    //value为节点的值， next为后继节点。
    struct node{
        int value;
        node* next;
        node* prev; 
    };
    // a pointer point to link list.
    node* head;
    // the number of elements in DuLink.
    int len;

public:
    /**
        构造函数，构建一个 DuLink。
        @name DuLink();
        @param 
        @return 
    */
    DuLink();

    /**
        询问DuLink现有元素的个数
        @name length();
        @param 
        @return int 当前link list包含元素的个数
    */
    int length() const;

    /**
        获取location位置的元素（从0开始标号)
        @name getData(const int&);
        @param  location 需要查询元素的位置
        @return int link list在lication的元素
    */
    int getData(const int& location) const;

    /**
        插入元素
        @name insert(const int&, const int&);
        @param  data        需要插入的元素
                location    插入元素的位置
        @return void
    */
    void insert(const int &data, const int& location);

    /**
        删除位于location的元素
        @name remove(const int&);
        @param  location 需要删除元素的位置
        @return bool    true 删除成功，false删除失败
    */
    bool remove(const int& location);


    /**
     *  将链表进行翻转操作。
        @name converse();
        @param 
        @return void
        例如， DuLink开始为 1 2 3 4 5，
        则翻转后为  5 4 3 2 1
    */
    void converse();

    /**
        将append_list拼接到当前链表后
        @name append(const DuLink&);
        @param  l
        @return bool    true 删除成功，false删除失败
    */
    void append(const DuLink& append_list);

    /**
        析构函数
        @name ~DuLink();
        @param  
        @return
    */
    ~DuLink();
};
#endif
