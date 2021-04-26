#include "MaxHeap.h"
using namespace std;

int main()
{
    int es[10] = {80, 57, 99, 35, 23, 11, 74, 29, 62, 16};
    MaxHeap<int> h1(es, 10);
    h1.Display();
    int num = h1.GetSize();
    while (!h1.IsEmpty())
    {
        cout << h1.GetTop() << " ";
        h1.DeleteTop();
    }
    system("pause");
}