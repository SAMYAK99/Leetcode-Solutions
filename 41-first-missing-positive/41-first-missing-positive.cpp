class Solution {
public:
    
    /*
    It is evident that the answer lies between [1,n+1]. 
    So bring all the elements to their respective position
    i.e if the element is 3 bring it to 3rd position or 2nd index.
    */
    
    int firstMissingPositive(vector<int>& nums) {
      
        int n = nums.size();
        
        for(int i=0 ;i<n ;i++){
            while(nums[i] > 0 and nums[i] <= n and  nums[i] != nums[nums[i] - 1]){
                // bring the element at its resp position
                  swap(nums[i],nums[nums[i]-1]);
            }
        }
        
        for(int i=0 ; i<n ;i++){
            // return the first element which is not equal
            if(nums[i] != i+1)
                return i+1;
        }
        
        
        return n+1;
       
    }
};