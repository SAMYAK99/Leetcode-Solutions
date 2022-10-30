class Solution {
public:
    
    /*
    On going up we need to decrement the row and increment the column
    row++   col--
    
    and vice versa
    */
    
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        vector<int> ans ;
        
        int m = mat.size();
        int n = mat[0].size();
        
        int row = 0 , col = 0 ; 
        bool up = true ; 
        
        while(row < m and col < n){
            // Going Up
            if(up){
               while(row > 0 and col <n-1){ 
                ans.push_back(mat[row][col]);
                row--;
                col++;
               }
                ans.push_back(mat[row][col]); 
                up = false ;
                if(col == n-1)
                    row++;
                else
                    col++;
            }
            // Going Down
            else{
              while(row < m-1 and col > 0){ 
                ans.push_back(mat[row][col]);
                row++;
                col--;
               }
                ans.push_back(mat[row][col]); 
                up = true ;
                if(row == m-1)
                    col++;
                else
                    row++;
            }
        }
        
        
        return ans ; 
    }
};