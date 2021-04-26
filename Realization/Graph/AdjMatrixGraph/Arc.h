#ifndef ARC_H
#define ARC_H
#include <bits/stdc++.h>
using namespace std;

template <class ElemType, class WeightType>
class Arc
// 边结点类模板
{
public:
    ElemType _v1, _v2;  //顶点
    WeightType _weight; //权值

    Arc() {}
    Arc(ElemType v1, ElemType v2, WeightType weight) : _v1(v1), _v2(v2), _weight(weight) {}
    bool operator>=(const Arc<ElemType, WeightType> &arc1)
    {
        return this->_weight >= arc1._weight ? true : false;
    }

    bool operator<(const Arc<ElemType, WeightType> &arc1)
    {
        return this->_weight < arc1._weight ? true : false;
    }

    Arc operator=(const Arc<ElemType, WeightType> &arc1)
    {
        if (&arc1 != this)
        {
            this->_v1 = arc1._v1;
            this->_v2 = arc1._v2;
            this->_weight = arc1._weight;
        }
        return *this;
    }

    void SetElem(ElemType v1, ElemType v2, WeightType weight)
    {
        _v1 = v1;
        _v2 = v2;
        _weight = weight;
    }
};

#endif