#ifndef TWO_STACK_TO_QUEUE
#define TWO_STACK_TO_QUEUE
#include "../../MyOwnRealization/SeqStack/SeqStack.h"
#include <bits/stdc++.h>
using namespace std;

template <class DataType>
class TwoStackToQueue
{
protected:
    SeqStack<DataType> _stack1;
    SeqStack<DataType> _stack2;

public:
    TwoStackToQueue() {}
    //TwoStackToQueue(const SeqStack<DataType> &s1) : _stack1(s1) {}
    //virtual ~TwoStackToQueue() {}

    bool IsEmpty() const
    {
        return _stack1.IsEmpty();
    }
    void DisplayQueue()
    {
        _stack1.DisplayStack();
    }

    void EnQueue(const DataType e)
    {
        _stack1.PushElem(e);
    }
    void DelQueue()
    {
        DataType e;
        if (_stack1.IsEmpty())
            cout << "队列为空，无法出队！" << endl;
        else
        {
            while (!_stack1.IsEmpty())
            {
                _stack2.PushElem(_stack1.TopElem());
                _stack1.PopElem();
            }
            _stack2.PopElem();
            while (!_stack2.IsEmpty())
            {
                _stack1.PushElem(_stack2.TopElem());
                _stack2.PopElem();
            }
        }
    }
};

#endif