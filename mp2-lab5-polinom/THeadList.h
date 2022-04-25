#pragma once
#include "TList.h"

using namespace std;

template <class T>
class THeadList : public TList<T>
{
protected:
    TNode<T>* pHead;

public:
    THeadList() {
        pHead = new TNode<T>();
        pHead->pNext = pHead;
        pStop = pHead;
        pLast = pFirst = pHead;
        pCurr = pPrev = pHead;
        len = 0;
    }

    ~THeadList() {
        while (pFirst != pStop) {
            TNode<T>* node = pFirst;
            pFirst = pFirst->pNext;
            delete node;
        }
        delete pHead;
    }

    void insFirst(const T& val) {
        TList::InsFirst(val);
        pHead->pNext = pFirst;
    }

    void delFirst() {
        TList::DelFirst();
        pHead->pNext = pFirst;
    }
};

