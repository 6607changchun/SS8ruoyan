/*******************************************************************************
* FileName:         SeqList.h
* Author:           田原
* Student Number:   3020218126
* Date:             2021/03/11 11:24:55
* Version:          v1.0
* Description:      Data Structure Experiment #1
*                   这个是助教完成的 SeqList.h 文件，请不要更改里面的内容
*******************************************************************************/

#ifndef SEQLIST_H
#define SEQLIST_H

class SeqList
{
private:

    // max size of the list.
    const int LIST_SIZE;
    // a pointer point to list.
    int *seq;
    // the number of elements in Seqlist.
    int len;

public:
    /**
        构造函数，构建一个 SeqList。
        @name SeqList(const int&);
        @param  listSize  SeqList的最多元素个数
        @return 
    */
    SeqList(const int &listSize);

    /**
        判断元素data是否在list中。
        @name isIn(const int&);
        @param  data  需要判定的data
        @return bool    false SeqList中不包含data
                        true  SeqList中包含data
    */
    bool isIn(const int &data);

    /**
        询问SeqList现有元素的个数
        @name length();
        @param 
        @return int SeqList包含元素的个数
    */
    int length();

    /**
        获取location位置的元素（从0开始标号)
        @name getData(const int&);
        @param  location 需要查询元素的位置
        @return int SeqList在lication的元素
    */
    int getData(const int& location);

    /**
        插入元素
        @name insert(const int&, const int&);
        @param  data        需要插入的元素
                location    插入元素的位置
        @return bool    false 插入失败
                        true 插入成功
    */
    bool insert(const int &data, const int& location);

    /**
        删除位于location的元素
        @name remove(const int&);
        @param  location 需要删除元素的位置
        @return bool    true 删除成功，false删除失败
    */
    bool remove(const int& location);

    /**
        析构函数
        @name ~SeqList();
        @param  
        @return
    */
    ~SeqList();
};
#endif