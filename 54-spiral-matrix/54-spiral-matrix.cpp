class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
         vector<int> ans ; 
         int startRow = 0 ; 
         int startCol = 0 ; 
         int endRow = matrix.size() - 1 ; 
         int endCol = matrix[0].size() - 1 ; 
        
        // traversing the whole row
        
        while(startRow <= endRow && startCol <= endCol){
            
            //1
            for(int i = startCol ; i<= endCol ; i++){
                cout << matrix[startRow][i] << " ";
                ans.push_back(matrix[startRow][i]);
            }
            
            startRow++;
            
            //2
            for(int i = startRow ; i <= endRow ; i++){
                cout << matrix[i][endCol] << " ";
                ans.push_back(matrix[i][endCol]);
            }
            
            endCol--;
            
            //3
            if(startRow <= endRow){
            for(int i = endCol ; i >= startCol ; i--){
                cout << matrix[endRow][i] << " ";
                ans.push_back(matrix[endRow][i]);
            }
            
            endRow--;
            }
            
            //4
            if(startCol <= endCol){
            for(int i = endRow ; i >= startRow ; i--){
                cout << matrix[i][startCol] << " ";
                ans.push_back(matrix[i][startCol]);
            }
            
            startCol++;
            }
        }
        
        return ans ; 
    }
};