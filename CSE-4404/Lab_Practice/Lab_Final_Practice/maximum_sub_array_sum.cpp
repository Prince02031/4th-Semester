#include <bits/stdc++.h>
using namespace std;

int maxCrossingSum(const vector<int>& arr, int l, int m, int r) {
    // Find max suffix sum in left half
    long long sum = 0, leftSum = LLONG_MIN;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    // Find max prefix sum in right half
    sum = 0;
    long long rightSum = LLONG_MIN;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return (int)(leftSum + rightSum);
}

int maxSubarraySum(const vector<int>& arr, int l, int r) {
    if (l == r) return arr[l];

    int m = l + (r - l) / 2;

    int left  = maxSubarraySum(arr, l, m);
    int right = maxSubarraySum(arr, m + 1, r);
    int cross = maxCrossingSum(arr, l, m, r);

    return max({left, right, cross});
}

int maxSubarraySum_Kadane(const vector<int>& arr) {
    int n = arr.size();
    long long curr_sum = arr[0];       // start with first element
    long long best_sum = arr[0];       // global max also starts here

    for (int i = 1; i < n; i++) {
        if (curr_sum + arr[i] < arr[i]) {
            curr_sum = arr[i];         // better to start new subarray
        } else {
            curr_sum += arr[i];        // extend current subarray
        }
        best_sum = max(best_sum, curr_sum);  // update global max
    }
    return (int)best_sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << maxSubarraySum(arr, 0, n - 1) << "\n";
    return 0;
}
