#include <bits/stdc++.h>
using namespace std;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int partition_hoare(vector<int>& a, int l, int r) {
    // pick a random pivot and move it to a[l]
    int pidx = uniform_int_distribution<int>(l, r)(rng);
    swap(a[l], a[pidx]);
    int pivot = a[l];

    int i = l - 1, j = r + 1;
    while (true) {
        do { ++i; } while (a[i] < pivot);
        do { --j; } while (a[j] > pivot);
        if (i >= j) return j;
        swap(a[i], a[j]);
    }
}

void quicksort(vector<int>& a, int l, int r) {
    while (l < r) {
        int m = partition_hoare(a, l, r);
        // recurse on smaller side first to keep stack O(log n)
        if (m - l < r - (m + 1)) {
            quicksort(a, l, m);
            l = m + 1;
        } else {
            quicksort(a, m + 1, r);
            r = m;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (n > 0) quicksort(a, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}
