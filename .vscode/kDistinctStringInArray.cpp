class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>freq;
        for(int i=0;i<arr.size();i++)
        {
            freq[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++)
        {
            string s= arr[i];
            if(freq[s]>1)
                continue;
            else
            {
                k--;
                if(k==0)
                    return s;
                
            }
        }
        return "";
    }
};