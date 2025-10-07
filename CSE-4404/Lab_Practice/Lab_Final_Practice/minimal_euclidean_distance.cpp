#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

long long dist2(const Point &a, const Point &b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx*dx + dy*dy;
}

long long bruteForce(vector<Point>& pts, int l, int r) {
    long long ans = LLONG_MAX;
    for (int i = l; i <= r; i++) {
        for (int j = i+1; j <= r; j++) {
            ans = min(ans, dist2(pts[i], pts[j]));
        }
    }
    return ans;
}

long long closestUtil(vector<Point>& pts, int l, int r) {
    if (r - l + 1 <= 3) {
        return bruteForce(pts, l, r);
    }

    int mid = (l + r) / 2;
    long long midx = pts[mid].x;

    long long d = min(closestUtil(pts, l, mid),
                      closestUtil(pts, mid+1, r));

    // Build strip of points within sqrt(d) distance from mid line
    vector<Point> strip;
    for (int i = l; i <= r; i++) {
        if ((pts[i].x - midx)*(pts[i].x - midx) < d)
            strip.push_back(pts[i]);
    }

    // Sort strip by y
    sort(strip.begin(), strip.end(), [](auto &a, auto &b){
        return a.y < b.y;
    });

    // Check each point with next few points
    for (int i = 0; i < (int)strip.size(); i++) {
        for (int j = i+1; j < (int)strip.size() && 
             (strip[j].y - strip[i].y)*(strip[j].y - strip[i].y) < d; j++) {
            d = min(d, dist2(strip[i], strip[j]));
        }
    }

    return d;
}

long long closestPair(vector<Point>& pts) {
    sort(pts.begin(), pts.end(), [](auto &a, auto &b){
        return a.x < b.x;
    });
    return closestUtil(pts, 0, pts.size()-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    cout << closestPair(pts) << "\n";
    return 0;
}
