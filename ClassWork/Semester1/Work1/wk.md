# Work1，T1.(3)

```c++
template <class ElemType>
void SeqList<ElemType>::DeleteSameElem()
{
    ElemType a, b;
    for (int i = 1; i <= length; i++)
    {
        GetElem(i, a);
        for (int j = i + 1; j <= length; (a == b) ?: j++)
        {
            GetElem(j, b);
            if (a == b)
                DeleteElem(j, a);
        }
    }
}
```

# Work2，T3

## 顺序表实现

```c++
template <class ElemType>
void SeqList<ElemType>::Reverse()
{
    ElemType e;
    for (int i = 0; i < length / 2; i++)
    {
        e = elems[i];
        elems[i] = elems[length - i - 1];
        elems[length - i - 1] = e;
    }
}
```

## 链表实现

```c++
template <class ElemType>
void LinkList<ElemType>::Reverse()
{
	Node<ElemType> *p = head->next, *q;
	for (head->next = NULL; p != NULL; p = q) //每次循环结束，p指向下一个节点
	{
		q = p->next;		  //q始终为p的后一位
		p->next = head->next; //指针域倒置，保证当前节点指向前一个节点
		head->next = p;		  //head指向当前节点
	}
}
```

# Work3，T7

```c++
int Polynomial::Calc(int x)
{
	int result = 0;
	PolyItem e;
	for (int i = 1; i <= polyList.GetLength(); i++)
	{
		polyList.GetElem(i, e);
		result += pow(x, e.expn) * e.coef;
	}
	return result;
}
```

# Work4，T2(4)

```c++
template <class ElemType>
void SeqList<ElemType>::DeleteSandT(ElemType s, ElemType t)
{
    if (s >= t || length == 0)
        cout << "Error!";
    else
    {
        int i = 0;
        while (i < length && elems[i] <= s)
            i++;
        int j = i + 1;
        while (j < length && elems[j] < t)
            j++;
        while (j < length)
        {
            elems[i] = elems[j];
			i++;
			j++;
        }
        length = length + i - j;
    }
}
```

# Work5，T10
```C++
friend LinkList<ElemType> Merge(const LinkList<ElemType> &la, const LinkList<ElemType> &lb)
	{
		Node<ElemType> *a, *b, *newHead;
		Node<ElemType> *q = NULL;
		a = la.head;
		b = lb.head;
		while (a != NULL && b != NULL)
		{
			if (a->data <= b->data)
			{
				newHead = a;
				a = a->next;
			}
			else
			{
				newHead = b;
				b = b->next;
			}
			newHead->next = q;
			q = newHead;
		}
		Node<ElemType> *last;
		last = (a != NULL) ? a : b;
		while (last != NULL)
		{
			newHead = last;
			last = last->next;
			newHead->next = q;
			q = newHead;
		}
		LinkList<ElemType> Result(newHead, la.length + lb.length);
		return Result;
	}
```