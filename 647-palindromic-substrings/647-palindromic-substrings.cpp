class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        int res = 0 ;
        int left = 0 , right = 0 ;
        
        //For odd length palindromes : a , a<-a->a , , a<-a<-a->a->a etc...
        for(int i= 0;i<n ;i++){
            left = right = i ;
            while(left >=0 && right<n && s[left]==s[right]){
                left--;
                right++;
                res++;
            }
        }
        
         //For even length palindromes  : a<->a , a<-a<->a->a etc...
        for(int i= 0;i<n ;i++){
            left =  i ;
            right = i+1 ;
            while(left >=0 && right<n && s[left]==s[right]){
                left--;
                right++;
                res++;
            }
        }
        
        return res ; 
    }
};