#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Node {
    map<char, Node*> links;
    bool flag = false;

    bool containsKey(char ch) {
        return links.find(ch) != links.end();
    }

    void put(char ch, Node* node) {
        links[ch] = node;
    }

    Node* get(char ch) {
        return links[ch];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        sort(folders.begin(), folders.end());
        Trie trie;
        vector<string> result;
        
        for (const string& folder : folders) {
            Node* node = trie.root;
            bool isSubfolder = false;
            
            for (int i = 0; i < folder.length(); i++) {
                if (folder[i] == '/') {
                    if (node->isEnd()) {
                        isSubfolder = true;
                        break;
                    }
                }
                
                if (!node->containsKey(folder[i])) {
                    node->put(folder[i], new Node());
                }
                node = node->get(folder[i]);
            }
            
            if (!isSubfolder) {
                node->setEnd();
                result.push_back(folder);
            }
        }
        
        return result;
    }
};