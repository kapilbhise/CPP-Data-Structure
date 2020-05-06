#include<iostream>
using namespace std;

struct stack {
    int size;
    int top;
    int *s;
};
void create(stack *st)
{
    cout<<"Enter size of stack : ";
    cin>>st->size;
    st->top= -1;
    st->s=new int(st->size);
}

void Display(stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        cout << st.s[i] << " ";
    }
    cout << "\n";
}

void push(stack *st,int x)
{
    if (st->size-1==st->top)
    {
        cout << "stack overflow";
        
    }    
    else
    {
        st->top++;
        st->s[st->top] = x;
        cout << "Value is added at position:" << st->top << "\n";
    }    
}

int pop( stack *st)
{   
    int x=-1;
    if(st->top==-1)
        return x;
    else
    {
        x=st->top;
        st->top--;
        cout<<"Value is removed from posttion:"<<st->top+1<<"\n";
    }
    return x;

}

int peek(stack st,int pos)
{   
    int x=-1;
    if(st.top-pos+1<0)
        cout<<"position is invalid";
    else
    {
        x=st.s[st.top-pos+1];
    }
    return x;
}

int isEmpty(stack st)
{
    return st.top==-1;
}

int isFull(stack st)
{
    return st.top==st.size-1;
}

int stackTop(stack st)
{   
    
    if(st.top==-1)
        return -1;
    else
        return st.s[st.top];
}

int main()
{
    stack st;
    
    st.size=5;
    st.s=new int[st.size];
    st.top=-1;
    push(&st,50);
    push(&st, 60);
    push(&st, 70);
    push(&st, 80);
    push(&st, 90);
    Display(st);
    //cout<<pop(&st);
    cout<<peek(st,1);


}