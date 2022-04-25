#pragma once

template <class T>
struct TNode {
	T value;
	TNode* pNext;

	TNode(const T& val = T(), TNode* next = NULL) : value(val), pNext(next) {}
};

template <class T>
class TList {
protected:
	TNode<T>* pFirst, * pLast, * pStop, * pCurr, * pPrev;
	int len;

public:
	TList(){
		pFirst = pLast = pCurr = pPrev = pStop = NULL;
		len = 0;
	}

	~TList(){
		while (pFirst != pStop){
			TNode<T>* del = pFirst;
			pFirst = pFirst->pNext;
			delete del;
		}
	}

	void InsFirst(T _value) {
		TNode<T>* p = new TNode<T>(_value, pFirst);
		pCurr = p;
		pFirst = p;
		len++;
		if (len == 1) { 
			pLast = pFirst; 
			pLast->pNext = pStop;
		}
	}

	void insLast(const T& _value) {
		TNode<T>* p = new TNode<T>(_value, pStop);
		if (pLast != pStop) { 
			pLast->pNext = p;
			pLast = p;
		}
		else { 
			pFirst = p;
			pLast = p;
		}
		pCurr = p;
		len++;
	}

	void InsCurr(const T& _value) {
		if (pCurr == pFirst) {
			InsFirst(_value);
		}
		else if (pPrev == pLast) {
			InsLast(_value);
		}
		else {
			TNode<T>* p = new TNode<T>(_value, pCurr);
			pPrev->pNext = p;
			pCurr = p;
			len++;
		}
	}

	void DelCurr() {
		if (pCurr != pStop) {
			if (pCurr == pFirst)
				DelFirst();
			else
			{
				TNode<T>* del = pCurr;
				pCurr = pCurr->pNext;
				pPrev->pNext = pCurr;
				delete del;
				len--;
			}
		}
	}

	void DelFirst() {
		if (pFirst != pStop) {
			TNode<T>* del = pFirst;
			pFirst = pFirst->pNext;
			pCurr = pFirst;
			delete del;
			len--;
			if (len == 0) { pLast = pStop; }
		}
	}

	T GetCurrVal() {
		if (pCurr != pStop) return pCurr->value;
		throw "ERROR";
	}

	bool IsEmpty() {
		return len == 0;
	}

	void Reset() {
		pCurr = pFirst;
		pPrev = pStop;
	}

	void GoNext() {
		pPrev = pCurr;
		pCurr = pCurr->pNext;
	}

	bool IsEnd() const { 
		return pCurr == pStop; 
	}

};

