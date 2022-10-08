class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int n = tokens.size();
        stack<long long> st; 
        int ans = 0 ; 
        
        
        for(int i=0 ;i<n ;i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
            long long nums = stoi(tokens[i]) ;
              st.push(nums);
            }
            else {
                long  n1 = 0 , n2 = 0 ;
                if(!st.empty()){
                  n2 = st.top();
                  st.pop();
                }
                if(!st.empty()){
                   n1 = st.top();
                   st.pop();
                }
               
                  if(tokens[i] == "+")  st.push(n1+n2);
                  else  if(tokens[i] == "-") st.push(n1-n2);
                  else  if(tokens[i] == "*") st.push(n1*n2);
                  else  if(tokens[i] == "/" and n2!=0) st.push(n1/n2);
                
            }
            
        }
        
        return st.top() ; 
        
    }
};