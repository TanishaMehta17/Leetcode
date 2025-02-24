class Solution {
private:
    bool solve(int i, int n, vector<int>& nums, vector<int>& dp) {
        if (i >= n) return false;
        if (i == n - 1) return true;

        if (dp[i] != -1) return dp[i];

        for (int j = 1; j <= nums[i]; j++) {
            if (solve(i + j, n, nums, dp)) {
                return dp[i] = true;  
            }
        }

        return dp[i] = false;  
    }

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(0, n, nums, dp);
    }
};
