#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>  // for std::pair

using namespace std;

int solution(vector<int>& A, vector<int>& B, int N) {
    // int N = A.size();
    unordered_map<int, vector<pair<int, int>>> adj;

    for (int i = 0; i < N; i++) {
        adj[A[i]].push_back(make_pair(B[i], 1));
        adj[B[i]].push_back(make_pair(A[i], 0));
    }

    queue<int> q;
    vector<int> visited(N + 1, 0);
    int reorientations = 0;

    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {  
        int node = q.front();
        q.pop();

        for (const auto& neighbor : adj[node]) {
            int next_city = neighbor.first;
            int direction = neighbor.second;

            if (!visited[next_city]) {
                visited[next_city] = 1;
                q.push(next_city);
                reorientations += direction;
            }
        }
    }

    return reorientations;
}

void test_solution() {
    vector<int> A = {0, 2, 2, 3};
    vector<int> B = {1, 1, 4, 4};
    int N = 4;
    cout << "Test Case 1: Expected output = 2, Actual output = " << solution(A, B, N) << endl;

    A = {0, 1, 1, 2, 3};
    B = {1, 2, 3, 4, 5};
    N = 5;
    cout << "Test Case 2: Expected output = 3, Actual output = " << solution(A, B, N) << endl;

    A = {0, 0, 0};
    B = {1, 2, 3};
    N = 3;
    cout << "Test Case 3: Expected output = 0, Actual output = " << solution(A, B, N) << endl;

    A = {0, 1, 1, 1, 1};
    B = {1, 2, 3, 4, 5};
    N = 5;
    cout << "Test Case 4: Expected output = 0, Actual output = " << solution(A, B, N) << endl;

    B = {0,0,0,2,5};
    A = {1,3,4,1,2};
    N =5 ;
    cout << "Test Case 5: Expected output = 0, Actual output = " << solution(A, B, N) << endl;
}

int main() {
    test_solution();
    return 0;
}