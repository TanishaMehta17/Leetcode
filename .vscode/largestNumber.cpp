class Solution {
public:
    string largestNumber(vector<int>& nums) {
       
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

      
        if (nums[0] == 0) return "0";

      
        string s = "";
        for (int i = 0; i < nums.size(); i++) {
            s += to_string(nums[i]);
        }
        return s;
    }
};
