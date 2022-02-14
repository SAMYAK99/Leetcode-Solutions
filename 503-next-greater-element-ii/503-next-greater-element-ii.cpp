class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        
        int n = nums.size() ; 
        
        vector<int> ans(n,-1) ; 
        stack<int> st ; 
        
        // For Circular array use : i%n ; 
        // For Traversing the whole array : (2*n)-1
        for(int i=2*n -1 ; i>=0 ; i--){
            int cur = nums[i%n] ; 
            
            while(!st.empty() && st.top() <= cur){
                st.pop() ; 
            }
            
            // i<n : pushing the elements in the answer array
            if(i<n && !st.empty()){
                ans[i] = st.top() ; 
            }
            
            st.push(nums[i % n]);    
        }
        
        return ans ; 
        
    }
};