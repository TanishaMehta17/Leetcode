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
    bool check(TreeNode*temp, int remi, TreeNode* node)
    {
         while(temp!=nullptr)
            {
                if(temp->val>remi)
                {
                    temp=temp->left;
                }
                else if(temp->val<remi)
                {
                    temp=temp->right;
                }
                else if(temp->val==remi)
                {
                    if(temp!=node)
                   return true;
                   return false;
                }
            }
            return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*node= q.front();
            q.pop();
            int nodeData= node->val;
            int remi= k-nodeData;
            bool ans= check(root,remi,node);
            if(ans)
            return true;
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);

        }
        return false;
    }
};