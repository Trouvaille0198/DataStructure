#ifndef ADJ_MATRIX_GRAPH
#define ADJ_MATRIX_GRAPH
#include <bits/stdc++.h>
#include "../../SeqList/SeqList.h"
#include "../../SeqStack/SeqStack.h"
#include "../../SeqQueue/SeqQueue.h"
using namespace std;

const int DEFAULT_SIZE = 100;
const int DEFAULT_INFINITY = 1000;
//图的邻接矩阵类
template <class ElemType, class WeightType>
class AdjMatrixGraph
{
protected:
    int _vexMaxNum, _arcNum;     // 最大顶点数, 边数
    int *_tag;                   // 标志数组
    SeqList<ElemType> _vertexes; // 顶点数组
    int **_arcs;                 // 邻接矩阵, 二维数组
    int _dirType;                // 有向图或无向图
    int _weightType;             // 带权值或不带权值
    WeightType _infinity;

public:
    AdjMatrixGraph(int dirType = 0, int weightType = 0,
                   int vexMaxNum = DEFAULT_SIZE, WeightType infinity = DEFAULT_INFINITY); //默认构造函数
    AdjMatrixGraph(ElemType *es, int vexNum,
                   int dirType = 0, int weightType = 0,
                   int vexMaxNum = DEFAULT_SIZE, WeightType infinity = DEFAULT_INFINITY); //构造函数
    ~AdjMatrixGraph();
    void Clear();
    bool IsEmpty();
    int GetVexNum() const;                          // 求顶点个数
    int GetArcNum() const;                          // 求边数
    int GetOrder(ElemType vex) const;               // 求顶点序号
    ElemType GetElem(int index) const;              // 求指定下标的顶点值
    void SetElem(int index, ElemType vex);          // 更新指定下标的顶点值
    int GetFirstAdjVex(int v) const;                // 求v的第一个邻接点的下标
    int GetNextAdjVex(int v1, int v2) const;        // 求v1相对于v2的下一个邻接点的下标
    void InsertVex(const ElemType &vex);            // 插入顶点
    void InsertArc(int v1, int v2, int weight = 1); // 插入边
    void DeleteVex(const ElemType &vex);            // 删除顶点
    void DeleteArc(int v1, int v2);                 // 删除边
    WeightType GetWeight(int v1, int v2) const;     // 求从顶点为v1到v2的边的权值
    void SetWeight(int v1, int v2, WeightType w);   // 设置从顶点为v1到v2的边的权值
    int GetTag(int v) const;                        // 求顶点v的标志值
    void SetTag(int v, int value);                  // 设置顶点v的标志值
    void Display() const;                           // 打印图
    void SetArcs(int **arcs, int vexNum);           // 设置新的邻接矩阵
    void Dijkstra(int v);                           // 迪杰斯特拉算法
    int GetInDegree(int v) const;                   // 求v的入度
    void TopSort() const;                           // 有向无权图的拓扑排序
    void CriticalPath() const;                      // AOE网络的开始时间、关键路径
    //bool IsConnected() const;                       //判断图是否连通
    void DFS(int v); //深度优先搜索
};

template <class ElemType, class WeightType>
AdjMatrixGraph<ElemType, WeightType>::AdjMatrixGraph(int dirType, int weightType, int vexMaxNum, WeightType infinity)
{
    if (vexMaxNum < 0)
    {
        cout << "允许的顶点最大数目不能为负!" << endl;
        return;
    }
    _dirType = dirType;
    _weightType = weightType;
    _arcNum = 0;
    _vexMaxNum = vexMaxNum;
    _infinity = infinity;

    _vertexes = SeqList<ElemType>(vexMaxNum);
    _tag = new int[vexMaxNum];
    _arcs = (int **)new int *[vexMaxNum];
    for (int i = 0; i < vexMaxNum; i++)
    //构造邻接矩阵
    {
        _arcs[i] = new int[vexMaxNum];
    }
}

template <class ElemType, class WeightType>
AdjMatrixGraph<ElemType, WeightType>::AdjMatrixGraph(ElemType *es, int vexNum,
                                                     int dirType, int weightType,
                                                     int vexMaxNum, WeightType infinity)
{
    if (vexMaxNum < 0)
    {
        cout << "允许的顶点最大数目不能为负!" << endl;
        return;
    }
    if (vexMaxNum < vexNum)
    {
        cout << "顶点数目不能大于允许的顶点最大数目!" << endl;
        return;
    }
    _arcNum = 0;
    _vexMaxNum = vexMaxNum;
    _dirType = dirType;
    _weightType = weightType;
    _infinity = infinity;

    _vertexes = SeqList<ElemType>(es, vexNum, vexMaxNum);
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
            _arcs[i][j] = _infinity;
        }
    }
}

