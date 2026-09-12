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
    int f(TreeNode* cur, int &mx) {
        if(cur == nullptr)
            return 0;
        
        int l = f(cur->left, mx);
        int r = f(cur->right, mx);

        mx = max(mx, abs(l - r));

        return 1 + max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) {
        int mx = 0;
        f(root, mx);

        return (mx <= 1);
    }
};
