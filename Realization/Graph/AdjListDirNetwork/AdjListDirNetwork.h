#ifndef __ADJ_LIST_GRAPH_H__
#define __ADJ_LIST_GRAPH_H__

#include "AdjListNetworkArc.h"     // 网络邻接表的边结点类
#include "AdjListNetworkVex.h"     // 网络邻接表的顶点结点类
#include "../../SeqList/SeqList.h" //顺序表
using namespace std;
const int DEFAULT_SIZE = 100;
const int DEFAULT_INFINITY = 100;

// 有向网的邻接表类
template <class ElemType, class WeightType>
class AdjListDirNetwork
{
protected:
    //注意，顶点数包含在顺序表的数据成员中
    int _vexMaxNum, _arcNum;                                    //最大顶点数，边数
    SeqList<AdjListNetworkVex<ElemType, WeightType>> _vexTable; //顶点表
    int *_tag;                                                  //标志数组
    WeightType _infinity;

public:
    AdjListDirNetwork(int vexMaxNum = DEFAULT_SIZE,
                      WeightType infinity = (WeightType)DEFAULT_INFINITY);
    AdjListDirNetwork(ElemType *vex, int vexNum, int vexMaxNum = DEFAULT_SIZE,
                      WeightType infinity = (WeightType)DEFAULT_INFINITY);
    ~AdjListDirNetwork();
    void Clear();
    bool IsEmpty();
    int GetOrder(ElemType vex) const;               //求顶点序号
    ElemType GetElem(int index) const;              //求指定下标的顶点值
    void SetElem(int index, ElemType vex);          //更新指定下标的顶点值
    WeightType GetInfinity() const;                 // 取无穷大的值
    int GetVexNum() const;                          // 求顶点个数
    int GetArcNum() const;                          // 求边数
    int FirstAdjVex(int v) const;                   //求v的第一个邻接点的下标
    int NextAdjVex(int v1, int v2) const;           //求v1相对于v2的下一个邻接点的下标
    void InsertVex(const ElemType &vex);            //插入顶点
    void InsertArc(int v1, int v2, int weight = 1); //插入边
    void DeleteVex(const ElemType &vex);            //删除顶点
    void DeleteArc(int v1, int v2);                 //删除边
    WeightType GetWeight(int v1, int v2) const;     // 求从顶点为v1到v2的边的权值
    void SetWeight(int v1, int v2, WeightType w);   // 设置从顶点为v1到v2的边的权值
    int GetTag(int v) const;                        //求顶点v的标志值
    void SetTag(int v, int value);                  //设置顶点v的标志值
    void Display() const;                           //打印图
};

template <class ElemType, class WeightType>
AdjListDirNetwork<ElemType, WeightType>::AdjListDirNetwork(int vexMaxNum, WeightType infinity)
// 操作结果：构造顶点最大数目为vexMaxNum,infinity表示无穷大的空有向网
{

    _vexMaxNum = vexMaxNum;
    _infinity = infinity;
    _arcNum = 0;

    _tag = new int[_vexMaxNum];
    _vexTable = SeqList<AdjListNetworkVex<ElemType, WeightType>>(_vexMaxNum);
}

template <class ElemType, class WeightType>
AdjListDirNetwork<ElemType, WeightType>::AdjListDirNetwork(ElemType *vex, int vexNum,
                                                           int vexMaxNum, WeightType infinity)
{
    _vexMaxNum = vexMaxNum;
    _infinity = infinity;
    _arcNum = 0;

    _tag = new int[_vexMaxNum];
    _vexTable = SeqList<AdjListNetworkVex<ElemType, WeightType>>(vex, vexNum, _vexMaxNum);
    for (int i = 0; i < vexMaxNum; i++)
    {
        _tag[i] = 0;
    }
}

template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::Clear()
// 释放所有边，并把顶点数和边数设为零
{
    AdjListNetworkArc<WeightType> *p;
    for (int i = 0; i < _vexTable.GetLength(); i++)
    { // 释放边节点
        p = _vexTable.GetElem(i)._firstArc;
        while (p != NULL)
        // 遍历并删除节点
        {
            _vexTable[i]._firstArc = p->_nextArc;
            delete p;
            p = vexTable[i]._firstArc;
        }
    }
    _vexTable.ClearList(); //顶点数置零
    _arcNum = 0;
}

template <class ElemType, class WeightType>
AdjListDirNetwork<ElemType, WeightType>::~AdjListDirNetwork()
{
    Clear();
    delete[] _tag;
}

template <class ElemType, class WeightType>
bool AdjListDirNetwork<ElemType, WeightType>::IsEmpty()
{
    return _vexTable.GetLength() == 0;
}

template <class ElemType, class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::GetOrder(ElemType vex) const
{
    return _vexTable.LocateElem(vex);
}

template <class ElemType, class WeightType>
ElemType AdjListDirNetwork<ElemType, WeightType>::GetElem(int index) const
{
    return _vexTable.GetElem(index);
}

template <class ElemType, class WeightType>
void AdjListDirNetwork<ElemType, WeightType>::SetElem(int index, ElemType vex)
{
    _vexTable.SetElem(index, vex);
}

template <class ElemType, class WeightType>
WeightType AdjListDirNetwork<ElemType, WeightType>::GetInfinity() const
{
    return _infinity;
}

template <class ElemType, class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::GetVexNum() const
{
    return _vexTable.GetLength();
}

template <class ElemType, class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::GetArcNum() const
{
    return _arcNum;
}

template <class ElemType, class WeightType>
int AdjListDirNetwork<ElemType, WeightType>::FirstAdjVex(int v) const
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
int AdjListDirNetwork<ElemType, WeightType>::NextAdjVex(int v1, int v2) const
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
    AdjListNetworkArc<WeightType> *p;
    p = _vexTable.GetElem(v1)->_firstArc;
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
void AdjListDirNetwork<ElemType, WeightType>::InsertVex(const ElemType &d)
// 操作结果：在顶点表的表尾插入元素值为d的顶点。
{
}

#endif