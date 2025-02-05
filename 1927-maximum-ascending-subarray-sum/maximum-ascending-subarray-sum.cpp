class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi=INT_MIN,r=0,sum=nums[0];
        if(nums.size()==1)
        return sum;
        while(r<nums.size()-1)
        {
            if(nums[r]<nums[r+1])
            sum+=nums[r+1];
            else
            {
                maxi=max(maxi,sum);
                sum=nums[r+1];
            }
            r++;
        }
        maxi=max(maxi,sum);
        return maxi;
    }
};