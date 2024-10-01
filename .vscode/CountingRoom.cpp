#include<bits/stdc++.h>
using namespace std;

void dfs(int row,int col,int n,int m,int dr[],int dc[],vector<vector<char>>&grid,vector<vector<int>>&vis)
{
    vis[row][col]=1;
    for(int i=0;i<4;i++)
    {
        int nrow=row +dr[i];
        int ncol= col+ dc[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='.')
        {
            dfs(nrow,ncol,n,m,dr,dc,grid,vis);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    int room=0;
    int dr[]={-1,0,1,0};
    int dc[]={0,-1,0,1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(!vis[i][j] && grid[i][j]=='.')
           {
            room++;
            dfs(i,j,n,m,dr,dc,grid,vis);
           }
        }
    }
    cout<<room<<endl;
}