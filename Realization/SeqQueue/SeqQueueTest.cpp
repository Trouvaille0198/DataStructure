#include "SeqQueue.h"
using namespace std;

int main()
{
    SeqQueue<int> q1(3);
    q1.EnterQueue(1);
    q1.EnterQueue(2);
    q1.EnterQueue(3);
    SeqQueue<int> q2;
    q2 = q1;
    q2.DisplayQueue();
    system("pause");
}