template <class ElemType, class WeightType>
void AdjMatrixGraph<ElemType, WeightType>::Clear()
//边数，顶点数清零
{
    _arcNum = 0;
    _vertexes.ClearList();
}
template <class ElemType, class WeightType>
bool AdjMatrixGraph<ElemType, WeightType>::IsEmpty()
//判断顶点数是否等于零
{
    return _vertexes.GetLength() == 0;
}

template <class ElemType, class WeightType>
AdjMatrixGraph<ElemType, WeightType>::~AdjMatrixGraph()
{
    //顺序表应该会自己析构掉
    delete[] _tag;
    for (int i = 0; i < _vexMaxNum; i++) // 释放邻接矩阵的行
        delete[] _arcs[i];
    delete[] _arcs; // 释放邻接矩阵
}
template <class ElemType, class WeightType>
int AdjMatrixGraph<ElemType, WeightType>::GetVexNum() const
{
    return _vertexes.GetLength();
}
template <class ElemType, class WeightType>
int AdjMatrixGraph<ElemType, WeightType>::GetArcNum() const
{
    return _arcNum;
}
template <class ElemType, class WeightType>
int AdjMatrixGraph<ElemType, WeightType>::GetOrder(ElemType vex) const
{
    return _vertexes.LocateElem(vex);
}
template <class ElemType, class WeightType>
ElemType AdjMatrixGraph<ElemType, WeightType>::GetElem(int index) const
{
    return _vertexes.GetElem(index);
}
template <class ElemType, class WeightType>
void AdjMatrixGraph<ElemType, WeightType>::SetElem(int index, ElemType vex)
{
    _vertexes.SetElem(index, vex);
}
template <class ElemType, class WeightType>
int AdjMatrixGraph<ElemType, WeightType>::GetFirstAdjVex(int v) const
{
    if (v < 0 || v > _vexMaxNum)
    {
        cout << "v 不合法!" << endl;
        return NULL;
    }
    int row = v; //顶点在顶点集的位置，即顶点在邻接矩阵中行的位置
    for (int col = 0; col < _vertexes.GetLength(); col++)
    {

        if (_arcs[row][col] != _infinity)
            return col;
    }
    return -1; //无邻接点
}

template <class ElemType, class WeightType>
int AdjMatrixGraph<ElemType, WeightType>::GetNextAdjVex(int v1, int v2) const
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

        if (_arcs[row][col] != _infinity)
            return col;
    }
    return -1; //无邻接点
}
template <class ElemType, class WeightType>
void AdjMatrixGraph<ElemType, WeightType>::InsertVex(const ElemType &vex)
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
        _arcs[_vexNum][i] = _infinity; //新增一行
        _arcs[i][_vexNum] = _infinity; //新增一列
    }
}
template <class ElemType, class WeightType>
void AdjMatrixGraph<ElemType, WeightType>::InsertArc(int v1, int v2, int weight)
{
    if (_weightType == 0)
        // 若为无权图, 插入的权值强制为 1
        weight = 1;
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

    if (_arcs[v1][v2] == _infinity)
    {
        _arcs[v1][v2] = weight;
        if (_dirType == 0)
            // 若为无向图, 对称处也设边
            _arcs[v2][v1] = weight;
        _arcNum++;
    }
}
template <class ElemType, class WeightType>
void AdjMatrixGraph<ElemType, WeightType>::DeleteVex(const ElemType &vex)
{
    int i = _vertexes.LocateElem(vex); //找到vex在顶点集中的位置
    if (i == -1)
    {
        cout << "找不到要删除的点!" << endl;
        return;
    }
    //删除关联边
    for (int j = 0; j < _vertexes.GetLength(); j++)
    {
        if (_arcs[i][j] != _infinity)
        {
            _arcNum--;
            _arcs[i][j] = _infinity;
            if (_dirType == 0)
                // 若为无向图, 对称处也删边
                _arcs[j][i] = _infinity;
        }
    }
    int _vexNum = _vertexes.GetLength() - 1; //记录删点后顶点的个数
    if (i < _vexNum)
    //若待删除点的位置不在最后，将最后的顶点前移
    {
        //顶点集前移
        _vertexes.SetElem(i, _vertexes.GetElem(_vexNum));
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
template <class ElemType, class WeightType>
void AdjMatrixGraph<ElemType, WeightType>::DeleteArc(int v1, int v2)
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
    if (_arcs[v1][v2] != _infinity)
    {
        _arcNum--;
        _arcs[v1][v2] = _infinity;
        if (_dirType == 0)
            // 若为无向图, 对称处也删边
            _arcs[v2][v1] = _infinity;
    }
}
template <class ElemType, class WeightType>
int AdjMatrixGraph<ElemType, WeightType>::GetTag(int v) const
{
    if (v < 0 || v > _vexMaxNum)
    {
        cout << "v 不合法!" << endl;
        return NULL;
    }
    return _tag[v];
}
template <class ElemType, class WeightType>
void AdjMatrixGraph<ElemType, WeightType>::SetTag(int v, int value)
{
    if (v < 0 || v > _vexMaxNum)
    {
        cout << "v 不合法!" << endl;
        return;
    }
    _tag[v] = value;
}

template <class ElemType, class WeightType>
void AdjMatrixGraph<ElemType, WeightType>::Display() const
{
    string ref = "0";
    if (_dirType == 1)
        ref = "∞";
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
            if (col == row)
                cout << "\t"
                     << "0";
            else if (_arcs[row][col] == _infinity)
                cout << "\t"
                     << ref;
            else
                cout << "\t" << _arcs[row][col];
        }
        cout << endl;
    }
}

