#include<iostream> #include<math.h>
#include<string.h> #include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(ll a, ll b, ll c)
{
    if(a*b<=c)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
}
int main()
{
    ll t; cin>>t;
    for(ll i=0;i<t;i++)
    {
        ll x,y,z; cin>>x>>y>>z;
        solve(x,y,z);
    }
    
    return 0;
    
}