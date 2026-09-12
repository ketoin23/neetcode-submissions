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
    int f(TreeNode* cur, unordered_map<TreeNode*, int> &mp) {
        if(cur == nullptr)
            return 0;
        
        int l = f(cur->left, mp);
        int r = f(cur->right, mp);

        mp[cur] = l + r;
        return 1 + max(l, r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // the max distance between 2 nodes can be the sum of max depth on left and right side of a node
        unordered_map<TreeNode*, int> mp;
        TreeNode* cur = root;
        f(cur, mp);
        int res = 0;
        for(auto i : mp) {
            res = max(res, i.second);
        }

        return res;
    }
};
