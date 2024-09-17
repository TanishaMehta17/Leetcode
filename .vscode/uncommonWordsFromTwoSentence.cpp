class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        vector<string> ans;

        
        string str = "";
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != ' ') {
                str += s1[i];
            } else {
                m[str]++;
                str = "";
            }
        }
        if (!str.empty()) {
            m[str]++;
        }

        
        str = "";
        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] != ' ') {
                str += s2[i];
            } else {
                m[str]++;
                str = "";
            }
        }
        if (!str.empty()) {
            m[str]++;
        }

        
        for (const auto& [word, count] : m) {
            if (count == 1) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
