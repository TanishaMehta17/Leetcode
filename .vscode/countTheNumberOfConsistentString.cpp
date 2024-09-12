class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>s(allowed.begin(),allowed.end());
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            bool flag=false;
            set<char> s1(words[i].begin(),words[i].end());
            for(auto it=s1.begin();it!=s1.end();it++)
            {
                if(s.find(*it)==s.end())
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
                count++;
        }
        return count;
    }
};