class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        set<int> sr , sc ;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0 ;i<m ; i++){
            for(int j=0 ; j<n ;j++){
                if(matrix[i][j] == 0){
                     sr.insert(i);
                     sc.insert(j);
                }
            }
        }
        
         for(int i=0 ;i<m ; i++){
            for(int j=0 ; j<n ;j++){
               if(sr.find(i) != sr.end() || sc.find(j) != sc.end())
                   matrix[i][j] = 0 ;   
            }
        }
        
        
    }
};