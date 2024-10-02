class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>m;
        vector<int>v=arr;
        vector<int>ans(arr.size());
        sort(v.begin(),v.end());
        int k=1;
        for(int i=0;i<v.size();i++)
        {
           if(m.find(v[i])==m.end())
           {
               m[v[i]]=k;
               k++;
           }
        }
        for(int i=0;i<arr.size();i++)
        {
           ans[i]= m[arr[i]]; 
        }
        
       return ans; 
    }
};