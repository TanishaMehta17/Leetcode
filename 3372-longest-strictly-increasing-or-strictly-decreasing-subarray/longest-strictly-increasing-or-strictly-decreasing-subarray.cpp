class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1, max_inc = 1, max_dec = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                max_inc = max(max_inc, inc);
            } else {
                inc = 1;
            }
            if (nums[i] < nums[i - 1]) {
                dec++;
                max_dec = max(max_dec, dec);
            } else {
                dec = 1;
            }
        }
        return max(max_inc, max_dec);
    }
};