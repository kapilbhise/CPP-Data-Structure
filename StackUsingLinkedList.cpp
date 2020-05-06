#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

}*top=NULL;

void push(int x)
{
    Node *t=new Node();
    if(t==NULL)
        cout<<"Stack is Full.";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{   
    int x=-1;
    Node *t;
    if(top==NULL)
    {
        cout<<"stack is empty.";
    }
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        delete(t);
    }
    return x;
}

void Display()
{
    Node *p;
    p=top;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";

}

int pre(char x)
{
    if(x =='+' || x =='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;

}
int main()
{
    push(10);
    push(20);
    push(30);
    Display();
    cout<<pop();
    return 0;
}