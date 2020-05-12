//
// Created by 邹春旭 on 2020-05-11.
//

#ifndef GEEKAL_SEARCHTREE_H
#define GEEKAL_SEARCHTREE_H

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

class SearchTree {
public:
    SearchTree();

    ~SearchTree();

    void insert(int val);

    int get(int val);

    void del(int val);

    void print();

private:
    TreeNode *treeNode;

    void _insert(TreeNode *treeNode, int val);

    int _get(TreeNode *treeNode, int val);

    void _print(TreeNode *treeNode);
};


#endif //GEEKAL_SEARCHTREE_H
