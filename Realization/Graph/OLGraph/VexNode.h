#ifndef __ADJ_LIST_NETWORK_VEX_H__
#define __ADJ_LIST_NETWORK_VEX_H__
#include <bits/stdc++.h>
// 结点类
template <class ElemType, class WeightType>
struct VexNode
{
    //数据成员
    ElemType _data;                    //顶点值
    ArcNode<WeightType> *_firstInArc;  //指向以该顶点为弧头的第一个节点的指针
    ArcNode<WeightType> *_firstOutArc; //指向以该顶点为弧尾的第一个节点的指针

    VexNode();
    VexNode(ElemType data, ArcNode<WeightType> *firstInArc = NULL, ArcNode<WeightType> *firstOutArc = NULL);
};

template <class ElemType, class WeightType>
VexNode<ElemType, WeightType>::VexNode()
//构造空顶点节点
{
    _firstInArc = NULL;
    _firstOutArc = NULL;
}
template <class ElemType, class WeightType>
VexNode<ElemType, WeightType>::VexNode(ElemType data, ArcNode<WeightType> *firstInArc, ArcNode<WeightType> *firstOutArc)
//构造空顶点节点
{
    _data = data;
    _firstInArc = firstInArc;
    _firstOutArc = firstOutArc;
}
#endif