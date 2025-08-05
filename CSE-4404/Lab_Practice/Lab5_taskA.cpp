#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;

void floydWarshall(int n,vector<vector<ll>>& dist)
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                    dist[i][j]= min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main()
{
    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<ll>> dist(n+1,vector<ll>(n+1,INT_MAX));

    for(int i=1;i<=n;i++)
    {
        dist[i][i]=0;
    }

    for(int i=0;i<m;i++)
    {
        int a,b;
        ll c;
        cin>>a>>b>>c;

        dist[a][b]= min(dist[a][b],c);
        dist[b][a]= min(dist[b][a],c);
    }

    //preprocess

    floydWarshall(n,dist);

    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(dist[a][b]==INT_MAX)
        {
            cout<<-1<<endl;
        }
        else    
            cout<<dist[a][b]<<endl;
    }

}