#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> solve(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        unordered_map<TreeNode*, int> dis;
        q.push({root, 0});
        dis[root] = 0;
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int diaDis = q.front().second;
            q.pop();
            if (node->left) {
                q.push({node->left, diaDis - 1});
                dis[node->left] = diaDis - 1;
            }
            if (node->right) {
                q.push({node->right, diaDis});
                dis[node->right] = diaDis;
            }
        }
        vector<pair<int, int>> nodeDistances;
        for (auto it = dis.begin(); it != dis.end(); it++) {
            nodeDistances.push_back({it->second, it->first->val});
        }
        
        sort(nodeDistances.begin(), nodeDistances.end());
        
        vector<int> ans;
        for (auto& pair : nodeDistances) {
            ans.push_back(pair.second);
        }
        
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(11);
    root->left = new TreeNode(20);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(15);
    root->right->right = new TreeNode(13);
    root->right->right->left = new TreeNode(16);
    root->left->right->left= new TreeNode(2);
    root->left->right->right= new TreeNode(17);
    root->left->right->left->right= new TreeNode(22);
    root->left->right->right->left = new TreeNode(34);

    Solution sol;
    vector<int> result = sol.solve(root);

    cout << "Sorted node values: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
