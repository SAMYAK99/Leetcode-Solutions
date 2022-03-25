class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if( n == 0) return 0;
        int island = 0;
        
        for( int i =0 ; i< n ; i++){
             for(int j = 0 ; j< grid[0].size() ; j++){
                 if(grid[i][j] == '1') {
                    dfs(grid , i , j);
                    island++;
                }
            }
        }
        return island;
    }
        
        void dfs(vector<vector<char>>& grid , int i , int j ){
            if( i< 0 || j < 0 || i> grid.size()-1 || j> grid[0].size() -1) return;
            
            if(grid[i][j] == '0') return ;
            
            grid[i][j] = '0';
            dfs(grid , i+1 , j);
            dfs(grid , i , j+1);
            dfs(grid , i-1 , j);
            dfs(grid , i , j-1);
        }
};