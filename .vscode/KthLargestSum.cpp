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
    long long kthLargestLevelSum(TreeNode* root, int k) {
       vector<long long>ans;
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty())
       {
        int size= q.size();
       long long  sum=0;
        for(int i=0;i<size;i++)
        {
             sum+= q.front()->val;
             if(q.front()->left)
             q.push(q.front()->left);
             if(q.front()->right)
             q.push(q.front()->right);
             q.pop();
        }
        ans.push_back(sum);
       
       } 
       sort(ans.begin(),ans.end(), greater<long long>());
        
      if(ans.size()<k)
          return -1;
        return ans[k-1];
    }
};