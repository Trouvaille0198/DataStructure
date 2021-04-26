#include "AdjMatrixGraph.h"
using namespace std;

int main()
{
    //T4 Dijkstra
    cout << endl
         << "T4 Dijkstra" << endl;
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
    cout << "迪杰斯特拉算法" << endl;
    g1.Dijkstra(0);

    //T7,拓扑排序
    cout << endl
         << "T7 拓扑排序" << endl;
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
    cout << "拓扑排序" << endl;
    g2.TopSort();

    //T8,AOE网络
    cout << endl
         << "T8 AOE网络" << endl;
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
    cout << "关键路径" << endl;
    g3.CriticalPath();

    // T10, 破圈法
    cout << endl
         << "T10 破圈法" << endl;
    char es4[6] = {'0', '1', '2', '3', '4', '5'};
    int arc3[6][6] = {
        {0, 6, 3, 5, 0, 0},
        {6, 0, 0, 1, 5, 0},
        {3, 0, 0, 6, 0, 6},
        {5, 1, 6, 0, 5, 4},
        {0, 5, 0, 5, 0, 2},
        {0, 0, 6, 4, 2, 0}};
    AdjMatrixGraph<char, int> g4(es4, 6, 0, 1);
    g4.SetArcs((int **)arc3, 6);
    g4.Display();
    cout << "破圈法" << endl;
    g4.TearCycle();
    system("pause");
}
