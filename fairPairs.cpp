class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end()); // Sort the array to use binary search
        long long ans = 0;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; ++i) { // Loop till n-1 since we need pairs
            int val1 = lower - nums[i];
            int val2 = upper - nums[i];
            
            // Find the lower bound for val1
            auto low = std::lower_bound(nums.begin() + i + 1, nums.end(), val1);
            // Find the upper bound for val2
            auto up = std::upper_bound(nums.begin() + i + 1, nums.end(), val2);
            
            // Calculate the number of valid pairs
            ans += up - low;
        }
        
        return ans;
    }
};
