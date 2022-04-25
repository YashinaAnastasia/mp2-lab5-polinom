#pragma once
#include "THeadList.h"
#include "TMonom.h"
#include <string>

class TPolinom :
    public THeadList<TMonom>
{
public:
    TPolinom() {
        TMonom m;
        pHead->value = m;
    }

    TPolinom(TPolinom& p){
        for (p.Reset(); !(p.IsEnd()); p.GoNext()){
            insLast(p.pCurr->value);
        }
    }

    void addMonom(const TMonom m) {
        if (m.coef == 0) return;
        if (pLast->value > m) {
            insLast(m);
            return;
        }
        for (Reset(); !IsEnd(); GoNext()) {
            if (pCurr->value == m) {
                pCurr->value.coef += m.coef;
                if (pCurr->value.coef == 0) {
                    DelCurr();
                }
                return;
            }
            if (pCurr->value < m) {
                InsCurr(m);
                return;
            }
        }
        InsFirst(m);
    }

    TPolinom operator=(TPolinom& p) {
        p.Reset();
        Reset();
        while (!IsEnd()) { 
            DelCurr(); 
        }
        while (!p.IsEnd()) { 
            addMonom(p.GetCurrVal()); 
            p.GoNext();
        }
        return *this;
    }

    TPolinom operator+ (TPolinom& p) {
		TPolinom result = *this;
		p.Reset();
		result.Reset();
		while (!p.IsEnd()) {
			if (result.pCurr->value > p.pCurr->value){
				result.GoNext();
			}
			else if (result.pCurr->value < p.pCurr->value) {
				result.InsCurr(p.pCurr->value);
				p.GoNext();
			}
			else {
				result.pCurr->value.coef += p.pCurr->value.coef;
				if (result.pCurr->value.coef != 0) {
					result.GoNext();
                    p.GoNext();
				} else {
					result.DelCurr();
                    p.GoNext();
				}
			}
		}
		return result;
    }

	TPolinom operator* (const double coef) {
		TPolinom result = *this;
        for (result.Reset(); !result.IsEnd(); result.GoNext()) {
            result.pCurr->value.coef *= coef;
        }
		return result;
	}

    std::string ToString() {
        std::string result = "";

        if (len == 0)
            return result;
        for (Reset(); !IsEnd(); GoNext()) {
            result += to_string((int)GetCurrVal().coef)
                + "*x^" + to_string(GetCurrVal().x)
                + "*y^" + to_string(GetCurrVal().y)
                + "*z^" + to_string(GetCurrVal().z);
            if (pCurr->pNext != pStop) {
                result += '+';
            }
        }
        return result;
    }

	friend std::ostream& operator<<(std::ostream& os, TPolinom& p)
	{
		if (p.len == 0)
			return os << 0;
        for (p.Reset(); !p.IsEnd(); p.GoNext()) {
            if (p.pCurr->pNext == p.pStop) {
                os << p.GetCurrVal();
                break;
            }
            os << p.GetCurrVal() << "+";
        }
		return os;
	}

};

