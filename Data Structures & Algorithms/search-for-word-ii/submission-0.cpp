class TrieNode{
public:

    TrieNode* child[26];
    string word;

    TrieNode(){

        for(int i=0;i<26;i++)
            child[i]=NULL;

        word="";
    }
};

class Solution {

public:

    TrieNode* root=new TrieNode();

    vector<string> ans;

    void insert(string word){

        TrieNode* curr=root;

        for(char c:word){

            int idx=c-'a';

            if(curr->child[idx]==NULL)
                curr->child[idx]=new TrieNode();

            curr=curr->child[idx];
        }

        curr->word=word;
    }

    void dfs(vector<vector<char>>& board,int i,int j,TrieNode* node){

        if(i<0||j<0||i>=board.size()||j>=board[0].size())
            return;

        char ch=board[i][j];

        if(ch=='#')
            return;

        if(node->child[ch-'a']==NULL)
            return;

        node=node->child[ch-'a'];

        if(node->word!=""){

            ans.push_back(node->word);

            node->word="";
        }

        board[i][j]='#';

        dfs(board,i+1,j,node);
        dfs(board,i-1,j,node);
        dfs(board,i,j+1,node);
        dfs(board,i,j-1,node);

        board[i][j]=ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        for(string &w:words)
            insert(w);

        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                dfs(board,i,j,root);

        return ans;
    }
};