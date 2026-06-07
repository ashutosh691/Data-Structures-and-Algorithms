/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> child;

        for (auto &d : descriptions) {
            int parent = d[0];
            int node = d[1];
            int isLeft = d[2];

            if (!mp.count(parent))
                mp[parent] = new TreeNode(parent);

            if (!mp.count(node))
                mp[node] = new TreeNode(node);

            if (isLeft)
                mp[parent]->left = mp[node];
            else
                mp[parent]->right = mp[node];

            child.insert(node);
        }

        for (auto &d : descriptions) {
            if (!child.count(d[0]))
                return mp[d[0]];
        }

        return nullptr;
    }
};