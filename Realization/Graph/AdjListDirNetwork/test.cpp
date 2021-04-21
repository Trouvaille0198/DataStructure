#include "AdjListDirNetwork.h"
using namespace std;

int main()
{
    char es[4] = {'a', 'b', 'c', 'd'};
    AdjListDirNetwork<char, int> g1(es, 4);
    g1.InsertArc(0, 2, 4);
    g1.InsertArc(0, 3, 5);
    g1.InsertArc(1, 2, 6);
    g1.InsertArc(1, 3, 7);
    cout << "测试插入" << endl;
    g1.Display();
    cout << g1.GetArcNum() << endl;
    system("pause");
}
