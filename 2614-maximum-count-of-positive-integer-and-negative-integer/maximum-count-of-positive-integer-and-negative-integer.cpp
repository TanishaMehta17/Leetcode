class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0, n = nums.size();
        auto lb = lower_bound(nums.begin(), nums.end(), 0);
        auto ub = upper_bound(nums.begin(), nums.end(), 0);
        if (lb != nums.end()) {
            if (nums[lb - nums.begin()] >= 0)
                neg = lb - nums.begin();
            else
                neg = lb - nums.begin() - 1;
          cout<<"LOWER BOUND= "<<lb-nums.begin()<<" "<<"NEGATIVE="<<neg<<endl;      
        }
        if (ub != nums.end()) {
            pos = n - (ub - nums.begin());
          cout<<"UPPER BOUND= "<<ub-nums.begin()<<" "<<"POSITIVE="<<pos<<endl;
        }
        if(ub==nums.end() && lb==nums.end())
        return nums.size();
        
        return max(pos, neg);
    }
};