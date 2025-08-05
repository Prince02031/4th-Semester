#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;



int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n); // 0-based indexing for astronauts (0 to n-1)

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> component_sizes;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int size = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                ++size;

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }

            component_sizes.push_back(size);
        }
    }

    // Now calculate valid pairs
    long long total_pairs = 1LL * n * (n - 1) / 2;
    long long same_country_pairs = 0;

    for (int size : component_sizes) {
        same_country_pairs += 1LL * size * (size - 1) / 2;
    }

    cout << total_pairs - same_country_pairs << endl;


}