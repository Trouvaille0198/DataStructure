#include "AdjMatrixUndiGraph.h"
using namespace std;

int main()
{
    char es[4] = {'a', 'b', 'c', 'd'};
    AdjMatrixUndiGraph<char> g1(es, 4, 10);
    g1.InsertArc(0, 2);
    g1.InsertArc(0, 3);
    g1.InsertArc(1, 2);
    g1.InsertArc(1, 3);
    cout << "测试插入" << endl;
    g1.Display();
    cout << g1.GetArcNum() << endl;

    cout << "测试覆盖邻接矩阵" << endl;
    int arc[4][4] = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 1},
    };
    g1.SetArcs((int **)arc, 4);
    g1.Display();
    cout << g1.GetArcNum() << endl;
    system("pause");
}
