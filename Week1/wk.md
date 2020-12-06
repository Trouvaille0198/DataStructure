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

# Work 7，T7

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

