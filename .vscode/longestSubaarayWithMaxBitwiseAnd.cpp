class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int>v= nums;
        sort(v.begin(), v.end());
        int maxi= v[v.size()-1];
        int len=1,ans=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1] && nums[i]==maxi)
                len++;
            else
            {
                ans=max(ans,len);
                len=1;
            }
            
        }
            ans=max(ans,len);
            return ans;
    }
};