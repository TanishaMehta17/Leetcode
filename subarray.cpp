class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0, c = 0, mini = INT_MAX, x = 0;
        while (r < nums.size()) {
            x |= nums[r];
            c++;
            if (x >= k) {
                mini = min(mini, c);
                x = 0;
                c = 0;
                l++;
                r = l;
            } else {
                r++;
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};
