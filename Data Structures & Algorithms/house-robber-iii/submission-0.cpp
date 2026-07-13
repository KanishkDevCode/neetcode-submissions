class Solution {
public:

    pair<int, int> dfs(TreeNode* root) {

        if(root == NULL)
            return {0,0};

        pair<int,int> left = dfs(root->left);
        pair<int,int> right = dfs(root->right);

        int rob = root->val + left.second + right.second;

        int notRob = max(left.first, left.second)
                    + max(right.first, right.second);

        return {rob, notRob};
    }
    int rob(TreeNode* root) {
        
        pair<int,int> ans = dfs(root);

        return max(ans.first, ans.second);
    }
};