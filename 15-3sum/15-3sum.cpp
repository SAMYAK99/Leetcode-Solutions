class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size() ; 
         vector<vector<int>> ans ; 
        
     
        sort(nums.begin() , nums.end()); 
        
        for(int i=0 ; i<n ;i++){
            
            int start = i+1 ; 
            int end = n-1 ;
            int target =  - nums[i] ; 
            
            while(start < end){
                int sum = nums[start] + nums[end];
                
                if(sum < target)
                    start++;
                
                else if (sum > target)
                    end--;
                
                else {
                   vector<int> tmp = {nums[i], nums[start], nums[end]};
                    ans.push_back(tmp) ;
                    
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards   
                 while(start < end &&  nums[start] == tmp[1] )
                           start++;
                
                // Processing duplicates of Number 3
                // Rolling the front pointer to the next different number forwards   
                 while(start < end &&  nums[end] == tmp[2] )
                             end--;
                }
                           
            }
            
               while(i+1 < n && nums[i+1] == nums[i])
                        i++;   
            }
        
        return ans ; 
        }
    
};