//
// Created by 邹春旭 on 2020-05-11.
//

#include "SearchTree.h"
#include <iostream>
#include <queue>

using namespace std;

void SearchTree::insert(int val) {
    _insert(treeNode, val);
}


int SearchTree::get(int val) {
    return _get(treeNode, val);
}

SearchTree::SearchTree() {
    treeNode = new TreeNode;
    treeNode->val = -999;
    treeNode->left = nullptr;
    treeNode->right = nullptr;
}

SearchTree::~SearchTree() {

}

void SearchTree::_insert(TreeNode *t, int val) {

    if (t->val < val) {
//        cout << (t->right != nullptr) << endl;
        if (t->right != nullptr) {
            _insert(t->right, val);
            return;
        }

        t->right = new TreeNode;
        t->right->val = val;
        t->right->left = nullptr;
        t->right->right = nullptr;

    } else if (t->val > val) {
        if (t->left != nullptr) {
            _insert(t->left, val);
            return;
        }

        t->left = new TreeNode;

        t->left->val = val;
        t->left->left = nullptr;
        t->left->right = nullptr;
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

    return -1;

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

    if (pp == nullptr) {
        treeNode = child;
    } else if (pp->left == p) {
        pp->left = child;
    } else {
        pp->right = child;
    }


}

void SearchTree::print() {
    _print(treeNode);
}

void SearchTree::_print(TreeNode *t) {
    if (t == nullptr) {
        return;
    }

    _print(t->left);
    cout << t->val << endl;
    _print(t->right);
}

void SearchTree::reserve() {
    _reserve(treeNode);
}

void SearchTree::_reserve(TreeNode *t) {

    if (t == nullptr) {
        return;
    }

    _reserve(t->left);
    _reserve(t->right);


    TreeNode *tmp = t->left;
    t->left = t->right;
    t->right = tmp;
}


int SearchTree::_getDepth(TreeNode *t) {
    if (t == nullptr) {
        return 0;
    }

    return max(_getDepth(t->left), _getDepth(t->right)) + 1;
}

int SearchTree::getDepth() {
    return _getDepth(treeNode);
}

void SearchTree::floorLevelTree() {
    queue<TreeNode *> q;


    q.push(treeNode);

    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();


        cout << tmp->val << endl;

        if (tmp->left != nullptr) {
            q.push(tmp->left);
        }

        if (tmp->right != nullptr) {
            q.push(tmp->right);
        }
    }


}


