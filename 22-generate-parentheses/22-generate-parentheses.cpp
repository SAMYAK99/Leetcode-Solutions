class Solution {
public:
    
    /*
    Condition for balanced parenthesis
    * closing count < opening count
    * opening count < n
    * oc : opening count | cc : closing count
    */
    
    void helper(vector<string> &ans , int n , int oc , int cc , string s){
        
        // Base case
        if(oc == n and cc == n){
            ans.push_back(s);
            return ;
        }
        
        if(oc < n)
            helper(ans,n,oc+1,cc,s+"(");
        
        if(cc < oc)
            helper(ans,n,oc,cc+1,s+")");
        
    }
    
    vector<string> generateParenthesis(int n) {
     
         vector<string> ans ; 
         int oc = 0 , cc = 0 ;
         helper(ans,n,oc,cc,"");
        
        return ans ; 
        
    }
};