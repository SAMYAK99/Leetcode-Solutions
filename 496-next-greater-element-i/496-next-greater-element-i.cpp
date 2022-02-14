class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> hmap;
        vector<int> result;
        stack<int> st;
        
        // Traversing the array backwards and pushing each greater element in stack
        
        for(int i=nums2.size()-1; i>=0; --i){
            
            int curr = nums2[i];
            
         //Removing the smaller elements from the array until we found the greater                   element   
            while(!st.empty() && st.top()<=curr){
                st.pop();
            }
            int ans = st.empty() ? -1 : st.top();
            hmap.insert({curr, ans});
            st.push(curr);
        }
        
        // Comparing the elements from nums1
        for(auto &ele : nums1){
            result.push_back(hmap[ele]);
        }
        
        return result;
    
    }
};