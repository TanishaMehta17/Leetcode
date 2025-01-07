#include <iostream>
#include <vector>
#include <string>
#include <set>

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> substrings;  
        for (int i = 0; i < words.size(); i++) {
            string str = words[i];
            for (int j = 0; j < words.size(); j++) {
               
                if (words[j].find(str) != string::npos && str != words[j]) {
                    substrings.insert(str);  
                }
            }
        }
        
        
        vector<string> ans(substrings.begin(), substrings.end());
        return ans;
    }
};
