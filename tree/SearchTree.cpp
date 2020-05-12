//
// Created by 邹春旭 on 2020-05-11.
//

#include "SearchTree.h"

void SearchTree::insert(int val) {
    _insert(treeNode, val);
}


int SearchTree::get(int val) {
    return _get(treeNode, val);
}

SearchTree::SearchTree() {
    treeNode = new TreeNode;
    treeNode->val = -999;
}

SearchTree::~SearchTree() {

}

void SearchTree::_insert(TreeNode *t, int val) {

    if (t->val < val) {

        if (t->right != nullptr) {
            _insert(t->right, val);
            return;
        }

        t->right = new TreeNode;
        t->right->val = val;

    } else if (t->val > val) {
        if (t->left != nullptr) {
            _insert(t->left, val);
            return;
        }

        t->left = new TreeNode;

        t->val = val;

    }


}

int SearchTree::_get(TreeNode *t, int val) {
    if (t == nullptr) {
        return -1;
    }

    if (t->val == val) {
        return t->val;
    } else if (t->val < val) {
        return _get(t->right, val);
    } else if (t->val > val) {
        return _get(t->left, val);
    }

}
