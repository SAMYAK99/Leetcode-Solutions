//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str){
        
        int n = str.size();
        int dp[n][n]  = {0}; 
        
        // Partition the array with more than 1 gap ie, a|b , a|b|c etc...
        for(int gap = 1 ; gap<n ; gap++){
            // Filling the matrix diagonally from top to bottom
           for(int row = 0 ,col = gap ; row < n - gap ; row++ , col++){
              if(isPalindrome(str , row , col)){
                  dp[row][col] = 0 ;  // No need to make cut
              }
              else{
                   int mn = INT_MAX ;
                  for(int k=row ; k < col ; k++){
                      mn = min(mn , dp[row][k] + dp[k+1][col] + 1) ;
                  }
                  dp[row][col] = mn ;
              }
           }        
        }
        
        // Returning top right column
        return dp[0][n-1] ;
    }
    
    bool isPalindrome(string str , int i ,int j){
        while(i<j){
            if(str[i++] != str[j--])
            return false ;
        }
      return true ;    
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends