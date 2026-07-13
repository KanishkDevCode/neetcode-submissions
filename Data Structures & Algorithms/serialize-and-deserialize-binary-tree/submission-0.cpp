class Codec {
public:

    void serializeHelper(TreeNode* root, string &s) {

        if(root == NULL) {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string s = "";

        serializeHelper(root, s);
        return s;
    }

    TreeNode* deserializeHelper(vector<string> &nodes,int &index) {

        if(nodes[index] == "N") {
            index++;
            return NULL;
        }

        TreeNode* root=new TreeNode(stoi(nodes[index]));
        index++;

        root->left = deserializeHelper(nodes, index);
        root->right = deserializeHelper(nodes, index);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector<string> nodes;

        string temp = "";

        for(char c : data) {

            if(c == ',') {
                nodes.push_back(temp);
                temp = "";
            }
            else
                temp += c;
        }

        int index = 0;

        return deserializeHelper(nodes, index);
    }
};
