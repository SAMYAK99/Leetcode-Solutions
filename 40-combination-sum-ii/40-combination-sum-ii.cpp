class Solution {
public:
    
    // Time Complexity : 2^t * k 
    
    void  findCombinations(vector<vector<int>> &ans ,vector<int> arr , vector<int> tmp, 
                           int index , int target) {
        
        // Base case : If TARGET becomes  0
            if(target == 0){
                ans.push_back(tmp);
                   return ;
            }
          
        for(int i=index ; i< arr.size() ;i++){
            
         // Avoid picking the same element   
          if(i>index && arr[i] == arr[i-1]) 
              continue ;
            
          // If current element is greater then no need to check further  
          if(arr[i] > target) 
              break ; 
         
          // Pushing the element in our answer  
          tmp.push_back(arr[i]) ; 
            
        // element is picked up
         findCombinations(ans , arr , tmp , i + 1 , target - arr[i]) ;
         // Popping the current element 
            
           tmp.pop_back() ;  
            
        }
        
    }
 
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         
        sort(candidates.begin() , candidates.end()) ; 
        vector<vector<int>>  ans ; 
        vector<int> tmp ;
        
        findCombinations(ans , candidates , tmp , 0 , target) ; 
        
        return ans ; 

    }
};