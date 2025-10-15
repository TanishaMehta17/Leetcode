class Solution {
    private:
    bool check(vector<int>&nums, int k)
    {
        int cnt=k-1;
        if(cnt==0)return true;

        for(int j=k+1;j<nums.size();j++)
        {
            if(nums[j]>nums[j-1] && nums[j-k]>nums[j-k-1]) cnt--;
            else cnt=k-1;
            if(cnt==0)return true;
        }
        return false;
    }
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size(),maxi=0;
         vector<int>val;
        for(int i=1;i<=n/2;i++)
        {
            val.push_back(i);
        }
        int low=0,high=val.size()-1;
        while(low<=high)
        {
            int mid= low+(high-low)/2;
            if(check(nums,val[mid]))
            {
                maxi=max(maxi,val[mid]);
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return maxi;

    }
};