class Solution {
private:
    bool allk(std::map<char, int>& m, int k) {
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second < k)
                return false;
        }
        return true;
    }

public:
    int longestSubstring(std::string s, int k) {
        std::map<char, int> m, mp;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        if (allk(mp, k)) {
            return n;
        }

        int l = 0, ans = 0, r = 0;

        while (l < n && r < n) {
            if (mp[s[l]] >= k) {
                m[s[l]]++;
                if (allk(m, k)) {
                    ans = std::max(ans, l - r + 1);
                }
                l++;
            } else {
                for (int i = r; i < l; i++) {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                }
                
                ans = std::max(ans, longestSubstring(s.substr(r, l - r), k));
                l++;
                r = l;
                m.clear();
            }
        }

        return ans;
    }
};
