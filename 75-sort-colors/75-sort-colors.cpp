class Solution {
public:
    
     // Brute Force : Count the number of 0's , 1's and 2's and 
     // place them in array
    
    void sortColors(vector<int>& nums) {
        
      int zero  = 0 ,one = 0 , two = 0 ;
        
        for(int i=0 ;i<nums.size();i++){
            if(nums[i] == 0)  zero++;
            if(nums[i] == 1)  one++;
            else if(nums[i] == 2)two++;
        }
        
        int k=0;
        if(zero > 0)
        while(zero--){
            nums[k++] = 0;
        }
        
        if(one >0)
          while(one--){
            nums[k++] = 1;
        }
        
        if(two > 0)
          while(two--){
            nums[k++] = 2;
        }
   
        
        
    }
};