template <class ElemType, class WeightType>
void AdjMatrixGraph<ElemType, WeightType>::SetArcs(int **arcs, int vexNum)
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
            if (*((int *)arcs + row * vexNum + col) == 0)
                _arcs[row][col] = _infinity;
            else
            {
                arcNum++;
                _arcs[row][col] = *((int *)arcs + row * vexNum + col);
            }
        }
    }
    _arcNum = arcNum / 2;
}

template <class ElemType, class WeightType>
WeightType AdjMatrixGraph<ElemType, WeightType>::GetWeight(int v1, int v2) const
{
    return _arcs[v1][v2];
}

template <class ElemType, class WeightType>
void AdjMatrixGraph<ElemType, WeightType>::SetWeight(int v1, int v2, WeightType w)
{

    _arcs[v1][v2] = w;
    if (_dirType == 0)
        _arcs[v2][v1] = w;
}

template <class ElemType, class WeightType>
void AdjMatrixGraph<ElemType, WeightType>::Dijkstra(int v)
// 求索引为v的顶点的各个最短路径长度
{
    int _vexNum = _vertexes.GetLength();
    WeightType min;
    WeightType dist[_vexNum]; // 存储当前找到的最短路径长度
    int path[_vexNum];        // 存储目标顶点的直接前驱节点

    for (int i = 0; i < _vexNum; i++)
    {
        dist[i] = _arcs[v][i]; // 存入一条边的路径
        SetTag(i, 0);          // 用_tag表示已经找到最短路径的集合
        if (i != v && dist[i] < _infinity)
            // 若dist[i]存在, 添加前驱节点
            path[i] = v;
        else
            path[i] = -1;
    }
    SetTag(v, 1); //自身已经在集合中

    cout << "所选源点: " << GetElem(v) << endl;

    int finalVex; // 已求出最短路径的顶点
    int w;
    for (int i = 1; i < _vexNum; i++)
    // 按递增序列求最短路径
    {
        min = _infinity;
        finalVex = v;
        for (int j = 0; j < _vexNum; j++)
        // 查询最小的最短路径, 找出finalVex
        {
            if (_tag[j] == 0 && dist[j] < min)
            {
                finalVex = j;
                min = dist[j];
            }
        }
        SetTag(finalVex, 1);
        for (int j = GetFirstAdjVex(finalVex); j != -1; j = GetNextAdjVex(finalVex, j))
        // 从上一次找到的最短路径的顶点出发, 依次判断各顶点的最短路径能否更新
        {
            if (_tag[j] == 0 && min + GetWeight(finalVex, j) < dist[j])
            {
                dist[j] = min + GetWeight(finalVex, j);
                path[j] = finalVex;
            }
        }
    }
    // 打印输出
    for (int i = 0; i < _vexNum; i++)
    {
        if (i == v)
            continue;
        string pathStr(1, GetElem(i));

        for (int j = path[i]; j != -1; j = path[j])
        {
            pathStr = string(1, GetElem(j)) + " -> " + pathStr;
        }
        cout << "从顶点 " << GetElem(v) << " 到顶点 " << GetElem(i) << " 的最短路径为: " << pathStr
             << ", 长度为: " << dist[i] << endl;
    }
}

template <class ElemType, class WeightType>
int AdjMatrixGraph<ElemType, WeightType>::GetInDegree(int v) const
//固定列,遍历行, 行中非零,则入度+1
{
    if (_dirType != 1)
        return 0;
    int InDegree = 0;
    for (int row = 0; row < GetVexNum(); row++)
    {
        if (_arcs[row][v] != _infinity)
            InDegree++;
    }
    return InDegree;
}

