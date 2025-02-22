/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        int n = s.length();
        map<int, TreeNode*> m;
        string num="";
        int id = 0, depth = 0,i=0;
        while(isdigit(s[i]))
                 {
                    num+=s[i];
                    i++;
                 }
         TreeNode* root = new TreeNode(stoi(num));         
         m.insert({0, root});
         num="";
        
        while(i<n) {
            if (s[i] == '-') {
                depth++;
                i++;
            } else 
            {
                 while(isdigit(s[i]))
                 {
                    num+=s[i];
                    i++;
                 }
                TreeNode* parent = m[depth - 1];
                TreeNode* node = new TreeNode(stoi(num));
                
                if (!parent->left) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
                
                m[depth] = node;
                id = depth;
                depth = 0;
                num="";
            }
        }
        return root;
    }
};
