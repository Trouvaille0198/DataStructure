#include "MinHeap.h"
using namespace std;

int main()
{
    int es[10] = {80, 57, 99, 35, 23, 11, 74, 29, 62, 16};
    MinHeap<int> h1(es, 10);
    h1.Display();
    int num = h1.GetSize();
    for (int i = 0; i < num; i++)
    {
        cout << h1.GetTop() << " ";
        h1.DeleteTop();
    }
    system("pause");
}