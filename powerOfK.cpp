class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
     int r=0,c=0,l=0;
        vector<int>ans;
        int n=nums.size();
        if(k==1) return nums;
        while(r<n-1)
        {
            if(nums[r]+1==nums[r+1])
            {
                c++;
                if(c+1==k)
                {
                    ans.push_back(nums[r+1]);
                    c=0;
                    r=l+1;
                    l++;
                }
                else
                {
                    r++;
                }
            }
            else
            {
                c=0;
                if(ans.size()<n-k+1)
                ans.push_back(-1);
                r=l+1;
                l++;
            }
        }
        return ans;
    }
};