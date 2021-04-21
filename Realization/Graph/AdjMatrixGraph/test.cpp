#include "AdjMatrixGraph.h"
using namespace std;

int main()
{
    cout << "无向图" << endl;
    char es[5] = {'a', 'b', 'c', 'd', 'e'};
    AdjMatrixGraph<char, int> g1(es, 5, 1, 1);
    g1.InsertArc(0, 1, 10);
    g1.InsertArc(0, 3, 30);
    g1.InsertArc(0, 4, 100);
    g1.InsertArc(1, 2, 50);
    g1.InsertArc(2, 4, 10);
    g1.InsertArc(3, 2, 20);
    g1.InsertArc(3, 4, 60);

    // g1.DeleteVex('b');
    cout << "测试插入" << endl;
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

    // cout << "有向图" << endl;
    // AdjMatrixGraph<char, int> g3(es, 4, 10, 1, 1);
    // g3.InsertArc(0, 2, 6);
    // g3.InsertArc(0, 3, 9);
    // g3.InsertArc(1, 2, 12);
    // g3.InsertArc(3, 1, 8);
    // // g3.DeleteVex('b');
    // cout << "测试插入" << endl;
    // g3.Display();
    // cout << g3.GetArcNum() << endl;

    system("pause");
}
