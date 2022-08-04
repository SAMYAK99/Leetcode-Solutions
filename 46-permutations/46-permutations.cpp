class Solution {
public:
    
    // Simple Backtracking Solution
    /*
    Go from index to n – 1 and swap. Once the swap has been done call recursion for the next state.After coming back from the recursion make sure you re-swap it because for the next element the swap will not take place.
    
    Time Complexity: O(N! X N)  
    Space Complexity: O(1)
    */
    void calculate(int index ,vector<int>& nums ,vector<vector<int>> &ans  ){
        
        // Base case : If we reach at last position n
        if(index == nums.size()){
            ans.push_back(nums);
            return ;
        }
        
        for(int i = index ; i<nums.size() ;i++){
            swap(nums[index],nums[i]);
             calculate(index+1 , nums , ans);
             swap(nums[index],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans ; 
       
        calculate(0,nums,ans);
        
        return ans ;
        
    }
};

