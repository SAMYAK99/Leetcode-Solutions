class Solution {
public:
    
    /*
    Variation of Next Greater Element to Right
    */
    
    
    vector<int> dailyTemperatures(vector<int>& nums) {
      
         // stack for storing NGL And its Current Index
         stack<pair<int,int>> st ;
         vector<int> ans ;
        
          int  n  = nums.size() ;
        
        for(int i=n-1 ;i>=0 ;i--){
            while(!st.empty() && st.top().first <= nums[i]){
                st.pop();
            }
            
            // If element don't exist push 0 else push [ ngl Index - Current Index ]
            int idx = st.empty() ? 0 : st.top().second - i;
            ans.push_back(idx);
            
            st.push({nums[i],i}) ; 
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans ;
        
    }
};