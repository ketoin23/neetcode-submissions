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
    bool f(TreeNode* a, TreeNode* b) {
        if(a == nullptr)
            return false;
        
        if(a->val == b->val) {
            TreeNode *temp = a;
            TreeNode *temp2 = b;

            if(match(temp, temp2))
                return true;
        }

        return (f(a->left, b) | f(a->right, b));
    }

    bool match(TreeNode* a, TreeNode* b) {
        if(a == nullptr && b == nullptr)
            return true;
        if(a == nullptr || b == nullptr)
            return false;

        if(a->val != b->val)
            return false;
        
        return (match(a->left, b->left) & match(a->right, b->right));
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == nullptr)
            return true;

        return f(root, subRoot);
    }
};
