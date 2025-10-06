#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int n, m;

// recursive helper: try filling column row by row
void dfs(int row, int mask, int nextMask, int n, vector<int>& nextMasks) {
    if (row == n) {
        nextMasks.push_back(nextMask);
        return;
    }
    if (mask & (1<<row)) {
        // this row is already filled, move on
        dfs(row+1, mask, nextMask, n, nextMasks);
    } else {
        // vertical domino: occupies current row in both masks
        dfs(row+1, mask|(1<<row), nextMask|(1<<row), n, nextMasks);
        // horizontal domino: occupy current row and next row (if free)
        if (row+1 < n && !(mask & (1<<(row+1)))) {
            dfs(row+2, mask|(1<<row)|(1<<(row+1)), nextMask, n, nextMasks);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int states = 1<<n;

    // precompute transitions for each mask
    vector<vector<int>> trans(states);
    for (int mask=0; mask<states; mask++) {
        vector<int> nextMasks;
        dfs(0, mask, 0, n, nextMasks);
        trans[mask] = nextMasks;
    }

    // DP table: only need two columns at a time
    vector<int> dp(states, 0), ndp(states, 0);
    dp[0] = 1;

    for (int col=0; col<m; col++) {
        fill(ndp.begin(), ndp.end(), 0);
        for (int mask=0; mask<states; mask++) {
            if (dp[mask] == 0) continue;
            for (int nxt : trans[mask]) {
                ndp[nxt] = (ndp[nxt] + dp[mask]) % MOD;
            }
        }
        dp.swap(ndp);
    }

    cout << dp[0] << "\n";
    return 0;
}
