#include <bits/stdc++.h>
using namespace std;

const int N = 8;

// Check if placing queen at (row,col) is safe
bool isSafe(const vector<int>& queens, int row, int col) {
    for (int r = 0; r < row; r++) {
        int c = queens[r];
        if (c == col) return false;                          // same column
        if (abs(c - col) == abs(r - row)) return false;      // same diagonal
    }
    return true;
}

// Las Vegas solver for 8 queens
vector<int> lasVegasQueens() {
    vector<int> queens(N, -1);  // queens[row] = column of queen
    int row = 0;
    while (row < N) {
        vector<int> validCols;
        for (int col = 0; col < N; col++) {
            if (isSafe(queens, row, col)) validCols.push_back(col);
        }
        if (validCols.empty()) {
            // Fail → restart from scratch
            return {};
        }
        // Choose random valid column
        int chosen = validCols[rand() % validCols.size()];
        queens[row] = chosen;
        row++;
    }
    return queens;
}

int main() {
    srand(time(0));

    vector<int> solution;
    while (solution.empty()) {
        solution = lasVegasQueens();  // keep trying until a valid solution
    }

    cout << "One solution:\n";
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (solution[r] == c) cout << "Q ";
            else cout << ". ";
        }
        cout << "\n";
    }
}
