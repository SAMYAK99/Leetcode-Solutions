class Solution {
public:
    
     /*
     -> Variation of lcs
     -> Given string & reversed string
     -> [IMP] Just find lcs of given string and reverse string
     */
    
      int lcs(string &text1, string &text2,int m,int n,int memo[][1001]) {
        if(m==0 || n==0){
            return 0;
        }
        if(memo[m][n]!=-1){
            return memo[m][n];
        }
        if(text1[m-1]==text2[n-1]){
            return memo[m][n]= 1+lcs(text1,text2,m-1,n-1,memo);
        }else{
            return memo[m][n]= max(lcs(text1,text2,m-1,n,memo),lcs(text1,text2,m,n-1,memo));
        }
    }
    
    int longestPalindromeSubseq(string s) {
       
         string re = s ; 
         reverse(s.begin(),s.end());
        
        
          int m=s.size(),n= re.size();
        int memo[1001][1001];
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                memo[i][j]=-1;
            }
        }
        return lcs(re,s,m,n,memo);
    }
};