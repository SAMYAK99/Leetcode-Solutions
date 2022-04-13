class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
       vector<vector<int>> matrix(n, vector<int> (n));
        
        // vector<int> num ; 
         int startRow = 0 ; 
         int startCol = 0 ; 
         int endRow = n - 1 ; 
         int endCol = n - 1 ; 
        
        // Filling the array
        // for(int i=1 ;i<=(n*n) ; i++){
        //     num.push_back(i);
        //    cout << num[i] << " " ; 
        // }
        
        // traversing the whole row
        
        int k = 1 ;
        while(startRow <= endRow && startCol <= endCol){
            
            //1
            for(int i = startCol ; i<= endCol ; i++){
                matrix[startRow][i] = k ; 
                k++;
            }
            
            startRow++;
            
            //2
            for(int i = startRow ; i <= endRow ; i++){
                matrix[i][endCol]  = k ; 
                k++ ;
            }
            
            endCol--;
            
            //3
            if(startRow <= endRow){
            for(int i = endCol ; i >= startCol ; i--){
                 matrix[endRow][i] = k ; 
                 k++ ;
            }
            
            endRow--;
            }
            
            //4
            if(startCol <= endCol){
            for(int i = endRow ; i >= startRow ; i--){
                matrix[i][startCol]  = k ; 
               k++;
            }
            
            startCol++;
            }
        }
        
        return matrix ; 
        
    }
};