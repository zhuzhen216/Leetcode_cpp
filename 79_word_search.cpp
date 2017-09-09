class Solution {
    void dfs(vector<vector<char>>& board,int i, int j, string word){
        if (found) return;
        if (i<0||i>=board.size()||j<0||j>=board[0].size()) return;
        if (board[i][j]=='*' || board[i][j]!=word[0]) return;
        if (board[i][j]==word[0] && word.size()==1) {found=true; return;}
        char cur = board[i][j];
        board[i][j]='*';
        dfs(board,i+1,j,word.substr(1));
        dfs(board,i-1,j,word.substr(1));
        dfs(board,i,j+1,word.substr(1));
        dfs(board,i,j-1,word.substr(1));
        board[i][j]=cur;
        return;
    }
    bool found = false;
    public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i=0;i<board.size();i++){
            for (int j=0;j<board[0].size();j++){
                if (found) return true;
                dfs(board,i,j,word);
            }
        }
        return found;
    }
    /*
    void dfs(vector<vector<char>>& board,int i, int j, const char* word){
        if (found) return;
        if (i<0||i>=board.size()||j<0||j>=board[0].size()) return;
        if (board[i][j]=='*' || board[i][j]!=*word) return;
        if (board[i][j]==*word && *(word+1)=='\0') {found=true; return;}
        char cur = board[i][j];
        board[i][j]='\0';
        dfs(board,i+1,j,word+1);
        dfs(board,i-1,j,word+1);
        dfs(board,i,j+1,word+1);
        dfs(board,i,j-1,word+1);
        board[i][j]=cur;
        return;
    }
    bool found = false;
    public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i=0;i<board.size();i++){
            for (int j=0;j<board[0].size();j++){
                if (found) return true;
                dfs(board,i,j,word.c_str());
            }
        }
        return found;
    }
    */
};
