class Solution 
{
private:
 int maxSubArrayMIN(vector<int>& nums, int maxi) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            maxi=min(maxi,sum);
            if(sum>0)
            sum=0;
        }
        return maxi;
    }
    int maxSubArrayMAX(vector<int>& nums, int maxi) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0)
            sum=0;
        }
        return maxi;
    }
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans1=maxSubArrayMAX(nums,INT_MIN),ans2=maxSubArrayMIN(nums,INT_MAX);
       if(maxSubArrayMAX(nums,INT_MIN)==INT_MIN)
       ans1=0;
       if(maxSubArrayMIN(nums,INT_MAX)==INT_MAX)
       ans2=0;
       return max(ans1,abs(ans2));
    }
};