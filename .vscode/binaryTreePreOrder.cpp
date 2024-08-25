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
    private:
    void traverse(TreeNode*root,vector<int>&v)
  {
    if(root==NULL)
    return ;
     else {
      traverse(root->left,v);
      traverse(root->right,v); 
      v.push_back(root->val);
    }
  }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        traverse(root,v);
        return v;
    }
};