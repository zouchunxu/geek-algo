//
// Created by 邹春旭 on 2020-05-08.
//

#ifndef GEEKAL_SKIPLIST_H
#define GEEKAL_SKIPLIST_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <random>
#include <ctime>
using namespace std;

/**
 * 跳表的一种实现方法。
 * 跳表中存储的是正整数，并且存储的是不重复的。
 *
 * 跳表的C++版本.
 * 翻译JAVA版本 原作者 Author：ZHENG
 *
 * Author：puhuaqiang
 *
 *  跳表结构:
 *
 *  第K级           1           9
 *  第K-1级         1     5     9
 *  第K-2级         1  3  5  7  9
 *  ...             ....
 *  第0级(原始链表)  1  2  3  4  5  6  7  8  9
 */

const int MAX_LEVEL = 16;

/**
 * @brief 节点
*/
class CNode
{
public:
    CNode();
    ~CNode();

    std::string toString();
    /**
     * @brief 获取索引链表
    */
    CNode** GetIdxList();

    /**
     * @brief 设置数据
    */
    void SetData(int v);
    /**
     * @brief 获取数据
    */
    int GetData();
    /**
    * @brief 设置最大索引级别
    */
    void SetLevel(int l);
private:
    /**当前节点的值*/
    int m_data;
    /**
     * 当前节点的每个等级的下一个节点.
     * 第2级 N1 N2
     * 第1级 N1 N2
     * 如果N1是本节点,则 m_lpForwards[x] 保存的是N2
     *
     * [0] 就是原始链表.
     */
    CNode* m_lpForwards[MAX_LEVEL];
    /**当前节点的所在的最大索引级别*/
    int m_iMaxLevel;
};

/**
 * @brief 跳表
*/
class CSkipList
{
public:
    CSkipList();
    ~CSkipList();
    /**
     * @brief 查找指定的值的节点
     * @param v 正整数
    */
    CNode* Find(int v);
    /**
     * @brief 插入指定的值
     * @param v 正整数
    */
    void Insert(int v);
    /**
     * @brief 删除指定的值的节点
     * @param v 正整数
    */
    int Delete(int v);
    void PrintAll();
    /**
     * @brief 打印跳表结构
     * @param l 等于-1时打印所有级别的结构 >=0时打印指定级别的结构
    */
    void PrintAll(int l);
    /**
     * @brief 插入节点时,得到插入K级的随机函数
     * @return K
    */
    int RandomLevel();

private:
    int levelCount;
    /**
     * 链表
     * 带头/哨所(节点)
    */
    CNode* m_lpHead;
};


#endif //GEEKAL_SKIPLIST_H
