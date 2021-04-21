#ifndef __ADJ_LIST_GRAPH_H__
#define __ADJ_LIST_GRAPH_H__

#include "ArcNode.h"               // 网络邻接表的边结点类
#include "VexNode.h"               // 网络邻接表的顶点结点类
#include "../../SeqList/SeqList.h" //顺序表
#include <bits/stdc++.h>
using namespace std;
const int DEFAULT_SIZE = 100;
const int DEFAULT_INFINITY = 1000;

// 有向网的邻接表类
template <class ElemType, class WeightType>
class AdjListGraph
{
protected:
    //注意，顶点数包含在顺序表的数据成员中
    int _vexMaxNum, _arcNum;                          //最大顶点数，边数
    SeqList<VexNode<ElemType, WeightType>> _vexTable; //顶点表
    int *_tag;                                        //标志数组
    WeightType _infinity;

public:
    //int v表示顶点v的索引; ElemType vexValue表示顶点vex的元素值
    AdjListGraph(int vexMaxNum = DEFAULT_SIZE,
                 WeightType infinity = (WeightType)DEFAULT_INFINITY);
    AdjListGraph(ElemType *vex, int vexNum, int vexMaxNum = DEFAULT_SIZE,
                 WeightType infinity = (WeightType)DEFAULT_INFINITY);
    ~AdjListGraph();
    void Clear();
    bool IsEmpty();
    int GetOrder(ElemType vex) const;             //求顶点序号
    ElemType GetElem(int index) const;            //求指定下标的顶点值
    void SetElem(int index, ElemType vex);        //更新指定下标的顶点值
    WeightType GetInfinity() const;               // 取无穷大的值
    int GetVexNum() const;                        // 求顶点个数
    int GetArcNum() const;                        // 求边数
    int FirstAdjVex(int v) const;                 //求v的第一个邻接点的下标
    int NextAdjVex(int v1, int v2) const;         //求v1相对于v2的下一个邻接点的下标
    void InsertVex(const ElemType &vexValue);     //插入顶点
    void InsertArc(int v1, int v2, WeightType w); //插入边
    void DeleteVex(const ElemType &vexValue);     //删除顶点
    void DeleteArc(int v1, int v2);               //删除边
    WeightType GetWeight(int v1, int v2) const;   // 求从顶点为v1到v2的边的权值
    void SetWeight(int v1, int v2, WeightType w); // 设置从顶点为v1到v2的边的权值
    int GetTag(int v) const;                      //求顶点v的标志值
    void SetTag(int v, int value);                //设置顶点v的标志值
    void Display() const;                         //打印图
};

template <class ElemType, class WeightType>
AdjListGraph<ElemType, WeightType>::AdjListGraph(int vexMaxNum, WeightType infinity)
// 操作结果：构造顶点最大数目为vexMaxNum,infinity表示无穷大的空有向网
{

    _vexMaxNum = vexMaxNum;
    _infinity = infinity;
    _arcNum = 0;

    _tag = new int[_vexMaxNum];
    _vexTable = SeqList<VexNode<ElemType, WeightType>>(_vexMaxNum);
}

template <class ElemType, class WeightType>
AdjListGraph<ElemType, WeightType>::AdjListGraph(ElemType *vex, int vexNum,
                                                 int vexMaxNum, WeightType infinity)
{
    _vexMaxNum = vexMaxNum;
    _infinity = infinity;
    _arcNum = 0;

    _tag = new int[_vexMaxNum];

    VexNode<ElemType, WeightType> node[vexNum];
    for (int i = 0; i < vexNum; i++)
        node[i]._data = vex[i];

    _vexTable = SeqList<VexNode<ElemType, WeightType>>(node, vexNum, _vexMaxNum);
    for (int i = 0; i < vexMaxNum; i++)
    {
        _tag[i] = 0;
    }
}

template <class ElemType, class WeightType>
void AdjListGraph<ElemType, WeightType>::Clear()
// 释放所有边，并把顶点数和边数设为零
{
    ArcNode<WeightType> *p;
    for (int i = 0; i < GetVexNum(); i++)
    { // 释放边节点
        p = _vexTable.GetElem(i)._firstArc;
        while (p != NULL)
        // 遍历并删除节点
        {
            _vexTable._data[i]._firstArc = p->_nextArc;
            delete p;
            p = _vexTable.GetElem(i)._firstArc;
        }
    }
    _vexTable.ClearList(); //顶点数置零
    _arcNum = 0;
}

template <class ElemType, class WeightType>
AdjListGraph<ElemType, WeightType>::~AdjListGraph()
{
    Clear();
    delete[] _tag;
}

template <class ElemType, class WeightType>
bool AdjListGraph<ElemType, WeightType>::IsEmpty()
{
    return _vexTable.GetLength() == 0;
}

template <class ElemType, class WeightType>
int AdjListGraph<ElemType, WeightType>::GetOrder(ElemType vex) const
{
    return _vexTable.LocateElem(vex);
}

