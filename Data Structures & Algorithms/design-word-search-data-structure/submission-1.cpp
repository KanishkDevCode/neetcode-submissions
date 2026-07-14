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

class WordDictionary {
public:

    TrieNode* root;

    WordDictionary() {
        
        root = new TrieNode();
    }
    
    void addWord(string word) {
        
        TrieNode* curr = root;

        for(char c:word) {

            int index = c - 'a';

            if(curr->child[index] == NULL)
                curr->child[index] = new TrieNode();

            curr = curr->child[index];
        }

        curr->isEnd = true;
    }
    
    bool dfs(string &word, int pos, TrieNode* node) {

        if(node == NULL)
            return false;

        if(pos == word.size())
            return node->isEnd;

        char c = word[pos];

        if(c != '.') {

            return dfs(word, pos+1, node->child[c - 'a']);
        }

        for(int i=0; i<26; i++) {

            if(node->child[i] &&  dfs(word, pos+1, node->child[i]))
                return true;
        }

        return false;
    }
    bool search(string word) {
        
        return dfs(word, 0, root);
    }
};
