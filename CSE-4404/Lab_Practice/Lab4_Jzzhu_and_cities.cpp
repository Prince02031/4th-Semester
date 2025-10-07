#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

typedef long long int lli;

enum State {READY, PROCESSING, VISITED};

int dijkstra(int n, vector<vector<int>>& adj, vector<vector<int>>& weight, int source,vector<vector<int>> routes)
{
    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1,-1);
    vector<State> state(n+1, READY);

    priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<>> pq;

    dist[source]=0;
    state[source]=PROCESSING;
    pq.push({0,source});

    int rmRoute=0;

    while(!pq.empty())
    {
        int u=get<1>(pq.top());
        pq.pop();

        if(state[u]==VISITED) continue;

        for(int i=0;i<adj[u].size();i++)
        {
            int v= adj[u][i];
            int w= weight[u][i];

            if(state[v]!=VISITED && dist[u]+ w<dist[v])
            {
                dist[v]= dist[u]+w;
                parent[v]=u;
                pq.push({dist[v],v});
                state[v]= PROCESSING;

            }
        }

        state[u]=VISITED;
    }

    for(int i=2;i<=n;i++)
    {
        
        if(routes[i].empty()) continue;

        bool oneKept=false;

        for(int y: routes[i])
        {
            if(y==dist[i] && !oneKept)
            {
                oneKept=true;
            }
            else
                rmRoute++;
        }

    }

    return rmRoute;
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int>> adj(n+1);
    vector<vector<int>> weight(n+1);
    vector<vector<int>> routes(n+1);

    for(int i=0;i<m;i++)
    {
        int u,v,x;
        cin>>u>>v>>x;

        adj[u].push_back({v});
        adj[v].push_back({u});

        weight[u].push_back(x);
        weight[v].push_back(x);

    }

    for(int i=0;i<k;i++)
    {
        int s,y;
        cin>>s>>y;

        adj[1].push_back({s});
        adj[s].push_back({1});

        weight[1].push_back(y);
        weight[s].push_back(y);

        routes[s].push_back(y);
    }

    int rmCount = dijkstra(n, adj, weight,1,routes);
    cout << rmCount << "\n";


}