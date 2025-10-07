#include <bits/stdc++.h>
using namespace std;

int main() {
    const int MOD = 1'000'000'007;
    int n;
    cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];

    vector<vector<int>> dp(n, vector<int>(n, 0));

    if (g[0][0] == '.') dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == '*') { 
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0) continue;
            long long up   = (i > 0) ? dp[i-1][j] : 0;
            long long left = (j > 0) ? dp[i][j-1] : 0;
            dp[i][j] = (up + left) % MOD;
        }
    }

    cout << dp[n-1][n-1] << "\n";
    return 0;
}
