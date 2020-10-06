#include <iostream>
#include <stdlib.h>

using namespace std;

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}

//0-1 knapsack recursion
int Knapsack(int weight[], int value[], int W, int n)
{
    if (W == 0 || n == 0)
    {
        return 0;
    }
    if (weight[n - 1] <= W)
    {
        return max(value[n - 1] + Knapsack(weight, value, W - weight[n - 1], n - 1), Knapsack(weight, value, W, n - 1));
    }
    else if (weight[n - 1] > W)
    {
        return Knapsack(weight, value, W, n - 1);
    }
    return 0;
}

// 0-1 knapsack recursion
int knapsack(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    }
    else if (wt[n - 1] > W)
    {
        return knapsack(wt, val, W, n - 1);
    }
    return 0;
}

// 0-1 knapsack top-down approach
int knapSack(int wt[], int val[], int W, int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(
                    val[i - 1] + K[i - 1][w - wt[i - 1]],
                    K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

// Returns true if there is a subset
// of set[] with sum equal to given sum
//using recursion
bool isSubsetSum(int set[], int n, int sum)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;

    // If last element is greater than sum,
    // then ignore it
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);

    /* else, check if sum can be obtained by any  
of the following: 
      (a) including the last element 
      (b) excluding the last element   */
    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

// Returns true if arr[] can be partitioned in two
// subsets of equal sum, otherwise false
bool equalSumPartition(int arr[], int n)
{
    // Calculate sum of the elements in array
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // If sum is odd, there cannot be two subsets
    // with equal sum
    if (sum % 2 != 0)
        return false;

    // Find if there is subset with sum equal to
    // half of total sum
    return isSubsetSum(arr, n, sum / 2);
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {2, 4, 5, 7};
    //cout<<Knapsack(wt,val,7,4);
    //cout << knapsack(wt, val, 7, 4);
    cout << knapSack(wt, val, 7, 4);
    //cout<<isSubsetSum(val,4,5);
    //cout<<equalSumPartition(val,2);//check this
    
    return 0;
}