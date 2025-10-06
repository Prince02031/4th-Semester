#include <bits/stdc++.h>

using namespace std;

long long solveMemo(int i, int w, const vector<int> &wt,vector<int> &val, vector<vector<long long>>&dp)
{
    //base case
    if(i==0)
    {
        if(wt[0]<=w)
            return val[0];
        else
            return  0LL;
    }

    if(dp[i][w]!=-1) return dp[i][w];

    long long notPick= solveMemo(i-1,w,wt,val,dp);

    long long pick= LLONG_MIN/4;
    if(wt[i]<=w)
    {
        pick= val[i]+ solveMemo(i-1,w-wt[i],wt,val,dp);
    }

    return dp[i][w]= max(pick,notPick);
}

long long knapsack01(const vector<int>& wt, vector<int>& val, int W) {
    int n = (int)wt.size();
    vector<vector<long long>> dp(n, vector<long long>(W + 1, -1));
    return solveMemo(n - 1, W, wt, val, dp);
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