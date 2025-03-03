class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>less,big;
        int count=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
            less.push_back(nums[i]);
            else if(nums[i]>pivot)
            big.push_back(nums[i]);
            else
            count++;
        }
        for(int i=0;i<count;i++)
        {
            less.push_back(pivot);
        }
        for(int i=0;i<big.size();i++)
        {
            less.push_back(big[i]);
        }
        return less;
    }
};