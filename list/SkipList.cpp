//
// Created by 邹春旭 on 2020-05-08.
//

#include "SkipList.h"

using namespace std;

CNode::CNode() {
    m_data = -1;
    m_iMaxLevel = 0;
    for (int i = 0; i < MAX_LEVEL; ++i) {
        m_lpForwards[i] = NULL;
    }
}

CNode::~CNode() {

}

CNode **CNode::GetIdxList() {
    return m_lpForwards;
}

void CNode::SetData(int v) {
    m_data = v;
}

int CNode::GetData() {
    return m_data;
}

void CNode::SetLevel(int l) {
    m_iMaxLevel = l;
}

string CNode::toString() {
    char tmp[32];
    string ret;

    ret.append("{ data: ");
    sprintf(tmp, "%d", m_data);
    ret.append(tmp);
    ret.append("; levels: ");
    sprintf(tmp, "%d", m_iMaxLevel);
    ret.append(tmp);
    ret.append(" }");
    return ret;
}

CSkipList::CSkipList() {
    levelCount = 1;
    m_lpHead = new CNode();
}

CSkipList::~CSkipList() {

}

CNode *CSkipList::Find(int v) {
    CNode *lpNode = m_lpHead;

    for (int i = levelCount - 1; i >= 0; --i) {
        while (NULL != lpNode->GetIdxList()[i] && (lpNode->GetIdxList()[i]->GetData() < v)) {
            lpNode = lpNode->GetIdxList()[i];
        }
    }
    if (NULL != lpNode->GetIdxList()[0] && (lpNode->GetIdxList()[0]->GetData() == v)) {
        return lpNode->GetIdxList()[0];
    }
    return NULL;
}

void CSkipList::Insert(int v) {
    CNode *lpNewNode = new CNode();
    if (NULL == lpNewNode) {
        return;
    }

    int level = RandomLevel();
    lpNewNode->SetData(v);
    lpNewNode->SetLevel(level);

    CNode *lpUpdateNode[level];
    for (int i = 0; i < level; ++i) {
        lpUpdateNode[i] = m_lpHead;
    }
    CNode *lpFind = m_lpHead;
    for (int i = level - 1; i >= 0; --i) {
        while ((NULL != lpFind->GetIdxList()[i]) && (lpFind->GetIdxList()[i]->GetData() < v)) {
            lpFind = lpFind->GetIdxList()[i];
        }
        lpUpdateNode[i] = lpFind;
    }

    for (int i = 0; i < level; ++i) {
        lpNewNode->GetIdxList()[i] = lpUpdateNode[i]->GetIdxList()[i];
        lpUpdateNode[i]->GetIdxList()[i] = lpNewNode;
    }

    if (levelCount < level) {
        levelCount = level;
    }
}

int CSkipList::Delete(int v) {
    int ret = -1;
    CNode *lpUpdateNode[levelCount];
    CNode *lpFind = m_lpHead;
    for (int i = levelCount - 1; i >= 0; --i) {
        while ((NULL != lpFind->GetIdxList()[i]) && (lpFind->GetIdxList()[i]->GetData() < v)) {
            lpFind = lpFind->GetIdxList()[i];
        }
        lpUpdateNode[i] = lpFind;
    }

    if (NULL != lpFind->GetIdxList()[0] && (lpFind->GetIdxList()[0]->GetData() == v)) {
        for (int i = levelCount - 1; i >= 0; --i) {
            if (NULL != lpUpdateNode[i]->GetIdxList()[i] && v == lpUpdateNode[i]->GetIdxList()[i]->GetData()) {
                lpUpdateNode[i]->GetIdxList()[i] = lpUpdateNode[i]->GetIdxList()[i]->GetIdxList()[i];
                ret = 0;
            }
        }
    }

    return ret;
}

void CSkipList::PrintAll() {
    CNode *lpNode = m_lpHead;
    while (NULL != lpNode->GetIdxList()[0]) {
        cout << lpNode->GetIdxList()[0]->toString().data() << endl;
        lpNode = lpNode->GetIdxList()[0];
    }
}

void CSkipList::PrintAll(int l) {
    for (int i = MAX_LEVEL - 1; i >= 0; --i) {
        CNode *lpNode = m_lpHead;
        cout << "第" << i << "级" << endl;
        if ((l < 0) || ((l >= 0) && (l == i))) {
            while (NULL != lpNode->GetIdxList()[i]) {
                cout << lpNode->GetIdxList()[i]->GetData() << " ";
                lpNode = lpNode->GetIdxList()[i];
            }
            cout << endl;
            if (l >= 0) break;
        }
    }
}

int GetRandom() {
    static int _count = 1;
    default_random_engine generator(time(0) + _count);
    uniform_int_distribution<int> distribution(1, 99999);
    int dice_roll = distribution(generator);
    _count += 100;
    return dice_roll;
}

int CSkipList::RandomLevel() {
    int level = 1;
    for (int i = 1; i < MAX_LEVEL; ++i) {
        if (1 == (GetRandom() % 3)) {
            level++;
        }
    }
    return level;
}