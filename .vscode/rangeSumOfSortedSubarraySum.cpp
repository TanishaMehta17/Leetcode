class Solution {
public:
    int mode=1000000007;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long int >sum;
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            
            for(int j=i;j<n;j++)
            {
                long long int s=0;
                for(int k=i;k<=j;k++)
                    s=(s+nums[k])%mode;
                sum.push_back(s);
                
            }
        }
        sort(sum.begin(),sum.end());  
        for(int i=left;i<=right;i++)
        {
            ans= (ans+sum[i-1])%mode;
        }
        return ans;
    }
};