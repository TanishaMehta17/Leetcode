#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    long long int sum=0,maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        maxi=max(maxi,sum);
        if(sum<=0)
        sum=0;
    }
    cout<<maxi<<endl;
    return 0;
}