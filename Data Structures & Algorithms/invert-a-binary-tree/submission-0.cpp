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
    void dfsSwap(TreeNode* cur) {
        if(cur == nullptr)
            return;
        TreeNode* temp = cur->left;
        cur->left = cur->right;
        cur->right = temp;

        dfsSwap(cur->left);
        dfsSwap(cur->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* cur = root;
        dfsSwap(cur);
        return root;
    }
};
