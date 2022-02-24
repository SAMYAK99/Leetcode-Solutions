class Solution {
public:
    vector<long long> maximumEvenSplit(long long n) {
        
          vector<long long>  ans ;
          
        
           if(n % 2 != 0 )
               return ans ; 
        
          long long  tmp = 0 ; 
        
          for(long long  i=2 ;i<=n ;i+=2){
              tmp+=i;
              ans.push_back(i);
              if(tmp >= n)
                  break;
          }
        
        long long rem = tmp - n  ; 
        
        ans.erase(remove(ans.begin(), ans.end(), rem), ans.end());
        
        return ans ; 
        
        
        
    }
};