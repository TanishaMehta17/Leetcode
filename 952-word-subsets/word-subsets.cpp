class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        unordered_map<char, int> m;

        for (int i = 0; i < words2.size(); i++) {
            unordered_map<char,int>freq;
            for (int j = 0; j < words2[i].length(); j++) {
                freq[words2[i][j]]++;
            }
           for (auto it = freq.begin(); it != freq.end(); it++) {
        m[it->first] = max(m[it->first], it->second);
    }
        }
        for (int i = 0; i < words1.size(); i++) {
            int c = 0;
            string word= words1[i];
            sort(words1[i].begin(), words1[i].end());

            for (auto it = m.begin(); it != m.end(); it++) {
                int low = lower_bound(words1[i].begin(), words1[i].end(), it->first) - words1[i].begin();
                int high = upper_bound(words1[i].begin(), words1[i].end(), it->first) - words1[i].begin();
                if (high - low >= it->second)
                    c++;
            }

            if (c == m.size()) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
