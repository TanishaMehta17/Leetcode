class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()==k)
        return true;
        if(s.length()<k)
        return false;
        unordered_map<char,int>m;
        int odd=0;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        for(auto it= m.begin();it!=m.end();it++)
        {
            if(it->second%2!=0)
            {
                odd++;
            }
        }
        if(odd>k)
        return false;
        return true;
    }
};