class Solution {
public:
    
    /*
    Variation of NEXT Greater Element to Right
    */
    
    vector<int> canSeePersonsCount(vector<int>& nums) {
         
      
         stack<int> st ;
         vector<int> ans ;
        
          int  n  = nums.size() ;
        
        for(int i=n-1 ;i>=0 ;i--){
            
            int cnt = 0 ;
            
             // Keep increasing the count
            while(!st.empty() &&  st.top() <= nums[i]){
                cnt++;
                st.pop();
            }
            
              if (!st.empty()) cnt++; 
              ans.push_back(cnt);
            
            st.push(nums[i]) ; 
        }
        
        reverse(ans.begin(),ans.end());
        
    
        
        return ans ;
    }
};