class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        
         vector<int> ans ;
         int n = nums.size();
        
        if(n%2 != 0)
            return ans ;
        
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        
        for(int i=0 ; i<n ;i++)
            mp[nums[i]]++;
        
        for(int val : nums){
            
            if(mp[val]){
                mp[val]--;
                ans.push_back(val);
                
                 
              if(mp[val*2]){
                 mp[val*2]--;
              }
              else{
                  return vector<int>();
              }
            }
           
        }
        
        return ans ;
        
    }
};