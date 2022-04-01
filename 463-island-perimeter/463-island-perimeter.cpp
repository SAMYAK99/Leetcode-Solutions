class Solution {
public:
    
   void  dfs(vector<vector<int>>& grid , int i , int j ,int &cnt){
        if(i<0 || j < 0 || i>=grid.size() || j>=grid[i].size() || grid[i][j] == 0){
            cnt ++ ; 
            return ;
        }
       
       // If the node is alredy visited 
       if(grid[i][j] == -1)
           return ; 
       
       // Marking the node visited
       grid[i][j] = -1;
         
         dfs(grid ,i+1 , j, cnt);
         dfs(grid ,i-1 , j, cnt);
         dfs(grid ,i , j+1, cnt);
         dfs(grid ,i , j-1, cnt);
         
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt = 0 ; 
        
        for(int i=0 ; i<rows ; i++){
            for(int j=0 ;j<cols ; j++){
                if(grid[i][j] == 1){
                    dfs(grid , i , j , cnt);
                }
            }
        }
        
        return cnt ; 
    }
};