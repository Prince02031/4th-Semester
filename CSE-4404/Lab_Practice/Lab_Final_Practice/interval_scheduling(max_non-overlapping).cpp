#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start, finish;
};

int maxNonOverlapping(vector<Interval>& intervals) {
    // sort by finish time
    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b){ return a.finish < b.finish; });

    int count = 0;
    int last_finish = INT_MIN;

    for (auto &iv : intervals) {
        if (iv.start >= last_finish) {
            count++;
            last_finish = iv.finish;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<Interval> intervals(n);
    for (int i=0; i<n; i++)
        cin >> intervals[i].start >> intervals[i].finish;

    cout << maxNonOverlapping(intervals) << "\n";
}
