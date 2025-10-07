#include <bits/stdc++.h>
using namespace std;

// Function to calculate minimal penalty
int minPenalty(vector<int>& a) {
    vector<int> lis;
    for (int x : a) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }
    int LIS = lis.size();
    return max(0, LIS - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << minPenalty(a) << "\n";
    }
    return 0;
}
