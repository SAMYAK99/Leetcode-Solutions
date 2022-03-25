class Solution {
public:
    
     int dfs(vector<vector<int>>& grid , int x , int y){
        
        // Base Case
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1)
            return 0 ;
        
        // Markig the visited node
        grid[x][y] = -1 ; 
        
        // Do dfs traversal in all four directions
        return 1 + dfs(grid , x , y+1) + dfs(grid , x+1 , y) + dfs(grid , x-1 , y) + dfs(grid , x, y-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int col = grid[0].size();
        int ans = 0 ; 
        
        for(int i=0 ; i<rows; i++){
            for(int j=0 ;j<col ; j++){
               // Compute if 1
                if(grid[i][j] == 1)
               ans = max(ans ,dfs(grid , i,j)); 
            }
        }
        
        return ans ; 
    }   
};