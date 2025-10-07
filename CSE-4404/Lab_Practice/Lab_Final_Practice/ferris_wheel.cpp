#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;
    vector<long long> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    sort(p.begin(), p.end());

    int i = 0, j = n - 1;
    int gondolas = 0;

    while (i <= j) {
        if (p[i] + p[j] <= x) {
            i++;
            j--;
        } else {
            j--;
        }
        gondolas++;
    }

    cout << gondolas << "\n";
}
