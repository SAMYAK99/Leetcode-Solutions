class Solution {
public:
    
    vector<vector<int>> ans ; 
        
    void sub(  vector<int> nums , vector<int> tmp ,   int i){
        
       // Base case 
       if(i == nums.size()){
           ans.push_back(tmp) ; 
           return ; 
       }
        
        sub(nums,tmp,i+1);
        tmp.push_back(nums[i]);
        sub(nums,tmp,i+1);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        
         vector<int> tmp ;
         sub(nums,tmp,0);
        
         return ans ; 
    }
};