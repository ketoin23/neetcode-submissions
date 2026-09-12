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
    bool f(TreeNode *a, TreeNode *b) {
        if(a == nullptr && b == nullptr)
            return true;
        if(a == nullptr || b == nullptr)
            return false;

        if(a->val != b->val)
            return false;
        
        return (f(a->left, b->left) & f(a->right, b->right));
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return f(p, q);
    }
};
