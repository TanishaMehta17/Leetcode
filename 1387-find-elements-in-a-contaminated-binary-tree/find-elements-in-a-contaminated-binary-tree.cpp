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
class FindElements {
public:
unordered_set<int>s;
    FindElements(TreeNode* root) {
        queue<TreeNode*>q;
        root->val=0;
        s.insert(0);
        q.push(root);
        while(!q.empty())
        {
            TreeNode *node=q.front();
            q.pop();
            if(node->left)
            {
                node->left->val= node->val*2+1;
                s.insert(node->left->val);
                q.push(node->left);
            }
            if(node->right)
            {
                node->right->val= node->val*2+2;
                s.insert(node->right->val);
                q.push(node->right);
            }
        }
    }
    
    bool find(int target) {
        return s.find(target)==s.end()?false:true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */