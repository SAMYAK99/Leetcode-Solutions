class Solution {
public:
    
      /*
        -> Convert all odd numbers to 1 and even numbers to 0
        -> Problem reduces to find number of subarray whose sum is equal to k
     */
        
    
    
    int numberOfSubarrays(vector<int>& nums, int k) {
       
      
          for(int i= 0 ;i<nums.size() ;i++){
              if(nums[i]%2==0)
                  nums[i] = 0 ; 
              else
                  nums[i] = 1 ; 
          }
        
         int n = nums.size();
        
       // setting the 0 sum with count 1 
       unordered_map<int,int> um = {{0,1}} ; 
        
        int count = 0 , sum = 0 ;
        
        
        for(auto w : nums){
            sum += w ;
            // Incrementing the frequency if sum - k is found
            // eg : k = 7 , arr[i] = 7 , sum = 14  is found then 14 - 7 is our answer
            // Mainly for Individual array whose sum is equal to k
            count += um[sum-k];
            // Added the found sum and Incrementing the count frequency
            um[sum]++;
        }
        
        return count ; 
        
       
    }
};