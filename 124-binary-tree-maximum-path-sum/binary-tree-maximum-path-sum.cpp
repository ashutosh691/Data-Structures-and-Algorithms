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
    int ans = INT_MIN;
    int trav(TreeNode* root) {
        if(!root) return 0;
        int l = max(0, trav(root->left)), r = max(0, trav(root->right));
        int cSum = l + r + root->val;
        ans = max(ans, cSum);
        return max(l, r) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        trav(root);
        return ans;
    }
};