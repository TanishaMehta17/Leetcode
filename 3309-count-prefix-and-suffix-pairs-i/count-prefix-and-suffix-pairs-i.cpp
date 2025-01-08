#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool end;

    TrieNode() {
        end = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->end = true;
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch];
        }
        return true;
    }

    // Clear the Trie
    void clear() {
        delete root;
        root = new TrieNode();
    }

    ~Trie() {
        clear();
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;
        Trie prefix, suffix;

        for (int i = words.size() - 1; i > 0; --i) {
            // Insert the word into the prefix and suffix trie
            prefix.insert(words[i]);
            string reversedWord = words[i];
            reverse(reversedWord.begin(), reversedWord.end());
            suffix.insert(reversedWord);

            // Check all previous words (where j < i)
            for (int j = i - 1; j >= 0; --j) {
                if (words[j].length() > words[i].length()) continue;

                string reversedWordJ = words[j];
                reverse(reversedWordJ.begin(), reversedWordJ.end());

                // Check if words[j] is a prefix and suffix of words[i]
                if (prefix.search(words[j]) && suffix.search(reversedWordJ)) {
                    res++;
                }
            }

            // Clear the tries for the next iteration
            prefix.clear();
            suffix.clear();
        }

        return res;
    }
};