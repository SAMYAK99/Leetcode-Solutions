class Solution {
public:
  int myAtoi(string s) {
   
      int n = s.size();
      if(n==0)
          return 0;
      
      int sign = 1;
      long ans = 0 ;
      int i = 0 ;
      
      // Traversing first i chrachters to avoid backspaces
      while(i<n && s[i] == ' '){
          i++;
      }
      
      // extracting the string after s charachters
       s = s.substr(i);
      
      if (s[0] == '-')
          sign = -1 ;
      
      // to avoid overflow 
      int MAX = INT_MAX, MIN = INT_MIN;
      
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;  
      
      while(i < n){
          if(s[0] == ' ' || !isdigit(s[i])) break;
            
            ans = ans * 10 + s[i]-'0';
            if(sign == -1 && -1*ans < MIN) return MIN;
            if(sign == 1 && ans > MAX) return MAX;
            
            i++;
      }
      
          return (int)(sign*ans);
      
  }
    
     private:
  bool isDigit(char ch){
    return ch >= '0' && ch <= '9';
  }
};