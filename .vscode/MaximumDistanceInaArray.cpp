class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int, int>> maxi;
        vector<pair<int, int>> mini; 
        int ans1 = INT_MIN;
         int ans2 = INT_MIN;
        
        for (int i = 0; i < arrays.size(); i++) {
            maxi.push_back({arrays[i][0], i});
            maxi.push_back({arrays[i][arrays[i].size() - 1], i});
        }
        
        sort(maxi.begin(), maxi.end());
        sort(mini.begin(), mini.end()); 
        
        int start = 0, end = maxi.size() - 1; 
        
       while(start<=end) {
            int miniVal = maxi[start].first; 
            int maxiVal = maxi[end].first;
            
            if (maxi[start].second != maxi[end].second) 
            { 
                ans1 = max(ans1, maxiVal - miniVal);
                break;
            } 
            else
            {
                start++;
            }
        }
         start = 0, end = maxi.size() - 1; 
         while(start<=end) {
            int miniVal = maxi[start].first; 
            int maxiVal = maxi[end].first;
            
            if (maxi[start].second != maxi[end].second) 
            { 
                ans2 = max(ans2, maxiVal - miniVal);
                break;
            } 
            else
            {
               end--;
            }
        }
        
        return max(ans1,ans2);
    }
};
