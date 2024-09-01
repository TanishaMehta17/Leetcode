class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int originalR= original.size();
        cout<<originalR<<endl;
        vector<vector<int>>ans(m,vector<int>(n));
        if(originalR> m*n || originalR<m*n)
            return {};
        else
        {
            int k=0;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    ans[i][j]= original[k++];
                }
            }
            return ans;
        }
    }
};