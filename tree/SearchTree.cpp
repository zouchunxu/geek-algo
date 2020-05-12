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

void SearchTree::del(int val) {
    TreeNode *p = treeNode;
    TreeNode *pp = nullptr;

    while (p != nullptr) {
        if (p->val == val) {
            break;
        } else if (p->val < val) {
            pp = p;
            p = p->right;
        } else if (p->val > val) {
            pp = p;
            p = p->left;
        }
    }

    if (p == nullptr) {
        return;
    }

    TreeNode *min;
    TreeNode *minP;
    if (pp->left != nullptr && pp->right != nullptr) {

        TreeNode *tmp = pp->right;


        while (tmp->left != nullptr) {
            minP = tmp;
            tmp = tmp->left;
        }

        min = tmp;

        p->val = min->val;
        p = min;
        pp = minP;
    }


    TreeNode *child;

    if (p->left != nullptr) {
        child = p->left;
    } else if (p->right != nullptr) {
        child = p->right;
    } else {
        child = nullptr;
    }

    if(pp == nullptr){
        treeNode = child;
    } else if(pp->left == p) {
        pp->left = child;
    } else {
        pp->right = child;
    }


}
