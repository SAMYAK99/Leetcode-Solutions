class Solution {
public:
    
    vector<string> ans ; 
    unordered_set<string> st;
    
    
    void dfsHelper(string s ,string curr, int i){
        
        // If we reach at the end of the string
        if( i == s.size()){
            // remove extra space from back
            curr.pop_back() ;
            ans.push_back(curr);
        }
        
        
        for(int j = i ; j<s.size() ;j++){
            // Extracting current string characters one by one
            // substr(length , position) : similar to tmp += s[j]
             string tmp = s.substr(i , j-i+1)  ;          
            
            if(st.find(tmp) != st.end()){
                dfsHelper(s , curr + tmp + " " , j+1);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    
         for(auto it : wordDict)
             st.insert(it);
        
        string curr = "" ;
        dfsHelper(s , curr ,0);
        
        return ans ;
    }
};