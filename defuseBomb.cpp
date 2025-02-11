class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n= code.size();
        vector<int>ans(n,0);
        if(k==0)
            return ans;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=1;j<=abs(k);j++)
            {
                if(k<0)
                {
                    sum+=code[(n-j+i)%n];
                }
                else
                {
                    sum+=code[(n+j+i)%n];
                }
            }
            ans[i]=sum;
        }
        return ans;
    }
};