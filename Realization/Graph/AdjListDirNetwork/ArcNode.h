#ifndef __ADJ_LIST_NETWORK_ARC_H__
#define __ADJ_LIST_NETWORK_ARC_H__
#include <bits/stdc++.h>
// 邻接表网边类
template <class WeightType>
struct ArcNode
{
    int _adjVex;                   //弧头顶点的序号,指向目标节点
    WeightType _weight;            //边的权值
    ArcNode<WeightType> *_nextArc; //下一条边结点的指针

    ArcNode();
    ArcNode(int adjVex, WeightType weight, ArcNode<WeightType> *nextArc = NULL);
};

template <class WeightType>
ArcNode<WeightType>::ArcNode()
//构造一个空的边
{
    _nextArc = NULL;
    _adjVex = -1;
}

template <class WeightType>
ArcNode<WeightType>::ArcNode(int adjVex, WeightType weight, ArcNode<WeightType> *nextArc)
{
    _adjVex = adjVex;
    _weight = weight;
    _nextArc = nextArc;
}
#endif