template <class ElemType, class WeightType>
ElemType AdjListGraph<ElemType, WeightType>::GetElem(int index) const
{
    return _vexTable.GetElem(index);
}

template <class ElemType, class WeightType>
void AdjListGraph<ElemType, WeightType>::SetElem(int index, ElemType vex)
{
    _vexTable.SetElem(index, vex);
}

template <class ElemType, class WeightType>
WeightType AdjListGraph<ElemType, WeightType>::GetInfinity() const
{
    return _infinity;
}

template <class ElemType, class WeightType>
int AdjListGraph<ElemType, WeightType>::GetVexNum() const
{
    return _vexTable.GetLength();
}

template <class ElemType, class WeightType>
int AdjListGraph<ElemType, WeightType>::GetArcNum() const
{
    return _arcNum;
}

template <class ElemType, class WeightType>
int AdjListGraph<ElemType, WeightType>::FirstAdjVex(int v) const
// 返回顶点v的第一个邻接点
{
    if (_vexTable.GetElem(v)._firstArc == NULL)
    {
        cout << "不存在邻接点!" << endl;
        return -1;
    }
    else
        return _vexTable.GetElem(v)._firstArc->_adjVex; //返回此顶点第一条边的弧头顶点
}

template <class ElemType, class WeightType>
int AdjListGraph<ElemType, WeightType>::NextAdjVex(int v1, int v2) const
// 返回顶点v1的相对于v2的下一个邻接点
{
    if (v1 < 0 || v1 > _vexMaxNum || v2 < 0 || v2 > _vexMaxNum || v1 == v2)
    {
        cout << "v1不合法!" << endl;
        return NULL;
    }
    if (v2 < 0 || v2 > _vexMaxNum || v1 == v2)
    {
        cout << "v2不合法!" << endl;
        return NULL;
    }
    if (v1 == v2)
    {
        cout << "v1不可等于v2!" << endl;
        return NULL;
    }
    ArcNode<WeightType> *p;
    p = _vexTable.GetElem(v1)._firstArc;
    while (p->_adjVex != v2 && p != NULL)
    {
        p = p->_nextArc;
    }

    if (p == NULL || p->_nextArc == NULL) //若没有v2,或v2是v1最后一个邻接点
        return -1;
    else
        return p->_adjVex;
}

template <class ElemType, class WeightType>
void AdjListGraph<ElemType, WeightType>::InsertVex(const ElemType &vexValue)
// 在顶点表的表尾插入元素值为vexValue的顶点。
{
    int _vexNum = GetVexNum();
    if (_vexNum == _vexMaxNum)
        cout << "图的顶点数不能超过允许的最大数!" << endl;

    VexNode<ElemType, WeightType> *p(vexValue);
    _vexTable.InsertElem(p);
    _tag[_vexNum] = 0;
}

template <class ElemType, class WeightType>
void AdjListGraph<ElemType, WeightType>::InsertArc(int v1, int v2, WeightType w)
// 插入：v1到v2,权为w的边
{
    int _vexNum = GetVexNum();
    if (v1 < 0 || v1 >= _vexNum || v2 < 0)
    {
        cout << "v1不合法!" << endl;
        return;
    }
    if (v2 < 0 || v2 >= _vexNum)
    {
        cout << "v2不合法!" << endl;
        return;
    }
    if (v1 == v2)
    {
        cout << "v1不可等于v2!" << endl;
        return;
    }
    if (w == _infinity)
    {
        cout << "权重不可为无限大！" << endl;
        return;
    }

    ArcNode<WeightType> *p;
    p = _vexTable.GetElem(v1)._firstArc;
    _vexTable._data[v1]._firstArc = new ArcNode<WeightType>(v2, w, p);
    _arcNum++;
}

template <class ElemType, class WeightType>
void AdjListGraph<ElemType, WeightType>::DeleteArc(int v1, int v2)
// 删除顶点索引为v1到v2的边
{
    int _vexNum = GetVexNum();
    if (v1 < 0 || v1 >= _vexNum || v2 < 0)
    {
        cout << "v1不合法!" << endl;
        return;
    }
    if (v2 < 0 || v2 >= _vexNum)
    {
        cout << "v2不合法!" << endl;
        return;
    }
    if (v1 == v2)
    {
        cout << "v1不可等于v2!" << endl;
        return;
    }
    ArcNode<WeightType> *p, *q;
    p = _vexTable.GetElem(v1)._firstArc;
    while (p != NULL && p->_adjVex != v2)
    // 找到指定边, 赋值给p, q为p的上一个节点
    {
        q = p;
        p = p->_nextArc;
    }
    if (p != NULL)
    {
        if (_vexTable.GetElem(v1)._firstArc == p)
            // 若指定边恰好是第一条
            _vexTable.GetElem(v1)._firstArc = p->_nextAr;
        else
            //正常情况,将p删除
            q->_nextArc = p->_nextArc;
        delete p;
        _arcNum--;
    }
}

