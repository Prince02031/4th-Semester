#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 1005;

struct Beacon {
    int x, y, r;
};

int n, q;
vector<Beacon> beacons;
vector<int> adj[MAXN];
vector<bool> visited;

// Euclidean distance squared
bool canReach(const Beacon& from, const Beacon& to) {
    long long dx = from.x - to.x;
    long long dy = from.y - to.y;
    long long distSq = dx * dx + dy * dy;
    return distSq <= 1LL * from.r * from.r;
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    cin >> n >> q;
    beacons.resize(n + 1); // 1-based indexing

    for (int i = 1; i <= n; ++i) {
        int x, y, r;
        cin >> x >> y >> r;
        beacons[i] = {x, y, r};
    }

    // Build directed graph
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j && canReach(beacons[i], beacons[j])) {
                adj[i].push_back(j);
            }
        }
    }

    // Answer queries
    while (q--) {
        int a, b;
        cin >> a >> b;

        visited.assign(n + 1, false);
        dfs(a);

        cout << (visited[b] ? "YES" : "NO") << '\n';
    }

    return 0;
}
