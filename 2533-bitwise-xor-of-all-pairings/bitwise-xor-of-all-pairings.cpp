class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long, long long>freq;
        int n1= nums1.size();
        int n2= nums2.size();
        int ans=0;
        for(int i=0;i<nums1.size();i++)
        {
            freq[nums1[i]]+=n2;
        }
        for(int i=0;i<nums2.size();i++)
        {
            freq[nums2[i]]+=n1;
        }
        for(auto it=freq.begin();it!=freq.end();it++)
        {
            if(it->second%2!=0)
            {
                ans^= it->first;
            }
        }
        return ans;
    }
};