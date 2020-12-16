#include "TwoStackToQueue.h"
using namespace std;

int main()
{
    TwoStackToQueue<int> q1;
    q1.EnQueue(1);
    q1.EnQueue(2);
    q1.EnQueue(3);
    q1.EnQueue(4);
    q1.DisplayQueue();

    system("pause");
}