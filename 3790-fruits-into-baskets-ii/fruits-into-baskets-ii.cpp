class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n= fruits.size();
        for(int i=0;i<fruits.size();i++)
        {
            for(int j=0;j<baskets.size();j++)
            {
                if(fruits[i]<=baskets[j])
                {
                   // cout<<fruits[i]<<" "<<baskets[j]<<endl;
                    baskets[j]=-1;
                    n--;
                    break;
                }
            }
        }
        return n;
    }
};