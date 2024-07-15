#include<bits/stdc++.h>
using namespace std;
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    private:
TreeNode* search(TreeNode* root, int val)
{
    while(root != nullptr)
    {
        if(root->val == val)
            return root;
        if(root->val > val)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> nodeMap;
        TreeNode* root = nullptr;
        set<int> children;
        
        for(auto& description : descriptions)
        {
            int parentVal = description[0];
            int childVal = description[1];
            int isLeft = description[2];
            
            TreeNode* parent;
            if(nodeMap.find(parentVal) == nodeMap.end())
            {
                parent = new TreeNode(parentVal);
                nodeMap[parentVal] = parent;
                if(!root) root = parent;
            }
            else
            {
                parent = nodeMap[parentVal];
            }
            
            TreeNode* child;
            if(nodeMap.find(childVal) == nodeMap.end())
            {
                child = new TreeNode(childVal);
                nodeMap[childVal] = child;
            }
            else
            {
                child = nodeMap[childVal];
            }
            
            if(isLeft == 1)
                parent->left = child;
            else
                parent->right = child;
                
            children.insert(childVal);
        }
        
        for(auto& node : nodeMap)
        {
            if(children.find(node.first) == children.end())
            {
                root = node.second;
                break;
            }
        }
        
        return root;
    }
};
