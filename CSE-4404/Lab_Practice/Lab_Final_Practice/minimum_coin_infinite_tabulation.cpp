#include <bits/stdc++.h>
using namespace std;

// Returns minimum number of coins to make 'T', or INF if impossible.
int memoSolve(int i, int T, const vector<int>& coins, vector<vector<int>>& dp) {
    const int INF = 1e9;

    // Base: only coin[0] is available
    if (i == 0) {
        if (T % coins[0] == 0) return T / coins[0];
        return INF;
    }

    if (dp[i][T] != -1) return dp[i][T];

    // Not pick coin i
    int notPick = memoSolve(i - 1, T, coins, dp);

    // Pick coin i (unbounded -> stay at i)
    int pick = INF;
    if (coins[i] <= T) {
        int sub = memoSolve(i, T - coins[i], coins, dp);
        if (sub != INF) pick = 1 + sub;
    }

    return dp[i][T] = min(pick, notPick);
}

int minCoins_memo(const vector<int>& coins, int amount) {
    int n = (int)coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    const int INF = 1e9;

    int ans = memoSolve(n - 1, amount, coins, dp);
    return (ans >= INF) ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];

    cout << minCoins_memo(coins, amount) << "\n";
    return 0;
}
