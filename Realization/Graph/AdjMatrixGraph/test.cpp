#include "AdjMatrixGraph.h"
using namespace std;

int main()
{
    //T4,
    cout << "无向图" << endl;
    char es1[6] = {'0', '1', '2', '3', '4', '5'};
    AdjMatrixGraph<char, int> g1(es1, 6, 1, 1);
    g1.InsertArc(0, 1, 45);
    g1.InsertArc(0, 2, 50);
    g1.InsertArc(0, 3, 15);
    g1.InsertArc(1, 2, 5);
    g1.InsertArc(1, 4, 20);
    g1.InsertArc(1, 5, 15);
    g1.InsertArc(3, 0, 10);
    g1.InsertArc(3, 1, 10);
    g1.InsertArc(3, 4, 79);
    g1.InsertArc(4, 1, 30);
    g1.InsertArc(5, 4, 20);

    g1.Display();
    cout << g1.GetArcNum() << endl;
    g1.Dijkstra(0);

    // cout << "测试覆盖邻接矩阵" << endl;
    // int arc[4][4] = {
    //     {0, 1, 0, 0},
    //     {1, 0, 1, 1},
    //     {0, 0, 0, 1},
    //     {0, 0, 1, 0},
    // };
    // AdjMatrixGraph<char, int> g2(es, 4, 10);
    // g2.SetArcs((int **)arc, 4);
    // g2.Display();
    // cout << g2.GetArcNum() << endl;

    //T7,拓扑排序
    char es2[6] = {'0', '1', '2', '3', '4', '5'};
    int arc1[6][6] = {
        {0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0}};
    AdjMatrixGraph<char, int> g2(es2, 6, 1, 0);
    g2.SetArcs((int **)arc1, 6);
    g2.Display();
    // for (int vexNum = 0; vexNum < g2.GetVexNum(); vexNum++)
    //     cout << vexNum << ": " << g2.GetInDegree(vexNum) << endl;

    g2.TopSort();

    //T8,AOE网络

    char es3[7] = {'0', '1', '2', '3', '4', '5', '6'};
    int arc2[7][7] = {
        {0, 8, 0, 4, 5, 0, 0},
        {0, 0, 3, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 6},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 2, 7, 0, 0, 2, 0},
        {0, 0, 3, 0, 0, 0, 9},
        {0, 0, 0, 0, 0, 0, 0}};
    AdjMatrixGraph<char, int> g3(es3, 7, 1, 1);
    g3.SetArcs((int **)arc2, 7);
    g3.Display();

    system("pause");
}
