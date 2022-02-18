class Solution {
public:
    
    // Time Complexity : 2^t * k 
    
    void  findCombinations(vector<vector<int>> &ans ,vector<int> arr , vector<int> tmp , 
                           int index , int target) {
        
        // Base case : If we reach the end of the array
        if(index == arr.size()){
            if(target == 0){
                ans.push_back(tmp);
            }
            return ; 
        }
        
        // Recursive cases
        // If element is Picked : We subtract current index
        if(arr[index] <= target){
            tmp.push_back(arr[index]) ; 
             findCombinations(ans , arr , tmp , index , target - arr[index]) ;
            
            // IMPORTANT : Remove the previous element 
            tmp.pop_back() ; 
        }
        
        // If element is not Picked : We move further
         findCombinations(ans , arr , tmp , index + 1 , target) ;
        
    }
 
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         
        vector<vector<int>>  ans ; 
        vector<int> tmp ;
        
        findCombinations(ans , candidates , tmp , 0 , target) ; 
        
        return ans ; 

    }
};