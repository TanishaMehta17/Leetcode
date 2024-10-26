#include<bits/stdc++.h>
using namespace std;
int mod= 1e9+7;
int solve(int i,int  j,int n, vector<vector<char>>&grid, vector<vector<int>>&dp)
{
    if(i>=n || j>=n || grid[i][j]=='*')
    return 0;

    if(i==n-1 && j==n-1)
    return 1;

    if(dp[i][j]!=-1)
    return dp[i][j];

   int right= solve(i+1,j,n,grid,dp);
   int down = solve(i,j+1,n,grid,dp);

   return dp[i][j]=(right+down)%mod;
  
}
int main()
{
    int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>dp(n,vector<int>(n,-1));
     int ans=  solve(0,0,n,grid,dp);
    cout<<ans<<endl;
    return 0;
}