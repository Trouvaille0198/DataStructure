#ifndef __ARCNODE_H__
#define __ARCNODE_H__
#include <bits/stdc++.h>
// 边类
template <class WeightType>
struct ArcNode
{
    int _tailVex;                      // 弧尾结点的序号
    int _headVex;                      // 弧头结点的序号
    ArcNode<WeightType> *_tailNextArc; //指向下一个弧尾相同的边的指针
    ArcNode<WeightType> *_headNextArc; //指向下一个弧头相同的边的指针
    WeightType _weight;                //边的权值

    ArcNode();
    ArcNode(int tailVex, int headVex, WeightType weight,
            ArcNode<WeightType> *tailNextArc = NULL,
            ArcNode<WeightType> *headNextArc = NULL);
};

template <class WeightType>
ArcNode<WeightType>::ArcNode()
//构造一个空的边
{
    _tailNextArc = NULL;
    _headNextArc = NULL;
    _tailVex = -1;
    _headVex = -1;
}

template <class WeightType>
ArcNode<WeightType>::ArcNode(int tailVex, int headVex, WeightType weight,
                             ArcNode<WeightType> *tailNextArc,
                             ArcNode<WeightType> *headNextArc)
{
    _tailVex = tailVex;
    _headVex = headVex;
    _tailNextArc = tailNextArc;
    _headNextArc = headNextArc;
    _weight = weight;
}
#endif