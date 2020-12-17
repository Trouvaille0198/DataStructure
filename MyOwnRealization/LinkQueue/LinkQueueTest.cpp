#include <bits/stdc++.h>
#include "LinkQueue.h"
using namespace std;

int main()
{
    LinkQueue<int> q1;
    q1.EnterQueue(1);
    q1.EnterQueue(2);
    q1.EnterQueue(3);
    q1.EnterQueue(4);
    q1.EnterQueue(100);
    q1.DeleteQueue();
    LinkQueue<int> q2;
    q2 = q1;
    q2.DisplayQueue();
    system("pause");
}