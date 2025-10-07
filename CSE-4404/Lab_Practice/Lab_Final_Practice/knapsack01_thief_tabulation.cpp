#include <bits/stdc++.h>

using namespace std;

long long knapsack01(const vector<int>& wt, vector<int>& val, int W)
{
    int n= (int)wt.size();
    vector<vector<long long>> dp(n,vector<long long>(W+1,0));

    //base case
    for(int w=0;w<=W;w++)
    {
        dp[0][w]= (wt[0]<=w) ? val[0]:0LL;
    }

    for(int i=1;i<n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            long long notPick= dp[i-1][w];
            long long pick= notPick;
            if(wt[i]<=w)
            {
                pick= max(pick,(long long) val[i]+dp[i-1][w-wt[i]]);
            }
            dp[i][w]=pick;
        }
    }

    return dp[n-1][W];
}

int main()
{
    int n,W;
    cin>>n>>W;
    vector<int>wt(n), val(n);

    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }

    cout<<knapsack01(wt,val,W)<<endl;
}