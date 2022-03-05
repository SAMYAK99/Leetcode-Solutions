class Solution {
public:
    
    
  int  countFreq(vector<int> arr, int n , int &ans){
    unordered_map<int, int> mp;
 
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
 
    int mx = 0  , pos = 0; 
    for (auto x : mp){
        int val = x.first * x.second ;
        if(val > mx){
            mx = val ;
            pos = x.first ; 
        }
    }
      ans += mx ; 
      
   return pos ;       
}
    
    
    int deleteAndEarn(vector<int>& nums) {
        
      map<int,int> cnt; //for storing  count
        for(int i=0;i<nums.size();i++)
        {
            cnt[nums[i]]++;
        }
        vector<int> dp(10000+2,0); //dp to store value
        
        int j=2;
        for(int i=1;i<=10000;i++)
        {
            /*recurance relation*/
            dp[j]=max(dp[j-1],cnt[i]*i+dp[j-2]);
            j++;
        }
		//returning the value
        return dp[10000+1];
    }
};