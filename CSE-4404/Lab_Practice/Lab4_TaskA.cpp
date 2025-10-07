#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

enum State {READY, PROCESSING, VISITED};

int dijkstra(int n, vector<vector<int>>& adj, vector<vector<int>>& weight, int source, vector<int>tmu)
{
    vector<int> dist(n+1, INT_MAX);
    vector<int> parent(n+1,-1);
    vector<State> state(n+1, READY);

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;

    dist[source]=0;
    state[source]=PROCESSING;
    pq.push({0,source, tmu[source]});

    //int currBike=1;

    while(!pq.empty())
    {
        //int u=get<1>(pq.top());
        auto [currDist,u,bikeTime]= pq.top();
        pq.pop();

        if(state[u]==VISITED) continue;

        for(int i=0;i<adj[u].size();i++)
        {
            int v= adj[u][i];
            int w= weight[u][i];

            int newBikeTime= min(bikeTime, tmu[v]);
            int newDist= currDist+ w*newBikeTime;

            if(state[v]!=VISITED && dist[u]+ newDist<dist[v])
            {
                dist[v]= newDist;
                parent[v]=u;
                pq.push({dist[v],v, newBikeTime});
                state[v]= PROCESSING;
            }
        }

        state[u]=VISITED;
    }

    return dist[n];
}

int main()
{
    int t;
    cin>>t;

    while(t--){


        int n,m;
        cin>>n>>m;

        vector<vector<int>> adj(n+1);
        vector<vector<int>> weight(n+1);
        vector<int> tmu(n+1);

        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;

            adj[u].push_back(v);
            adj[v].push_back(u);

            weight[u].push_back(w);
            weight[v].push_back(w);
        }

        for(int i=1;i<=n;i++)
        {
            int s;
            cin>>s;

            tmu[i]=s;
        }

        int shortestPath= dijkstra(n,adj,weight,1,tmu);

        cout<< shortestPath<<endl;
    }
    return 0;
}