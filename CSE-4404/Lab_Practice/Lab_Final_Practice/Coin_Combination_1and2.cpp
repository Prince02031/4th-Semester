#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Order matters (permutations)
int countPermutations(int n, int x, const vector<int>& coins) {
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int sum = 1; sum <= x; sum++) {
        long long ways = 0;
        for (int coin : coins) {
            if (sum - coin >= 0) {
                ways += dp[sum - coin];
                if (ways >= (long long)MOD * 4) ways %= MOD;
            }
        }
        dp[sum] = (int)(ways % MOD);
    }
    return dp[x];
}

// Order does not matter (combinations)
int countCombinations(int n, int x, const vector<int>& coins) {
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int sum = coin; sum <= x; sum++) {
            dp[sum] += dp[sum - coin];
            if (dp[sum] >= MOD) dp[sum] -= MOD;
        }
    }
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    cout << "Permutations (order matters): "
         << countPermutations(n, x, coins) << "\n";

    cout << "Combinations (order doesn’t matter): "
         << countCombinations(n, x, coins) << "\n";

    return 0;
}
