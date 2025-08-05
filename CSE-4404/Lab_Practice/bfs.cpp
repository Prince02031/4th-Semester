#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

enum State {READY, PROCESSING, VISITED};

vector<int> bfs(int n, vector<vector<int>>& adj, int source, int x)
{
    vector<State> state(n+1, READY); //1-based indexing
    queue<int> q;
    int count=0;
    vector<int> dist(n+1,-1);
    dist[source]=0;// shortest distance

    vector<int> parent(n+1,0);
    parent[source]=0; //no path

    state[source]= PROCESSING;
    q.push(source);

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        cout<<"visiting node: "<<u<<endl;
        count++;
        
        for(int v: adj[u])
        {
            if(state[v]==READY)
            {
                state[v]=PROCESSING;
                dist[v]=dist[u]+1;
                parent[v]=u;
                q.push(v);
            }

        }
       
        state[u]=VISITED;
    }

    return parent;
}

void trackPath(int n, vector<int>parent,int x)
{
    // if(dist[x]==-1)
    // {
        // cout<<"No path exists to node "<<x <<endl;
    // }

    vector<int> path;

    while(x!=0)
    {
        path.push_back(x);
        x=parent[x];
    }

    reverse(path.begin(),path.end());
    cout<<"Shortest path: ";
    for(int node:path)
    {
        cout<<node<<" ";
    }
    cout<<endl;

}



int main()
{
    int n,e,x;
    cin>>n>>e>>x;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //int shortestDist= bfs(n,adj,1,x);
    vector<int> parent= bfs(n,adj,1,x);
    trackPath(n,parent,x);

    return 0;
}