template <class ElemType, class WeightType>
void AdjListGraph<ElemType, WeightType>::DeleteVex(const ElemType &vexValue)
// 删除元素值为vexValue的顶点, 很复杂, 一般不用
{

    ArcNode<WeightType> *p;
    int index = _vexTable.LocateElem(vexValue); //找到指定顶点的索引
    if (index == -1)
        return;

    for (int startIndex = 0; startIndex < GetVexNum(); startIndex++) // 删除到达此顶点的弧
        if (startIndex != index)
            DeleteArc(startIndex, index);

    p = _vexTable.GetElem(index)._firstArc; // 删除从此顶点出发的弧
    while (p != NULL)
    {
        _vexTable.GetElem(index)._firstArc = p->_nextArc;
        delete p;
        p = _vexTable.GetElem(index)._firstArc;
        _arcNum--;
    }

    int _vexNum = GetVexNum() - 1; //记录删点后顶点的个数
    if (index < _vexNum)
    //若待删除点的位置不在最后，将最后的顶点前移
    {
        //顶点集前移
        _vexTable.GetElem(index) = _vexTable.GetElem(_vexNum);
        _vexTable.DeleteElemByIndex(_vexNum); //此时真正的顶点数目已经-1
        _tag[index] = _tag[_vexNum];
    }

    for (int i = 0; i < _vexNum; i++)
        //修改所有指向转移顶点的边结点的_adjVex
        if (i != index)
        {
            p = _vexTable.GetElem(i)._firstArc;
            while (p != NULL)
            {
                if (p->_adjVex == _vexNum)
                    p->_adjVex = i;
                p = p->_nextArc;
            }
        }
}

template <class ElemType, class WeightType>
WeightType AdjListGraph<ElemType, WeightType>::GetWeight(int v1, int v2) const
// 返回顶点索引为v1和v2的边的权值
{
    int _vexNum = GetVexNum();
    if (v1 < 0 || v1 >= _vexNum || v2 < 0)
    {
        cout << "v1不合法!" << endl;
        return;
    }
    if (v2 < 0 || v2 >= _vexNum)
    {
        cout << "v2不合法!" << endl;
        return;
    }

    ArcNode<WeightType> *p = _vexTable.GetElem(v1)._firstArc;
    while (p != NULL && p->_adjVex != v2)
        p = p->_nextArc;
    if (p != NULL)
        return p->_weight;
    else
        return _infinity; //边不存在
}

template <class ElemType, class WeightType>
void AdjListGraph<ElemType, WeightType>::SetWeight(int v1, int v2, WeightType w)
// 设置顶点索引为v1和v2的边的权值
{
    int _vexNum = GetVexNum();
    if (v1 < 0 || v1 >= _vexNum || v2 < 0)
    {
        cout << "v1不合法!" << endl;
        return;
    }
    if (v2 < 0 || v2 >= _vexNum)
    {
        cout << "v2不合法!" << endl;
        return;
    }
    if (v1 == v2)
    {
        cout << "v1不可等于v2!" << endl;
        return;
    }
    if (w == _infinity)
    {
        cout << "权重不可为无限大！" << endl;
        return;
    }
    ArcNode<WeightType> *p = _vexTable.GetElem(v1)._firstArc;
    while (p != NULL && p->_adjVex != v2)
        p = p->_nextArc;
    if (p != NULL)
        p->_weight = w;
}

template <class ElemType, class WeightType>
int AdjListGraph<ElemType, WeightType>::GetTag(int v) const
// 返回顶点索引为v的标志
{
    if (v < 0 || v >= GetVexNum())
        cout << "v不合法!" << endl;
    return _tag[v];
}

template <class ElemType, class WeightType>
void AdjListGraph<ElemType, WeightType>::SetTag(int v, int value)
// 设置顶点v的标志为value
{
    if (v < 0 || v >= GetVexNum())
        cout << "v不合法!" << endl;

    _tag[v] = value;
}

template <class ElemType, class WeightType>
void AdjListGraph<ElemType, WeightType>::Display() const
{
    for (int i = 0; i < GetVexNum(); i++)
    {
        cout << "\t" << _vexTable.GetElem(i)._data;
    }
    ArcNode<WeightType> *p;
    for (int i = 0; i < GetVexNum(); i++)
    {
        cout << endl
             << _vexTable.GetElem(i)._data;

        for (int j = 0; j < GetVexNum(); j++)
        {
            p = _vexTable.GetElem(i)._firstArc;
            if (i == j)
            {
                cout << "\t"
                     << "0";
                continue;
            }
            while (p != NULL)
            {
                if (p->_adjVex == j)
                {
                    cout << "\t" << p->_weight;
                    break;
                }
                p = p->_nextArc;
            }
            if (p == NULL)
                cout << "\t"
                     << "∞";
        }
    }
    cout << endl;
}

#endif