#include<iostream>
#include<stdio.h>
using namespace std;
struct Array{
    int A[20];
    int size,length;
};

void Display(Array arr){
    int i;
    for (int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<"\t";

}
void Append(Array *arr,int x){
    if(arr->length<arr->size)
        arr->A[arr->length]=x;
        arr->length++;

}

void Insert(Array *arr,int index,int x){
    int i;
    if(index>=0 && index<=arr->length)
    {
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }   
}



int Delete ( Array *arr,int index){
    int i;
    int x=0;
    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(i=index;i<arr->length;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
    
    return  x;
}

void swap( int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
    
}

int LinearSearch(Array *arr,int key){
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            swap(arr->A[i],arr->A[0]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(Array arr,int key){
    int l=0;
    int h=arr.length-1;
    int mid;

    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr.A[mid]==key)
        {
            return mid; 
        }
        else if(key<arr.A[mid])
        {
            h=mid-1;
        }
        else if(key>arr.A[mid])
        {
            l=mid+1;
        }
    }
    return -1;

}

int RBinSearch(Array arr,int l,int h,int key){
    int mid;
    mid=(l+h)/2;
    if(l<=h)
    {
        if (arr.A[mid]==key)
        {
            return mid;
        }
        else if(key<arr.A[mid])
        {
            return RBinSearch(arr,l,mid-1,key);
        }
        else if(key>arr.A[mid])
        {
            return RBinSearch(arr,mid+1,h,key);
        }
        
    }
    return -1;
}

int Get(Array arr,int index){
    if(index>=0 && index<arr.length)
    {
        return arr.A[index];

    }
    return -1;
}

void Set(Array *arr,int index,int x){
    if(index>=0 && index < arr->length)
    {
        arr->A[index]=x;
    }
    
}

int Max(Array arr)
{
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
        {
            max=arr.A[i];
        }
    }
    return max;
}

int Min(Array arr)
{
    int min=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
        {
            min=arr.A[i];
        }
    }
    return min;
}

int Sum(Array arr)
{
    int i,s=0;
    for(i=0;i<arr.length;i++)
    {
        s+=arr.A[i];
    }
    return s;
}

float Avg(Array arr)
{
    return Sum(arr)/arr.length;
}

void Reverse(Array *arr)
{
    int i=0,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(arr->A[i],arr->A[j]);
    }
}

void InsertSort(Array *arr,int x)
{   
    int i=arr->length-1;
    if(arr->length==arr->size)
    {
        return ;
    }
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int IsSorted( Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
        {
            return 0;
        }
    }
    return 1;
}

void Rearrange(Array *arr)
{
    int i=0;
    int j=arr->length-1;

    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j)
        {
            swap(&arr->A[i],&arr->A[j]);
        }
    }
}

Array* Merge(Array *arr1,Array *arr2)
{
    int i,j,k;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
        }
        else
        {
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for(;i<arr1->length;i++)
    {
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++)
    {
        arr3->A[k++]=arr2->A[j];
    }
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;

    return arr3;
}
int main(){

    Array arr={{2,3,4,5,6},10,5} ;
    Array arr2 ={{7,8,9,10,11},10,5},*arr3 ;
    //Reverse(&arr);
    //InsertSort(&arr,6);
    //cout<<IsSorted(arr);
    //Rearrange(&arr);
    
    Display(arr);
    //cout<<RBinSearch(arr,0,arr.length,10)<<"\n";

    
    return 0;
}