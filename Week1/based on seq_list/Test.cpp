#include "SeqList.h"
using namespace std;
int main(void)
{
    int a[10] = {2, 4, 6, 8, 10, 12, 14};
    SeqList<int> sa(a, 7);
    sa.Cout();
    sa.GetLength();
    cout << endl;
    sa.DeleteSandT(2, 16);
    sa.GetLength();
    sa.Cout();

    system("pause");
    return 0;
}