class Solution {
    private:
int solve(int i, int n, int prev, vector<int>&nums, vector<vector<int>>&dp)
{
    if(i>=n)
        return 0;
    
    if(dp[i][prev+1]!=-1)
        return dp[i][prev+1];
    
    int take, notTake;
    if(prev==-1 || pow(prev,2)==nums[i])
    {
        take= 1+ solve(i+1,n,nums[i],nums,dp);
    }
    notTake= solve(i+1,n,prev,nums,dp);
   return dp[i][prev+1]= max(take,notTake);
}
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size(),-1));
        int ans= solve(0,nums.size()-1,-1,nums,dp);
        return ans;
    }
};