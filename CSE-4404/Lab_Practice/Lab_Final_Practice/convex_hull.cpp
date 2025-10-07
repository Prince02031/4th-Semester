#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

// Cross product of OA × OB
long long cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - 
           (A.y - O.y) * (B.x - O.x);
}

vector<Point> convexHull(vector<Point> pts) {
    int n = pts.size(), k = 0;
    if (n <= 1) return pts;

    // Sort points lexicographically (by x, then y)
    sort(pts.begin(), pts.end(), [](auto &a, auto &b) {
        return (a.x == b.x) ? a.y < b.y : a.x < b.x;
    });

    vector<Point> H(2*n);

    // Build lower hull
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(H[k-2], H[k-1], pts[i]) <= 0) k--;
        H[k++] = pts[i];
    }

    // Build upper hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], pts[i]) <= 0) k--;
        H[k++] = pts[i];
    }

    H.resize(k-1);
    return H;
}

int main() {
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;

    auto hull = convexHull(pts);

    cout << "Convex Hull points:\n";
    for (auto &p : hull)
        cout << p.x << " " << p.y << "\n";

    return 0;
}
