class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
          vector<vector<int>> ans ; 
        
        
        for (int i = 0; i < numRows; i++) {
            
          // Intializing all the elements with 1 (first and last)  
		  vector<int> row(i + 1, 1);
            
          // Traversing excluding first and last element  
		 for (int j = 1; j < i; j++) {
             
             // adding previous 2 row elements
			 row[j] = ans[i - 1][j] + ans[i - 1][j - 1];
		 }
            
		   ans.push_back(row);
            
	}
	    return ans;
        
    
    
     /*
      -> Nth element of Pascal Triangle : r-1
      ->                                      C
      ->                                        c-1
      */  
        
    
    }
};