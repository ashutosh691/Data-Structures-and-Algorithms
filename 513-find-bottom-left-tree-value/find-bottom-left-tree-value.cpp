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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = -1, n = 0;
        q.push(root);
        while(n = q.size()) {
            bool first = true;
            while(n--) {
                TreeNode* t = q.front();
                q.pop();
                if(first) ans = t->val, first = !first;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return ans;
    }
};