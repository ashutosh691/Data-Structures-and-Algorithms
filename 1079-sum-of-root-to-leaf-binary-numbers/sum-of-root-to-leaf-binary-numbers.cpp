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
    int ans = 0;
    int process(string& temp) {
        int ans = 0, power = 1;
        for(int i = temp.size() - 1; i >= 0; --i) {
            ans += (int)(temp[i] - '0') * power;
            power *= 2;
        }
        return ans;
    }
    void traverse(TreeNode* root, string temp) {
        if(!root) return;
        temp += to_string(root->val);
        if(!root->left && !root->right) {
            ans += process(temp);
            return;
        }
        traverse(root->left, temp);
        traverse(root->right, temp);
    }
    int sumRootToLeaf(TreeNode* root) {
        traverse(root, "");
        return ans;
    }
};