class Solution {
    private:
int xornum(vector<int> &arr, int start, int end)
    {
        int ans=0;
        for(int i=start;i<=end;i++)
        {
            ans=ans^arr[i];
        }
        return ans;
    }
    
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            int start= queries[i][0];
            int end= queries[i][1];
            ans.push_back(xornum(arr,start,end));
        }
        return ans;
    }
};