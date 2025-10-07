#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    long long profit;
};

// Greedy Job Sequencing returning profit + chosen job sequence
pair<long long, vector<int>> jobSequencing(vector<Job>& jobs) {
    int maxD = 0;
    for (auto &job : jobs) maxD = max(maxD, job.deadline);

    // Sort jobs by profit descending
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b){
        return a.profit > b.profit;
    });

    vector<int> slot(maxD + 1, -1); // slot[t] = job id at time t
    long long totalProfit = 0;

    for (auto &job : jobs) {
        for (int t = min(job.deadline, maxD); t >= 1; --t) {
            if (slot[t] == -1) {
                slot[t] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    // Extract scheduled jobs (ignore -1)
    vector<int> sequence;
    for (int t = 1; t <= maxD; t++) {
        if (slot[t] != -1) sequence.push_back(slot[t]);
    }

    return {totalProfit, sequence};
}

int main() {
    int n;
    cin >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].deadline >> jobs[i].profit;
        jobs[i].id = i + 1;  // give each job an id
    }

    auto [profit, sequence] = jobSequencing(jobs);

    cout << "Max Profit: " << profit << "\n";
    cout << "Job Sequence: ";
    for (int id : sequence) cout << id << " ";
    cout << "\n";

    return 0;
}
