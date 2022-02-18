class Solution {
public:
    
    // Primary Task : Partioning
    
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans ; 
        // for storing individual list of substrings
        vector<string> path  ;
        findPartition(ans , s , path , 0);
        
        return ans ; 
        
    }
    
    void  findPartition( vector<vector<string>> &ans , string s , vector<string> path , int index ){
        
        // Base case : If we reaches at the end of the string
         if(index == s.size()){
             ans.push_back(path) ; 
             return  ; 
         }
        
        // Recursive Case : Looping to whole string to find partition 
        for(int i = index ; i<s.size() ; i++){
            if(isPalindrome(s , index , i)){
                path.push_back(s.substr(index, i - index + 1)) ;
                
             // Recursion : move to next index 
                 findPartition(ans,s,path,i+1);
            
            // remove  the last element as it is passed by the reference
            path.pop_back() ; 
                
            }
        }
    }
    
    
    
    
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    
};