template <class ElemType, class WeightType>
void AdjMatrixGraph<ElemType, WeightType>::TopSort() const
{
    int *InDegree = new int[GetVexNum()]; //入度数组
    SeqStack<int> s;                      //存放入度为零的顶点索引栈
    for (int i = 0; i < GetVexNum(); i++)
    {
        InDegree[i] = GetInDegree(i);
        if (GetInDegree(i) == 0)
            s.PushElem(i); //将入度为0的顶点索引入栈
    }
    int v, count = 0;
    while (!s.IsEmpty())
    {
        v = s.TopElem();
        s.PopElem();
        cout << GetElem(v) << " ";
        count++;
        for (int u = GetFirstAdjVex(v); u != -1; u = GetNextAdjVex(v, u))
        //找到零入度顶点指向的顶点,将他们入度 -1,若 -1后入度为 0,将他们入栈
        {
            if (--InDegree[u] == 0)
                s.PushElem(u);
        }
    }
    cout << endl;
    delete[] InDegree;
    if (count < GetVexNum())
        cout << "图有回路,无法进行拓扑排序!" << endl;
}

template <class ElemType, class WeightType>
void AdjMatrixGraph<ElemType, WeightType>::CriticalPath() const
{
    int *InDegree = new int[GetVexNum()];  //入度数组
    WeightType *ve = new int[GetVexNum()]; //事件的最早开始时间
    WeightType *vl = new int[GetVexNum()]; //事件的最晚开始时间

    SeqQueue<int> q;             //入度为零的顶点队列,用来求 ve
    SeqStack<int> s;             //用于实现逆拓扑序列的栈,用来求 vl
    int ee, el, u, v, count = 0; //活动的开始时间不单独开辟数组
    ElemType e1, e2;
    for (int i = 0; i < GetVexNum(); i++)
        //初始化最早开始时间数组
        ve[i] = 0;
    for (int i = 0; i < GetVexNum(); i++)
    //统计顶点入度,并将入度为0的顶点索引入队
    {
        InDegree[i] = GetInDegree(i);
        if (GetInDegree(i) == 0)
            q.EnterQueue(i);
    }
    while (!q.IsEmpty())
    //计算事件最早开始时间
    {
        v = q.GetFront();
        q.DeleteQueue();
        s.PushElem(v); //v入栈,之后出栈即可得到逆拓扑序列
        count++;
        for (u = GetFirstAdjVex(v); u != -1; u = GetNextAdjVex(v, u))
        // 刷新最早开始时间
        {
            if (--InDegree[u] == 0)
                //找到顶点v指向的顶点u,将他们入度 -1,若 -1后入度为 0,将他们入队
                q.EnterQueue(u);
            if (ve[v] + GetWeight(v, u) > ve[u])
                //取弧尾 v的 ve加边权值的最大值,赋值给 u的 ve
                ve[u] = ve[v] + GetWeight(v, u);
        }
    }

    if (count < GetVexNum())
    {
        delete[] InDegree;
        delete[] ve;
        delete[] vl;
        cout << "图有回路,不是 AOE 网络!" << endl;
    }
    v = s.TopElem(); //取栈顶,栈顶为汇点
    s.PopElem();
    for (int i = 0; i < GetVexNum(); i++)
        // 初始化最迟开始时间
        vl[i] = ve[v];
    while (!s.IsEmpty())
    // 计算事件最迟开始时间
    {
        v = s.TopElem();
        s.PopElem();
        for (u = GetFirstAdjVex(v); u != -1; u = GetNextAdjVex(v, u))
            // 刷新最迟开始时间
            if (vl[u] - GetWeight(v, u) < vl[v])
                //取弧头 u的 vl减边权值的最小值,赋值给 v的 vl
                vl[v] = vl[u] - GetWeight(v, u);
    }
    for (u = 0; u < GetVexNum(); u++)
    // 求关键路径
    {
        for (v = GetFirstAdjVex(u); v != -1; v = GetNextAdjVex(u, v))
        {
            ee = ve[u];                   //ee为弧尾的vl
            el = vl[v] - GetWeight(u, v); //el为弧头的vl减权值
            if (ee == el)
            // 输出关键活动
            {
                e1 = GetElem(u);
                e2 = GetElem(v);
                cout << "<" << e1 << ", " << e2 << "> ";
            }
        }
    }
    cout << endl;
    delete[] InDegree;
    delete[] ve;
    delete[] vl;
}

template <class ElemType, class WeightType>
void AdjMatrixGraph<ElemType, WeightType>::DFS(int v)
{
    SetTag(v, 1);
    cout << GetElem(v) << " ";
    for (int u = GetFirstAdjVex(v); u != -1; u = GetNextAdjVex(v, u))
    {
        if (_tag[u] == 0)
            DFS(u);
        else
            break;
    }
}
#endif