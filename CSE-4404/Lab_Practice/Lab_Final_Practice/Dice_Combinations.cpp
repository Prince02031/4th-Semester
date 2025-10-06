#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
vector<int> dp;


//memoization
int solve(int n) {
    if (n == 0) return 1;        // one valid way (no dice)
    if (n < 0) return 0;         // invalid
    if (dp[n] != -1) return dp[n];

    long long ways = 0;
    for (int k = 1; k <= 6; k++) {
        ways += solve(n - k);
        ways %= MOD;
    }
    return dp[n] = ways;
}


//tabulation
int diceWays(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;  // base case: 1 way to make sum 0 (no dice)

    for (int x = 1; x <= n; x++) {
        long long ways = 0;
        for (int k = 1; k <= 6; k++) {
            if (x - k >= 0) {
                ways += dp[x - k];
            }
        }
        dp[x] = ways % MOD;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    dp.assign(n + 1, -1);

    cout << solve(n) << "\n";
    return 0;
}
