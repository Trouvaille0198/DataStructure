#include "SeqList.h"
using namespace std;
int main(void)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    SeqList<int> sa(a, 9);
    sa.Traverse(Write<int>);
    cout << endl;
    sa.DeleteSandT(4, 6);
    sa.Traverse(Write<int>);

    system("pause");
    return 0;
}