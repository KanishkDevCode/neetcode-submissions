class Solution {
public:

    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {
        
        if (mp.count(node))
            return mp[node];

        Node* clone = new Node(node->val);
        mp[node] = clone;

        for (Node* nei : node->neighbors)
            clone->neighbors.push_back(dfs(nei));

        return clone;
    }
    Node* cloneGraph(Node* node) {
        
        if (node == NULL)
            return NULL;

        return dfs(node);
    }
};
