#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    multiset<int> b;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        b.insert(temp);
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        
        auto lb = b.lower_bound(a[i] - k);
        
       
        if (lb != b.end() && *lb <= a[i] + k) {
            ans++;
            b.erase(lb); 
        }
    }

    cout << ans << endl;

    return 0;
}
