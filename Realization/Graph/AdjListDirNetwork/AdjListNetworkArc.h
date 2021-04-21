#ifndef __ADJ_LIST_NETWORK_ARC_H__
#define __ADJ_LIST_NETWORK_ARC_H__
#include <bits/stdc++.h>
// 邻接表网边类
template <class WeightType>
struct AdjListNetworkArc
{
    int _adjVex;                             //弧头顶点的序号,指向目标节点
    WeightType _weight;                      //边的权值
    AdjListNetworkArc<WeightType> *_nextArc; //下一条边结点的指针

    AdjListNetworkArc();
    AdjListNetworkArc(int adjVex, WeightType weight, AdjListNetworkArc<WeightType> *nextArc = NULL);
};

template <class WeightType>
AdjListNetworkArc<WeightType>::AdjListNetworkArc()
//构造一个空的边
{
    _adjVex = -1;
}

template <class WeightType>
AdjListNetworkArc<WeightType>::AdjListNetworkArc(int adjVex, WeightType weight, AdjListNetworkArc<WeightType> *nextArc)
{
    _adjVex = adjVex;
    _weight = weight;
    _nextArc = nextArc;
}
#endif