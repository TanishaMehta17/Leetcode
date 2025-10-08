class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans(spells.size(),0);
        for(int i=0;i<spells.size();i++)
        {
            long long val=0;
            val=success%spells[i]==0?success/spells[i]:success/spells[i]+1;
           
            auto it = lower_bound(potions.begin(), potions.end(), val);
            
            if(it!=potions.end()) 
            {
                
                ans[i]=potions.size()-(it-potions.begin());
            }
            else ans[i]=0;
        }
        return ans;
    }
};