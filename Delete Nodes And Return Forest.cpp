class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        root = helper(root, to_delete_set, result);
        if (root != nullptr) {
            result.push_back(root);
        }
        return result;
    }
    
private:
    TreeNode* helper(TreeNode* node, unordered_set<int>& to_delete_set, vector<TreeNode*>& result) {
        if (node == nullptr) {
            return nullptr;
        }
        
        node->left = helper(node->left, to_delete_set, result);
        node->right = helper(node->right, to_delete_set, result);
        
        if (to_delete_set.find(node->val) != to_delete_set.end()) {
            if (node->left != nullptr) {
                result.push_back(node->left);
            }
            if (node->right != nullptr) {
                result.push_back(node->right);
            }
            delete node; // Deleting the node since it's in the to_delete list
            return nullptr;
        }
        
        return node;
    }
};