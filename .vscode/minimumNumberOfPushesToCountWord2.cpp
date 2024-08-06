class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>freq;
        int ans=0,k=0,mul=1;
        for(int i=0;i<word.length();i++)
        {
            freq[word[i]]++;
        }
        if(freq.size()<=8)
            return word.length();
        else
        {
           vector<int>count;
            for(auto it:freq)
                count.push_back(it.second);
            sort(count.begin(),count.end(),greater<int>());
            
            for(int i=0;i<count.size();i++)
            {
                if(k!=8)
                {
                    ans+=mul*count[i];
                    k++;
                }
               if(k==8)
               {
                    k=0;
                    mul++;
              }
            }
        }
        return ans;
        
    }
};