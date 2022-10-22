class Solution {
public:
    
    vector<int> original;
	int n; 
    
    Solution(vector<int>& nums) {
    
        // copying all the elements for using it in next iteration
        original = nums ; 
        n = original.size() ;
        
    }
    
    vector<int> reset() {
        
       return original ; 
        
    }
    
    vector<int> shuffle() {
        
        vector<int> shuffled = original ;
        
        int leftSize = n ;
        for(int i=n-1 ; i>=0 ;i--){
            
            // Getting a random number in the range of 0 to n
            int j = rand() % leftSize ; 
            leftSize--;
            
            // Shuffling the array
            swap(shuffled[i] , shuffled[j]);     
        }
        
        return shuffled ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */