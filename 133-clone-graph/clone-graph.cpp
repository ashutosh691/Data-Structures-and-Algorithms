class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* dfs(Node* node) {
        if(mp.count(node)) return mp[node];
        Node* temp = new Node(node->val);
        mp[node] = temp;
        for(auto i : node->neighbors) temp->neighbors.push_back(dfs(i));
        return temp;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        return dfs(node);
    }
};