class Solution {
private:
    int solve(vector<int>& nums, int k) {
        int r = 0, l = 0, n = nums.size(), count = 0, odd = 0;
        
        while (r < n) {
            if (nums[r] % 2 != 0) odd++;  // Increase odd count for odd numbers
            
            while (odd > k) {  // Shrink window if odd count exceeds k
                if (nums[l] % 2 != 0) odd--; 
                l++;
            }
            
            count += (r - l + 1);  // Count all valid subarrays ending at r
            r++;
        }
        return count;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
