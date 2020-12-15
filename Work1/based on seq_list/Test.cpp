#include "SeqList.h"
using namespace std;
int main(void)
{
    int a[10] = {2, 4, 6, 8, 10, 12, 14};
    SeqList<int> sa(a, 7);
    cout << "原顺序表：";
    sa.Cout();
    cout << endl;
    sa.DeleteSandT(5, 8);
    cout << "删除后的顺序表：";
    sa.Cout();

    system("pause");
    return 0;
}