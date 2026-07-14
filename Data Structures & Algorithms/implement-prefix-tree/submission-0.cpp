class TrieNode {
public:

    TrieNode* child[26];

    bool isEnd;

    TrieNode() {

        for(int i=0; i<26; i++)
            child[i] = NULL;

        isEnd = false;
    }
};

class PrefixTree {
public:

    TrieNode* root;
    
    PrefixTree() {
        
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* curr = root;

        for(char c:word) {

            int index = c - 'a';

            if(curr->child[index] == NULL)
                curr->child[index] = new TrieNode();

            curr = curr->child[index];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        
        TrieNode* curr = root;

        for(char c:word) {

            int index = c - 'a';

            if(curr->child[index] == NULL)
                return false;

            curr = curr->child[index];
        }

        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* curr = root;

        for(char c:prefix) {

            int index = c - 'a';

            if(curr->child[index] == NULL)
                return false;

            curr = curr->child[index];
        }

        return true;
    }
};
