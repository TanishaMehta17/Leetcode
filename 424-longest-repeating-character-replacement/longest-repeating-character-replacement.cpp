class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int max_freq = 0; // Maximum frequency of a character in the current window
        int l = 0, ans = 0;

        for (int r = 0; r < s.length(); r++) {
            freq[s[r]]++;
            max_freq = max(max_freq, freq[s[r]]);
            
            
            while ((r - l + 1) - max_freq > k) {
                freq[s[l]]--;
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};
