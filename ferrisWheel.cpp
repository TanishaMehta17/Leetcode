#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>w(n);
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
     sort(w.begin(),w.end());
     int start=0, end= n-1,ans=0;
     while(start<=end)
     {
        if(w[start]+w[end]<=x)
        {
            start++;
            end--;
        }
        else
        {
            end--;
        }
        ans++;
     }
    cout<<ans<<endl;
    return 0;
}