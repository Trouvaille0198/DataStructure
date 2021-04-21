#ifndef ADJ_MATRIX_UNDI_GRAPH
#define ADJ_MATRIX_UNDI_GRAPH
#include <bits/stdc++.h>
#include "../../SeqList/SeqList.h"
using namespace std;

const int DEFAULT_SIZE = 100;
//无向图的邻接矩阵类
template <class T>
class AdjMatrixUndiGraph
{
protected:
    int _vexMaxNum, _arcNum; //最大顶点数，边数
    int *_tag;               //标志数组
    SeqList<T> _vertexes;    // 顶点数组
    int **_arcs;             //邻接矩阵，二维数组
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
    int NextAdjVex(int v1, int v2) const;           //求v1相对于v2的下一个邻接点的下标
    void InsertVex(const T &vex);                   //插入顶点
    void InsertArc(int v1, int v2, int weight = 1); //插入边
    void DeleteVex(const T &vex);                   //删除顶点
    void DeleteArc(int v1, int v2);                 //删除边
    int GetTag(int v) const;                        //求顶点v的标志值
    void SetTag(int v, int value);                  //设置顶点v的标志值
    void Display() const;                           //打印图
    void SetArcs(int **arcs, int vexNum);           //设置新的邻接矩阵
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

    _vertexes = SeqList<T>(vexMaxNum);
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
    int i = _vertexes.LocateElem(vex); //找到vex在顶点集中的位置

    //删除关联边
    for (int j = 0; j < _vertexes.GetLength(); j++)
    {
        if (_arcs[i][j] != 0)
        {
            _arcNum--;
            _arcs[i][j] = 0;
            _arcs[j][i] = 0;
        }
    }
    int _vexNum = _vertexes.GetLength() - 1; //记录删点后顶点的个数
    if (i < _vexNum)
    //若待删除点的位置不在最后，将最后的顶点前移
    {
        //顶点集前移
        _vertexes.GetElem(i) = _vertexes.GetElem(_vexNum);
        _vertexes.DeleteElemByIndex(_vexNum);
        //标志集前移
        _tag[i] = _tag[_vexNum];
        //邻接矩阵前移
        for (int col = 0; col <= _vexNum; col++)
            _arcs[i][col] = _arcs[_vexNum][col]; //删行
        for (int row = 0; row <= _vexNum; row++)
            _arcs[row][i] = _arcs[row][_vexNum]; //删列
    }
}
template <class T>
void AdjMatrixUndiGraph<T>::DeleteArc(int v1, int v2)
{
    if (v1 < 0 || v1 > _vexMaxNum || v2 < 0 || v2 > _vexMaxNum || v1 == v2)
    {
        cout << "v1不合法!" << endl;
        return;
    }
    if (v2 < 0 || v2 > _vexMaxNum || v1 == v2)
    {
        cout << "v2不合法!" << endl;
        return;
    }
    if (v1 == v2)
    {
        cout << "v1不可等于v2!" << endl;
        return;
    }
    if (_arcs[v1][v2] != 0)
    {
        _arcNum--;
        _arcs[v1][v2] = 0;
        _arcs[v2][v1] = 0;
    }
}
template <class T>
int AdjMatrixUndiGraph<T>::GetTag(int v) const
{
    if (v < 0 || v > _vexMaxNum)
    {
        cout << "v 不合法!" << endl;
        return NULL;
    }
    return _tag[v];
}
template <class T>
void AdjMatrixUndiGraph<T>::SetTag(int v, int value)
{
    if (v < 0 || v > _vexMaxNum)
    {
        cout << "v 不合法!" << endl;
        return;
    }
    _tag[v] = value;
}

template <class T>
void AdjMatrixUndiGraph<T>::Display() const
{
    for (int i = 0; i < _vertexes.GetLength(); i++)
    {
        cout << "\t" << _vertexes.GetElem(i);
    }
    cout << endl;

    for (int row = 0; row < _vertexes.GetLength(); row++)
    {
        cout << _vertexes.GetElem(row);
        for (int col = 0; col < _vertexes.GetLength(); col++)
        {
            if (_arcs[row][col] == 0)
                cout << "\t"
                     << "0";
            else
                cout << "\t" << _arcs[row][col];
        }
        cout << endl;
    }
}

template <class T>
void AdjMatrixUndiGraph<T>::SetArcs(int **arcs, int vexNum)
{
    if (vexNum != _vertexes.GetLength())
    {
        cout << "新的邻接矩阵的个数与原图不匹配!" << endl;
        return;
    }
    int arcNum = 0;
    for (int row = 0; row < vexNum; row++)
    {
        for (int col = 0; col < vexNum; col++)
        {
            if (*((int *)arcs + row * vexNum + col) != 0)
                arcNum++;
            _arcs[row][col] = *((int *)arcs + row * vexNum + col);
        }
    }
    _arcNum = arcNum / 2;
}

#endif