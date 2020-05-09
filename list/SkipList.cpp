//
// Created by 邹春旭 on 2020-05-08.
//

#include "SkipList.h"

CNode::CNode() {
    m_data = -1;
    m_iMaxLevel = 0;
    for (int i = 0; i < MAX_LEVEL; i++) {
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

std::string CNode::toString() {
    char tmp[32];
    std::string ret;

    ret.append("{ data: ");
    sprintf(tmp, "%d", m_data);
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
    CNode *head = m_lpHead;

    for (int i = levelCount - 1; i >= 0; i--) {
        while (head->GetIdxList()[i] != NULL && head->GetIdxList()[i]->GetData() < v) {
            head = head->GetIdxList()[i];
        }
    }

    if (head->GetIdxList()[0] != NULL && head->GetIdxList()[0]->GetData() == v) {
        return head->GetIdxList()[0];
    }

    return nullptr;
}

void CSkipList::Insert(int v) {
    auto *node = new CNode();
    int level = RandomLevel();
    node->SetData(v);
    node->SetLevel(level);

    CNode *updateNode[level];

    for (int i = 0; i < level; ++i) {
        updateNode[i] = m_lpHead;
    }


    CNode *head = m_lpHead;

    for (int i = levelCount - 1; i >= 0; i--) {
        while (head->GetIdxList()[i] != NULL && head->GetIdxList()[i]->GetData() < v) {
            head = head->GetIdxList()[i];
        }
        updateNode[i] = head;
    }

    for (int i = 0; i < level; ++i) {
        node->GetIdxList()[i] = updateNode[i]->GetIdxList()[i];
        updateNode[i]->GetIdxList()[i] = node;
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
        /**
         * 查找小于v的节点(lpFind).
        */
        while ((NULL != lpFind->GetIdxList()[i]) && (lpFind->GetIdxList()[i]->GetData() < v)) {
            lpFind = lpFind->GetIdxList()[i];
        }
        lpUpdateNode[i] = lpFind;
    }
    /**
     * lpFind 是小于v的节点, lpFind的下一个节点就等于或大于v的节点
    */
    if ((NULL != lpFind->GetIdxList()[0]) && (lpFind->GetIdxList()[0]->GetData() == v)) {
        for (int i = levelCount - 1; i >= 0; --i) {
            if ((NULL != lpUpdateNode[i]->GetIdxList()[i]) && (v == lpUpdateNode[i]->GetIdxList()[i]->GetData())) {
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
        std::cout << lpNode->GetIdxList()[0]->toString().data() << std::endl;
        lpNode = lpNode->GetIdxList()[0];
    }
}

void CSkipList::PrintAll(int l) {
    for (int i = MAX_LEVEL - 1; i >= 0; --i) {
        CNode *lpNode = m_lpHead;
        std::cout << "第" << i << "级:" << std::endl;
        if ((l < 0) || ((l >= 0) && (l == i))) {
            while (NULL != lpNode->GetIdxList()[i]) {
                std::cout << lpNode->GetIdxList()[i]->GetData() << " ";
                lpNode = lpNode->GetIdxList()[i];
            }
            std::cout << std::endl;
            if (l >= 0) {
                break;
            }
        }
    }
}

int GetRandom() {
    static int _count = 1;
    std::default_random_engine generator(time(0) + _count);
    std::uniform_int_distribution<int> distribution(1, 99999/*0x7FFFFFFF*/);
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

