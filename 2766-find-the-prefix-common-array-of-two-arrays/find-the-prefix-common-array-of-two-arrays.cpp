class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>m;
        vector<int>ans(A.size());
        for(int i=0;i<A.size();i++)
        {
            m[A[i]]++;
            m[B[i]]++;
            int c=0;
            for(auto it=m.begin();it!=m.end();it++)
            {
                if(it->second>=2)
                c++;
            }
            ans[i]=c;
        }
        return ans;
    }
};