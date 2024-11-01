#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    multiset<long long int> arr1;
    vector<long long int> arr2(m);
    vector<long long int> ans(m);

    for (int i = 0; i < n; i++)
    {
        long long int price;
        cin >> price;
        arr1.insert(price);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    for (int i = 0; i < m; i++)
    {
        auto it = arr1.upper_bound(arr2[i]);
        
        if (it != arr1.begin())
        {
            it--;
            ans[i] = *it;
            arr1.erase(it);
        }
        else
        {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
