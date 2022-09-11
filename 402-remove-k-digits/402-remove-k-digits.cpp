class Solution {
public:
    
    /*
    
    Intution : Maintain the digits in sorted increasing order ie, a monotonic stack
    
     Use a stack that you keep sorted ascendingly. You remove elements from it as long as        you  can still make it to n - k digits,
     and your current element is smaller than the top of the stack 
    */
    
    string removeKdigits(string num, int k) {
        
        int n = num.size();
        stack<char> mystack;
        
        //Store the final string in stack
        for(char c: num){
            while(!mystack.empty() && k>0 && mystack.top()>c){
                mystack.pop();
                k-=1;   
            }
            
            if(!mystack.empty() || c!='0')
                mystack.push(c);
        }
        
        // EDGE CASES 
        
        // If stack contains all increasing elements : 1 2 3 4 and k is still not 0
        //Now remove the largest values from the top of the stack
        while(!mystack.empty() && k--){
            mystack.pop();
        }
        if(mystack.empty())
            return "0";
        
        //Now retrieve the number from stack into a string (reusing num)
        
        string ans ; 
        while(!mystack.empty()){
            ans += mystack.top();
            mystack.pop();
        }
        
        reverse(ans.begin(),ans.end()) ;
        return ans;
        
    }
};