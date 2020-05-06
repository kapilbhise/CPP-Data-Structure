#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        RDisplay(p->next);
        printf("%d ", p->data);
    }
}

int Count(Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int RCount(Node *p)
{
    int l = 0;
    if (p)
        return RCount(p->next) + 1;
    else
        return 0;
}

int Sum(Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int RSum(Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return RSum(p->next) + p->data;
    }
}

int Max(Node *p)
{
    int max = INT32_MIN;
    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int RMax(Node *p)
{
    int x = 0;
    if (p == 0)
        return INT32_MIN;
    x = RMax(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}

//Linear Search
Node *LSearch(Node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

//Recursive Linear Search
Node *RLSearch(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    return RLSearch(p->next, key);
}
//Improvement in Linear Search
Node *MoveToHead(Node *p, int key)
{
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void Insert(Node *p, int data, int index)
{
    Node *t;
    t = new Node();
    t->data = data;
    t->next = NULL;
    if (index == 1)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void InsertL(Node *p, int data)
{
    Node *t, *last;
    t = new Node();
    t->data = data;
    t->next = NULL;
    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

void SortedInsert(Node *p, int x)
{
    Node *t, *q = NULL;
    t = new Node();
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p->data < x && p)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(Node *p, int index)
{
    Node *q;
    int i, x = -1;
    if (index < 0 && index > Count(p))
    {
        return -1;
    }
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

int IsSorted(Node *p)
{
    int x = -65536;
    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void RDuplicate(Node *p)
{
    Node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

//Reversing Linked List by changing data inside node
void Reverse1(Node *p)
{
    int *A, i = 0;
    Node *q;
    A = (int *)malloc(sizeof(int) * Count(p));
    q = p;
    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

//Reversing Linked List using sliding pointers
void Reverse2(Node *p)
{
    Node *q, *r;
    q = r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

//Reversing Linked List using Recursive function
void Reverse3(Node *q, Node *p)
{
    if (p)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

void Concat(Node *p, Node *q)
{
    third=p;
    while(p->next!=NULL)
        p=p->next;
    p->next=q;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q)
        return 1;
    else
        return 0;
}

int main()
{
    struct Node temp,*t1,*t2;
    int A[] = {1,3,5,7,9};
    int B[] = {2,4,6,8,10};
    Create(A, 5);
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    printf("%d\n", isLoop(first));
    //Create2(B, 5);
    //Concat(first,second);
    //Display(third);
    //RDuplicate(first);
    //Reverse1(first);
    //Merge(first, second);
    //Display(third);
    //Reverse3(NULL,first);
    //Display(first);
    //Delete(first,2);
    //cout<<IsSorted(first);
    //Display(first);
    //RDisplay(first);
    //cout << endl;
    //cout << Count(first);
    //cout << RCount(first);
    //cout << endl;
    //cout<<Sum(first);
    //cout<<RSum(first);
    //cout << endl;
    //cout<<"Maximum number in linked list is:";
    //cout<<Max(first);
    //cout<<RMax(first);
    //Insert(first,100,2);
    //Display(first);
    //SortedInsert(first,10);
    //Display(first);
}
