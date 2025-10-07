#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
const int M1 = 1000000007;
const int M2 = 1000000009;

struct Edge
{
    int u, v;
    ll w;
};

vector<ll> dijkstra(int n, int start, vector<vector<pair<int, ll>>> &graph)
{
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        auto [du, u] = pq.top();
        pq.pop();
        if (du != dist[u]) continue;
        for (auto [v, w] : graph[u])
        {
            if (dist[v] > du + w)
            {
                dist[v] = du + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m + 1);
    vector<vector<pair<int, ll>>> graph(n + 1);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int s = 1, t = n;

    vector<ll> distFromS = dijkstra(n, s, graph);
    vector<ll> distFromT = dijkstra(n, t, graph);

    ll shortestDistance = distFromS[t];

    vector<vector<pair<int, int>>> dag(n + 1), reverseDag(n + 1);

    for (int i = 1; i <= m; i++)
    {
        int u = edges[i].u, v = edges[i].v;
        ll w = edges[i].w;
        if (distFromS[u] + w + distFromT[v] == shortestDistance && distFromS[u] < distFromS[v])
        {
            dag[u].push_back({v, i});
            reverseDag[v].push_back({u, i});
        }
        if (distFromS[v] + w + distFromT[u] == shortestDistance && distFromS[v] < distFromS[u])
        {
            dag[v].push_back({u, i});
            reverseDag[u].push_back({v, i});
        }
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 1);
    sort(order.begin(), order.end(), [&](int a, int b)
    {
        return distFromS[a] < distFromS[b];
    });

    vector<int> f1(n + 1), f2(n + 1);
    f1[s] = f2[s] = 1;

    for (int u : order)
    {
        for (auto [v, _] : dag[u])
        {
            f1[v] = (f1[v] + f1[u]) % M1;
            f2[v] = (f2[v] + f2[u]) % M2;
        }
    }

    sort(order.begin(), order.end(), [&](int a, int b)
    {
        return distFromS[a] > distFromS[b];
    });

    vector<int> g1(n + 1), g2(n + 1);
    g1[t] = g2[t] = 1;

    for (int u : order)
    {
        for (auto [v, _] : reverseDag[u])
        {
            g1[v] = (g1[v] + g1[u]) % M1;
            g2[v] = (g2[v] + g2[u]) % M2;
        }
    }

    int totalPaths1 = f1[t];
    int totalPaths2 = f2[t];

    vector<int> criticalEdges;
    for (int u = 1; u <= n; u++)
    {
        for (auto [v, idx] : dag[u])
        {
            ll a = 1LL * f1[u] * g1[v] % M1;
            ll b = 1LL * f2[u] * g2[v] % M2;
            if (a == totalPaths1 && b == totalPaths2)
            {
                criticalEdges.push_back(idx);
            }
        }
    }

    sort(criticalEdges.begin(), criticalEdges.end());

    cout << criticalEdges.size() << "\n";
    for (size_t i = 0; i < criticalEdges.size(); i++)
    {
        if (i > 0) cout << " ";
        cout << criticalEdges[i];
    }
    cout << "\n";

    return 0;
}
