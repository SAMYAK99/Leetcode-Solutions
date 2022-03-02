class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n = t.size() ;
        int k =0 ;
        
        
        if(s.size() == 0)
            return true ;
        
        if(t.size() == 0)
            return false ; 
        
        for(int i=0 ;i<n ;i++){
            if(t[i] == s[k])
                k++;
            
            if(k == s.size())
                return true ; 
        }
        
        return false ; 
        
    }
};