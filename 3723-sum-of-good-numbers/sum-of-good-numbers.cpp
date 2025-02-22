class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            int left=i-k;
            int right=i+k;
            if(left>=0 && right<n)
            {
                if(nums[i]>nums[left] && nums[i]>nums[right])
                sum+=nums[i];
            }
            else if(left>=0)
            {
                if(nums[i]>nums[left])
                sum+=nums[i];
            }
            else if(right<n)
            {
                if(nums[i]>nums[right])
                sum+=nums[i];
            }
        }
        return sum;
    }
};