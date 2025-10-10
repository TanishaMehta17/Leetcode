class Solution {
private:
    int solve(int i,int n,int k, vector<int>&energy,vector<int>&dp)
    {
        if(i>=n) return 0;
        if(i==n-1) return energy[n-1];
        if(dp[i]!=-1) return dp[i];

        int max_energy=0;
        if(i<n)
            max_energy = energy[i] + solve(i+k, n, k, energy, dp);

        return dp[i] = max_energy;
    }
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int maxi = INT_MIN;
        vector<int> dp(n, -1); 

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, solve(i, n, k, energy, dp));
        }
        return maxi;
    }
};
