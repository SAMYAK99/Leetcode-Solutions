class Solution {
public:
    
    // Simple DFS Call 
    
    bool dfs(vector<vector<char>>& board , int i , int j , string word , int count){
        
        //base case
        if(count == word.size())
            return true;
        
        if(i<0 || j<0 || i>board.size()-1 || j >board[0].size()-1 || board[i][j] != word[count] )
            return false ; 
        
        // Stroing the current variable and replacing it with * to avoid confusion in backtracking
        char tmp = board[i][j] ; 
        board[i][j] = '*';
        
        
        bool found  = dfs(board,i+1,j,word,count+1) || 
                      dfs(board,i-1,j,word,count+1)  ||
                      dfs(board,i,j+1,word,count+1) ||
                      dfs(board,i,j-1,word,count +1) ; 
        
       
        // Placing the same charachter that we removed above
        board[i][j] = tmp ;
        
        return found ; 
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0 ; i<board.size();i++){
            for(int j=0 ; j<board[i].size();j++){
                if(board[i][j] == word[0] && dfs(board,i,j,word,0))
                    return true ; 
            }
        }
        
        return false ; 
    }
};