#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#include <vector>
#include <stack>

//Nearest Greater to Right or next largest element
vector<int> NGR(vector<int> arr)
{
    vector<int> v;
    stack<int> s;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > arr[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= arr[i])
        {
            while (s.size() > 0 && s.top() <= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

//nearest Greater to left or previous largest element
vector<int> NGL(vector<int> arr)
{
    vector<int> v;
    stack<int> s;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > arr[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= arr[i])
        {
            while (s.size() > 0 && s.top() <= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }

    return v;
}

//nearest smaller to left or nearest smaller element on left side
vector<int> NSL(vector<int> arr)
{
    vector<int> v;
    stack<int> s;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() < arr[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() >= arr[i])
        {
            while (s.size() > 0 && s.top() >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    return v;
}

//nearest smaller to right or nearest greater element on right side
vector<int> NSR(vector<int> arr)
{
    vector<int> v;
    stack<int> s;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top() < arr[i])
        {
            v.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() >= arr[i])
        {
            while (s.size() > 0 && s.top() >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

//it is nearest greater to left which returns the index of nearest greater left element
vector<int> StockSpan(vector<int> arr)
{
    vector<int> v;
    stack<pair<int,int>> s;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top().first > arr[i])
        {
            v.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first <= arr[i])
        {
            while (s.size() > 0 && s.top().first <= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        s.push({arr[i],i});
    }
    return v;
}

vector<int> nsl(vector<int>arr){
    
    int pseudoindex = -1;
    vector<int> left;
    stack<pair<int, int>> s;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        if (s.size() == 0)
        {
            left.push_back(pseudoindex);
        }
        else if (s.size() > 0 && s.top().first < arr[i])
        {
            left.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                left.push_back(pseudoindex);
            }
            else
            {
                left.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    return left;
}

vector<int> nsr(vector<int> arr)
{
    int pseudoindex = arr.size()+1;
    vector<int> right;
    stack<pair<int, int>> s;
    int n = arr.size();
    for (int i = n-1; i >=0; i--)
    {

        if (s.size() == 0)
        {
            right.push_back(pseudoindex);
        }
        else if (s.size() > 0 && s.top().first < arr[i])
        {
            right.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first >= arr[i])
        {
            while (s.size() > 0 && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                right.push_back(pseudoindex);
            }
            else
            {
                right.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    reverse(right.begin(),right.end());
    return right;
}

int MaxAreaHistogram(vector<int>arr)
{
    cout << "hello";
    vector<int> left,right,width,area;
    left=nsl(arr);
    right=nsr(right);
    for(int i=0;i<left.size();i++){
        //int x=right[i]-left[i];
        //width.push_back(right[i] - left[i]);
        cout<<right[i]<<" ";
    }
    cout << "hllo";
    for (int i = 0; i < arr.size(); i++)
    {
        int x = width[i]*arr[i];
        width.push_back(x);
    }
    cout << "lo";
    int n=area.size();
    sort(area.begin(),area.end());
    //cout<<*max_element( area, area +n);
    cout << area[area.size() - 1];
    return area[area.size() - 1];
}

int main()
{
    vector<int> arr = {6,2,5,4,5,1,6};
    vector<int> v;
    //v=NGR(arr);
    //v=NGL(arr);
    //v = NSL(arr);
    //v = NSR(arr);
    //v=StockSpan(arr);
    //int area=MaxAreaHistogram(arr);
    //cout<<"Maximum area is: "<<area<<"\n";
    //v=nsr(arr);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}