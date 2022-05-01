class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
      
        
        stack<int> tmp1 , tmp2 ; 
        
        for(int i=0 ;i<s.size();i++){
            if(s[i] == '#' && !tmp1.empty())
                tmp1.pop();
            else if(s[i] != '#')
                tmp1.push(s[i]);
        }
        
         for(int i=0 ;i<t.size();i++){
            if(t[i] == '#' && !tmp2.empty())
                tmp2.pop();
            else if(t[i] != '#')
                tmp2.push(t[i]);
        }
        
       
        if(tmp1 == tmp2)
            return true;
        else
            return false ; 
        
    }
};