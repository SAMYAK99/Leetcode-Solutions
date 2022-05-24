class Solution {
public:
    // len = current Index - indexattop
    
    int longestValidParentheses(string s) {
        
        int ans = 0 ;
        
        stack<int> st;
        st.push(-1);      // if first char is )
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '(')
                st.push(i);
            else{
                st.pop();
                if(st.empty()) {
                    st.push(i);
                }
                else{
                    int len = i  - st.top() ;
                    ans = max(ans,len) ;
                }      
            }
        }
        
        
        return ans ; 
    }
};