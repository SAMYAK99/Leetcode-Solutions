class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
         vector<string> ans ; 
        
         string tmp = "" ; 
        
        for(int i=1 ; i<=n ;i++){
             tmp = "" ; 
            
            if(i%3 == 0)  tmp += "Fizz" ;
            if(i%5 == 0)  tmp += "Buzz" ;
            if(tmp == "") tmp += to_string(i);
            
            ans.push_back(tmp);
        }
        
        return ans ; 
        
    }
};