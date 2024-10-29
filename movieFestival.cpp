#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.begin(), v.end());sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    });
    int movie = 1;
    int last_end_time = v[0].second;

    for (int i = 1; i < n; i++) {
        if (v[i].first >= last_end_time) {
            movie++;
            last_end_time = v[i].second;
        }
    }
    
    cout << movie << endl;
    return 0;
}
