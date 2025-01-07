#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void solve(TreeNode* root, string &s, int &sum) {
    if (root == nullptr)
        return;
    
    s += to_string(root->val);  
    
    if (root->left == nullptr && root->right == nullptr) {
        sum += stoi(s);
        s.pop_back();
        cout << s << " ";  
        return;
    }
    
    if (root->left) {
        solve(root->left, s, sum);
    }
    
    if (root->right) {
        solve(root->right, s, sum);
    }
    s.pop_back();
}

int sumNumbers(TreeNode* root) {
    int sum = 0;
    string s = "";
    solve(root, s, sum);
    return sum;
}

int main() {
    // Constructing a simple binary tree:
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    
    // Calling the sumNumbers function to compute the sum of all root-to-leaf numbers
    int result = sumNumbers(root);
    
    cout << "\nTotal sum: " << result << endl;

    return 0;
}
