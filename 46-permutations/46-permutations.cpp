class Solution {
public:
    
    // Brute Force : Using next permutation 
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans ; 
        sort(nums.begin() , nums.end()) ; 
        int n = nums.size() ; 
        
    do {
          ans.push_back(nums) ; 
       } while (next_permutation(nums.begin(), nums.end()));
        
        return ans ; 
        
    }
};