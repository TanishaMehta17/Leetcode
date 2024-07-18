#include <set>
#include <map>
#include <queue>
#include <unordered_set>

/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
private:
    void solve(TreeNode* root, set<TreeNode*>& leaf) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
            leaf.insert(root);
        solve(root->left, leaf);
        solve(root->right, leaf);
    }

    void find_parent(TreeNode* root, map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

public:
    int countPairs(TreeNode* root, int distance) {
        set<TreeNode*> leaf;
        map<TreeNode*, TreeNode*> parent;
        solve(root, leaf);
        find_parent(root, parent);
        int count = 0;
        for (auto it : leaf) {
            unordered_set<TreeNode*> visited;
            queue<pair<TreeNode*,int>> q;
            q.push({it,0});
            TreeNode* value = it;
            
            
            while (!q.empty()) {
                
                TreeNode* node = q.front().first;
                int k=q.front().second;
                q.pop();
                TreeNode* left = nullptr;
                TreeNode* right = nullptr;
                TreeNode* p = nullptr;
                if (node->left && node->left != value && visited.find(node->left) == visited.end() && k+1<=distance) {
                    left = node->left; 
                    q.push({left,k+1});
                    visited.insert(left);
                
                }
                if (node->right && node->right != value && visited.find(node->right) == visited.end()  && k+1<=distance) {
                    right = node->right;
                    q.push({right,k+1});
                    visited.insert(right);
                    
                }
                if (parent.find(node) != parent.end() && parent[node] != value && visited.find(parent[node]) == visited.end()  && k+1<=distance) {
                    p = parent[node];
                    q.push({p,k+1});
                    visited.insert(p);
                    
                }
                
                if (left != nullptr && leaf.find(left) != leaf.end() && k+1 <= distance)
                    count++;
                if (right != nullptr && leaf.find(right) != leaf.end() && k+1 <= distance)
                    count++;
                if (p != nullptr && leaf.find(p) != leaf.end() &&k+1 <= distance)
                    count++;
            }
        }
        return count / 2;
    }
};