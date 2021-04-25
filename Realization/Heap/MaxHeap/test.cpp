#include "MaxHeap.h"
using namespace std;

int main()
{
    int es[10] = {80, 57, 99, 35, 23, 11, 74, 29, 62, 16};
    MaxMap<int> h1(es, 10);
    h1.Display();
    system("pause");
}