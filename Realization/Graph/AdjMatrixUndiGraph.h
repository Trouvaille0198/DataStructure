#ifndef ADJ_MATRIX_UNDI_GRAPH
#define ADJ_MATRIX_UNDI_GRAPH
#include <bits/stdc++.h>
#include "../SeqList/SeqList.h"
using namespace std;

const int DEFAULT_SIZE = 100;

template <class T>
class AdjMatrixUndiGraph
{
protected:
    int _vexNum, _vexMaxNum, _arcNum; //最大顶点数，边数
    int *_tag;                        //标志数组
    SeqList<T> _vertexes;             // 顶点数组
    int **_arcs;                      //邻接矩阵，二维数组
public:
    AdjMatrixUndiGraph(int vexMaxNum = DEFAULT_SIZE);                    //默认构造函数
    AdjMatrixUndiGraph(T *es, int vexNum, int vexMaxNum = DEFAULT_SIZE); //构造函数
    ~AdjMatrixUndiGraph();
    void Clear();
    bool IsEmpty();
    int GetVexNum() const;                          //求顶点个数
    int GetArcNum() const;                          //求边数
    int GetOrder(T vex) const;                      //求顶点序号
    T GetElem(int index) const;                     //求指定下标的顶点值
    void SetElem(int index, T vex);                 //更新指定下标的顶点值
    int FirstAdjVex(int v) const;                   //求v的第一个邻接点的下标
    int NextAdjVex(int v1, int v2) const;           //求v1相对于v2的下一个临界点的下标
    void InsertVex(const T &vex);                   //插入顶点
    void InsertArc(int v1, int v2, int weight = 1); //插入边
    void DeleteVex(const T &vex);                   //删除顶点
    void DeleteArc(int v1, int v2);                 //删除边
    int GetTag(int v) const;                        //求顶点v的标志值
    void SetTag(int v, int value);                  //设置顶点v的标志值
    void Display() const;                           //打印图
};

template <class T>
AdjMatrixUndiGraph<T>::AdjMatrixUndiGraph(int vexMaxNum)
{
    if (vexMaxNum < 0)
    {
        cout << "允许的顶点最大数目不能为负!" << endl; // 抛出异常
        return;
    }
    _arcNum = 0;
    _vexMaxNum = vexMaxNum;

    _vertexes = SeqList<T>(DEFAULT_SIZE);
    _tag = new int[vexMaxNum];
    _arcs = (int **)new int *[vexMaxNum];
    for (int i = 0; i < vexMaxNum; i++)
    //构造邻接矩阵
    {
        _arcs[i] = new int[vexMaxNum];
    }
}

template <class T>
AdjMatrixUndiGraph<T>::AdjMatrixUndiGraph(T *es, int vexNum, int vexMaxNum)
{
    if (vexMaxNum < 0)
    {
        cout << "允许的顶点最大数目不能为负!" << endl; // 抛出异常
        return;
    }
    if (vexMaxNum < vexNum)
    {
        cout << "顶点数目不能大于允许的顶点最大数目!" << endl; // 抛出异常
        return;
    }
    _arcNum = 0;
    _vexMaxNum = vexMaxNum;

    _vertexes = SeqList<T>(es, vexNum, vexMaxNum);
    _tag = new int[vexMaxNum];
    _arcs = (int **)new int *[vexMaxNum];

    for (int i = 0; i < vexMaxNum; i++)
    //构造邻接矩阵
    {
        _arcs[i] = new int[vexMaxNum];
    }
    for (int i = 0; i < vexMaxNum; i++)
    //赋零值
    {
        _tag[i] = 0;
        for (int j = 0; j < vexMaxNum; j++)
        {
            _arcs[i][j] = 0;
        }
    }
}

template <class T>
void AdjMatrixUndiGraph<T>::Clear()
//边数，顶点数清零
{
    _arcNum = 0;
    _vertexes.ClearList();
}
template <class T>
bool AdjMatrixUndiGraph<T>::IsEmpty()
//判断顶点数是否等于零
{
    return _vertexes.GetLength() == 0;
}

template <class T>
AdjMatrixUndiGraph<T>::~AdjMatrixUndiGraph()
{
    //顺序表应该会自己析构掉
    delete[] _tag;
    for (int i = 0; i < _vexMaxNum; i++) // 释放邻接矩阵的行
        delete[] _arcs[i];
    delete[] _arcs; // 释放邻接矩阵
}
template <class T>
int AdjMatrixUndiGraph<T>::GetVexNum() const
{
    return _vertexes.GetLength();
}
template <class T>
int AdjMatrixUndiGraph<T>::GetArcNum() const
{
    return _arcNum;
}
template <class T>
int AdjMatrixUndiGraph<T>::GetOrder(T vex) const
{
    return _vertexes.LocateElem(vex);
}
template <class T>
T AdjMatrixUndiGraph<T>::GetElem(int index) const
{
    return _vertexes.GetElem(index);
}
template <class T>
void AdjMatrixUndiGraph<T>::SetElem(int index, T vex)
{
    _vertexes.SetElem(index, vex);
}
template <class T>
int AdjMatrixUndiGraph<T>::FirstAdjVex(int v) const
{
    if (v < 0 || v > _vexMaxNum)
    {
        cout << "v 不合法!" << endl;
        return NULL;
    }
    int row = v; //顶点在顶点集的位置，即顶点在邻接矩阵中行的位置
    for (int col = 0; col < _vertexes.GetLength(); col++)
    {

        if (_arcs[row][col] != 0)
            return col;
    }
    return -1; //无邻接点
}

template <class T>
int AdjMatrixUndiGraph<T>::NextAdjVex(int v1, int v2) const
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
    int row = v1; //顶点在顶点集的位置，即顶点在邻接矩阵中行的位置
    for (int col = v2 + 1; col < _vertexes.GetLength(); col++)
    //循环从v2的后一个顶点开始
    {

        if (_arcs[row][col] != 0)
            return col;
    }
    return -1; //无邻接点
}
template <class T>
void AdjMatrixUndiGraph<T>::InsertVex(const T &vex)
{
    int _vexNum = _vertexes.GetLength();
    if (_vexNum == _vexMaxNum)
    {
        cout << "图已满，不可再插入顶点!" << endl;
        return;
    }
    _vertexes.InsertElem(vex);
    _tag[_vexNum] = 0;
    for (int i = 0; i < _vexNum + 1; i++)
    {
        _arcs[_vexNum][i] = 0; //新增一行
        _arcs[i][_vexNum] = 0; //新增一列
    }
}
template <class T>
void AdjMatrixUndiGraph<T>::InsertArc(int v1, int v2, int weight)
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
    if (_arcs[v1][v2] == 0)
    {
        _arcs[v1][v2] = weight;
        _arcs[v2][v1] = weight;
        _arcNum++;
    }
}
template <class T>
void AdjMatrixUndiGraph<T>::DeleteVex(const T &vex)
{
    int v = _vertexes.LocateElem(vex); //找到vex在顶点集中的位置
    _vertexes.DeleteElemByValue(vex);
}
template <class T>
void AdjMatrixUndiGraph<T>::DeleteArc(int v1, int v2) {}
template <class T>
int AdjMatrixUndiGraph<T>::GetTag(int v) const {}
template <class T>
void AdjMatrixUndiGraph<T>::SetTag(int v, int value) {}
template <class T>
void AdjMatrixUndiGraph<T>::Display() const {}

#endif