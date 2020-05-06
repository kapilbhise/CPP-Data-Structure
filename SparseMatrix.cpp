#include <iostream>
#include <stdlib.h>
using namespace std;

struct Element{
    int i,j,x;
};

struct Sparse{
    int m,n,num;
    Element *ele;
};

void Create(Sparse *s)
{
    cout<<"Enter Dimensions:\n";
    cin>>s->m>>s->n;
    cout<<"Enter number of non-zero elements:\n";
    cin>>s->num;
    s->ele=new Element[s->num];
    cout<<"Enter Non-zero elements:\n";
    for(int i=0;i<s->num;i++)
    {
        cin >> s->ele[i].i;
        cin >> s->ele[i].j;
        cin >> s->ele[i].x;
    }
}

void Display(Sparse s)
{
    int i,j,k=0;
    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i==s.ele[k].i && j==s.ele[k].j)
            {
                cout<<s.ele[k++].x<<" ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<"\n";
    }
}

 Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;
    if (s1->n != s2->n && s1->m != s2->m)
        return NULL;
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->ele = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));
    while (i < s1->num && j < s2->num)
    {
        if (s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if (s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++] = s2->ele[j++];
        else
        {
            if (s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s1->ele[i++];
            else if (s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++] = s2->ele[j++];
            else
            {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }
    for (; i < s1->num; i++)
        sum->ele[k++] = s1->ele[i];
    for (; j < s2->num; j++)
        sum->ele[k++] = s2->ele[j];
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;
    return sum;
}

int main()
{
    struct Sparse s1, s2, *s3;
    Create(&s1);
    Create(&s2);
    s3 = add(&s1, &s2);
    printf("First Matrix\n");
    Display(s1);
    printf("Second Matrix\n");
    Display(s2);
    printf("Sum Matrix\n");
    Display(*s3);
    return 0;
}