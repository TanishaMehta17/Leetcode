class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> freq;
        int l = 0, r = 0, n = s.length(), ans = 0;
        while (r < n ) {
            
            freq[s[r]]++;
           
            while (freq.size()==3) {
                ans += n - r;
                freq[s[l]]--;
                if (freq[s[l]] == 0)
                    freq.erase(s[l]);
                l++;
            }
            r++;
            
        }
        return ans;
    }
};