class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
        set<int>miniEle;
        set<int>maxiEle;
        for(int i=0;i<matrix.size();i++)
        {
            int mini=INT_MAX;
           for(int j=0;j<matrix[0].size();j++)
           {
               mini= min(mini,matrix[i][j]);
           }
            miniEle.insert(mini);
        }
         for(int i=0;i<matrix[0].size();i++)
        {
            int maxi=INT_MIN;
           for(int j=0;j<matrix.size();j++)
           {
               maxi= max(maxi,matrix[j][i]);
           }
            maxiEle.insert(maxi);
        }
        for(auto it:miniEle)
        {
            if(maxiEle.find(it)!=maxiEle.end())
                ans.push_back(it);
        }
        return ans;
    }
};