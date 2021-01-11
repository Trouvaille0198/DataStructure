//DLR
p = r;
Stack s;
while (!s.IsEmpty())
{
    if (p != NUll)
    {
        visit(p);
        s.Push(p);
        p = p->LeftChild;
    }
    else
    {
        p = s.GetTop();
        s.Pop();
        p = p->RightChild;
    }
}
//LDR （左节点为空时访问）即将转到右节点时访问
p = r;
Stack s;
while (!s.IsEmpty())
{
    if (p != NUll)
    {
        s.Push(p);
        p = p->LeftChild;
    }
    if (p == NULL)
    {
        p = s.GetTop();
        s.Pop();
        visit(p);
        p = p->RightChild;
    }
}
//LRD
p = r;
Stack s;
while (!s.IsEmpty())
{
    if (p != NUll)
    {
        s.Push(p);
        p = p->LeftChild;
        flag = 0;
    }
    if (p == NULL && flag == 0)
    {
        p = s.GetTop();
        p = p->RightChild;
        flag = 1;
    }
    if (p == NULL && flag == 1)
    {
        p = s.GetTop();
        s.Pop();
        visit(p);
        flag = 0;
    }
}