class Solution {
public:
    
    /*
    If a reminder repeats 2nd time then it should put in the bracket 
    Otherwise continue dividing with same denominator 
    until we find a repeting remider
    
    Insert length , rem in the map 
    */
    
    
    string fractionToDecimal(int num, int den) {
        
      if(!num)
          return "0";
        
       string ans = "";
       
        // Adding negatives : either num or den will be 0
        if(num > 0 ^ den > 0)
            ans += "-";
        
      long n =  num = abs(num) ; 
      long d =  den = abs(den) ;
        
        ans += to_string(n/d);
        long rem = n % d ;
        
        if(!rem){
            return ans;
        }
        
        ans += "." ;
       
            
            unordered_map<long,int> mp ;
        
        while(rem){
            // If a digit is repeated
            if(mp.find(rem) != mp.end()){
                ans.insert(mp[rem] , "(" );
                ans += ")" ;
                break ;
            }
            
            mp[rem] = ans.size();
            rem *= 10 ;
            ans += to_string(rem / d);
            rem %= d;
            
        }
        
        return ans ;
        
    }
};