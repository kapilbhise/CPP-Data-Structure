#include<iostream>
using namespace std;

struct Queue{
    int size;
    int front,rear;
    int *Q;

};

void create(Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=new int(q->size);
}

void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("Queue is Full");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void Display(Queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)
    {
        cout<<q.Q[i]<<" ";
    }
    cout<<"\n";
}

int isEmpty(Queue q)
{   
    int x=-1;
    if(q.front==q.rear)
    {   
        x=1;
        cout<<"Queue is Empty";
        return x;
    }
    return x;
}

int isFull(Queue q)
{   
    int x=-1;
    if(q.rear==q.size-1)
    {   
        x=1;
        cout<<"Queue is Full.";
        return x;
    }
    return x;
}

int main()
{
    Queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    Display(q);
    cout<<dequeue(&q);
    return 0;
}