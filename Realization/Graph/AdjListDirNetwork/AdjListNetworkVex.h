#ifndef __ADJ_LIST_NETWORK_VEX_H__
#define __ADJ_LIST_NETWORK_VEX_H__
#include <bits/stdc++.h>
// 邻接表网顶点结点类
template <class ElemType, class WeightType>
struct AdjListNetworkVex
{
    //数据成员
    ElemType _data;                           //顶点值
    AdjListNetworkArc<WeightType> *_firstArc; //指向邻接链表第一个节点的指针

    AdjListNetworkVex();
    AdjListNetworkVex(ElemType data, AdjListNetworkArc<WeightType> *firstArc = NULL);
};

template <class ElemType, class WeightType>
AdjListNetworkVex<ElemType, WeightType>::AdjListNetworkVex()
//构造空顶点节点
{
    _firstArc = NULL;
}
template <class ElemType, class WeightType>
AdjListNetworkVex<ElemType, WeightType>::AdjListNetworkVex(ElemType data, AdjListNetworkArc<WeightType> *firstArc)
//构造空顶点节点
{
    _data = data;
    _firstArc = firstArc;
}
#endif