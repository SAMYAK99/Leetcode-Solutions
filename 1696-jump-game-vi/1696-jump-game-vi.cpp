class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        
      vector<int> dp(size(nums), INT_MIN);
        
    // set dp[0] = nums[0] and insert it into set
    multiset<int> s ({ dp[0] = nums[0] });  
        
	for(int i = 1; i < size(nums); i++) {
        // erase elements from which we cant jump to current index
        if(i > k) 
            s.erase(s.find(dp[i - k - 1]));  
         // choose element with max score and jump from that to the current index
        s.insert(dp[i] = *rbegin(s) + nums[i]);   
    }
        
	return dp.back();
        
    }
};