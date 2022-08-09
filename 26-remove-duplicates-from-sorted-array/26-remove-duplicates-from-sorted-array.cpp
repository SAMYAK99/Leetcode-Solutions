class Solution {
public:
     
    // Completely Brute Force : USE SET FOR OPTIMIZTION 
    

    int removeDuplicates(vector<int>& nums) {
        
      int i =0 ;
      int n = nums.size();
        
        
        
       for(int j=1 ;j<n ;j++){
           if(nums[i] != nums[j]){
               i++;
               nums[i] = nums[j];
           }
       }
        
        return i+1 ;
       
    }
};