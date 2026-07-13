class Solution {
public:

    int ans = 0;

    void dfs(TreeNode* root, int maxValue)
    {
        if(root == NULL)
            return;

        if(root->val >= maxValue)
            ans++;

        maxValue = max(maxValue, root->val);

        dfs(root->left, maxValue);

        dfs(root->right, maxValue);
    }
    int goodNodes(TreeNode* root) {
        
        dfs(root, root->val);

        return ans;
    }
};
