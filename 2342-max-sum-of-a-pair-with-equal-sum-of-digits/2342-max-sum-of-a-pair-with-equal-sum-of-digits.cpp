class Solution {
public:
    
  long long  int sum(long long int n){
     long long   int s = 0 ;
        while(n!=0){
            s += n%10;
            n /= 10 ;
        }
        
        return s ; 
    }
    
    
    int maximumSum(vector<int>& nums) {
      
         // vector<int , vector<int>> vpp ;
        map<int,vector<int>> mp ; 
        
        sort(nums.begin(),nums.end(),greater<int>()) ;
        
         for(long long int i = 0 ; i<nums.size() ;i++){
             mp[sum(nums[i])].push_back(nums[i]);
            
         }
        
        int sum = 0 ; 
       for(auto it : mp){
           if(it.second.size() <= 1) continue ;
           vector<int> tmp = it.second ;
           sum = max(sum,tmp[0]+tmp[1]) ; 
       }
        
        
        return sum == 0 ? -1 : sum ; 
        
    }
};