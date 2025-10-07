#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> bellmanFord(int n, vector<vector<int>>&edges, int src, vector<int>&parent)
{
    vector<int>dist(n+1,INT_MAX);
    parent.assign(n+1,-1);

    dist[src]=0;

    for(int i=1;i<n+1;i++)
    {
        for(auto edge: edges)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];

            if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
            {
                if(i==n)
                    return {-1};
                dist[v]= dist[u]+w;
                parent[v]=u;
            }
        }
    }
    return dist;
}



int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges;

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});

    }

    int src;
    cin>>src;

    vector<int> parent;
    vector<int>dist= bellmanFord(n,edges,src,parent);

    for(int i=1;i<=n;i++)
    {
        cout<<"node: "<<i<<" distance: "<<dist[i]<<endl;
    }

    return 0;


}