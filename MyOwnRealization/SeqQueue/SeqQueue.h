#ifndef SEQ_QUEUE
#define SEQ_QUEUE
#include <bits/stdc++.h>
using namespace std;

template <class T>
class SeqQueue
{
protected:
    static const int DEFAULT_SIZE = 100;
    int _front;
    int _rear;
    int _maxlen; //包含被闲置的那一个存储空间，真实供存储的最大值为_maxlen-1
    T *_data;

public:
    SeqQueue(int maxlen = DEFAULT_SIZE);
    virtual ~SeqQueue();
    SeqQueue(const SeqQueue<T> &q);
    SeqQueue<T> &operator=(const SeqQueue<T> &q);

    int GetLength() const;
    bool IsEmpty() const;
    bool IsFull() const;
    void ClearQueue();
    void DisplayQueue() const;

    void EnterQueue(const T &e); //入队
    T GetFront() const;          //取队头
    void DeleteQueue();          //出队
};

template <class T>
SeqQueue<T>::SeqQueue(int maxlen) : _maxlen(maxlen + 1), _rear(0), _front(0)
//构造函数
{
    //if (_data != NULL)
    //    delete[] _data;
    _data = new T[maxlen];
}

template <class T>
SeqQueue<T>::~SeqQueue()
//析构函数，不用修改_maxlen,_rear,_front的值
{
    delete[] _data;
}

template <class T>
SeqQueue<T>::SeqQueue(const SeqQueue<T> &q)
//拷贝构造函数
{

    _front = q._front;
    _rear = q._rear;
    _maxlen = q._maxlen;
    _data = new T[_maxlen];
    for (int i = _front; i != _rear; i = (i + 1) % _maxlen)
    {
        _data[i] = q._data[i];
    }
}

template <class T>
SeqQueue<T> &SeqQueue<T>::operator=(const SeqQueue<T> &q)
//赋值运算符重载
{
    if (&q != this)
    {
        _front = q._front;
        _rear = q._rear;
        _maxlen = q._maxlen;
        if (_data)
            delete[] _data; //相较于拷贝构造函数，多了释放被赋值对象原来的空间这个步骤
        _data = new T[_maxlen];
        for (int i = _front; i != _rear; i = (i + 1) % _maxlen)
        {
            _data[i] = q._data[i];
        }
    }
}

template <class T>
int SeqQueue<T>::GetLength() const
//当 rear > front 时，长度为 rear-front;当 rear < front 时，长度为(QueueSize-front)+rear
{
    return (_rear - _front + _maxlen) % _maxlen;
}

template <class T>
bool SeqQueue<T>::IsEmpty() const
{
    return _rear == _front;
}

template <class T>
bool SeqQueue<T>::IsFull() const

{
    return (_rear + 1) % _maxlen == _front;
}

template <class T>
void SeqQueue<T>::ClearQueue()
//清空队列，不需要清空存储的元素
{
    _rear = _front = 0;
}

template <class T>
void SeqQueue<T>::DisplayQueue() const
{
    if (IsEmpty())
        cout << "队列中无元素！" << endl;
    else
    {
        cout << "从对头到队尾，队列元素依次为：";
        for (int i = _front; i != _rear - 1; i = (i + 1) % _maxlen)
        {
            cout << _data[i] << ", ";
        }
        cout << _data[_rear - 1] << endl;
    }
}

template <class T>
void SeqQueue<T>::EnterQueue(const T &e)
//入队
{
    if (IsFull())
        cout << "队列已满，无法继续添加元素！" << endl;
    else
    {
        _data[_rear] = e;
        _rear = (_rear + 1) % _maxlen;
    }
}

template <class T>
T SeqQueue<T>::GetFront() const
{
    if (IsEmpty())
        cout << "队列为空，队头元素不存在！" << endl;
    else
    {
        return _data[_front];
    }
}

template <class T>
void SeqQueue<T>::DeleteQueue()
//出队
{
    if (IsEmpty())
        cout << "队列为空，无法出队！" << endl;
    else
    {
        _front = (_front + 1) % _maxlen;
    }
}

#endif