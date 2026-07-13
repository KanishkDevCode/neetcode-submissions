class Solution {
public:

    TreeNode* findMin(TreeNode* root)
    {
        while(root->left != NULL)
            root = root->left;

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == NULL)
            return NULL;

        if(key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if(root->left == NULL)
                return root->right;

            if(root->right == NULL)
                return root->left;

            TreeNode* temp = findMin(root->right);

            root->val = temp->val;

            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};