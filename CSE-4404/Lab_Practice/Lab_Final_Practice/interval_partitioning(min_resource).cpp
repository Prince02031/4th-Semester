#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start, finish, id;
};

// Function for interval partitioning
pair<int, vector<int>> intervalPartitioning(vector<Interval>& jobs) {
    // 1) Sort jobs by start time
    sort(jobs.begin(), jobs.end(), [](auto &a, auto &b){
        return a.start < b.start;
    });

    // 2) Min-heap: (finish time, resource id)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    int resourceCount = 0;
    vector<int> assignment(jobs.size() + 1); // assignment by job.id

    for (auto &job : jobs) {
        if (!pq.empty() && pq.top().first <= job.start) {
            // Reuse resource
            int res = pq.top().second;
            pq.pop();
            assignment[job.id] = res;
            pq.push({job.finish, res});
        } else {
            // Allocate new resource
            resourceCount++;
            int res = resourceCount;
            assignment[job.id] = res;
            pq.push({job.finish, res});
        }
    }

    return {resourceCount, assignment};
}

int main() {
    int n;
    cin >> n;
    vector<Interval> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].start >> jobs[i].finish;
        jobs[i].id = i + 1;
    }

    auto [resources, assignment] = intervalPartitioning(jobs);

    cout << "Minimum resources needed: " << resources << "\n";
    cout << "Assignments:\n";
    for (int i = 1; i <= n; i++) {
        cout << "Job " << i << " → Resource " << assignment[i] << "\n";
    }

    return 0;
}
