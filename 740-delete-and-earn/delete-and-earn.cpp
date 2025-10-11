class Solution {
    private:
    int solve(int i, int n, const vector<int>&val, unordered_map<int,int>&sum,vector<int>&dp)
    {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=sum[val[i]];
        int j=i+1;
        while(j<n && val[j]-val[i]<=1)j++;
        take+=solve(j,n,val,sum,dp);
        int notTake=solve(i+1,n,val,sum,dp);
        return dp[i]=max(take,notTake);

    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>sum;
        for(int i=0;i<n;i++)
        {
            sum[nums[i]]+=nums[i];
        }
        vector<int>dp(n+1,-1),val;
        for(auto it=sum.begin();it!=sum.end();it++)
        {
            val.push_back(it->first);
        }
          sort(val.begin(), val.end());
        return solve(0,val.size(),val,sum,dp);
    }
};