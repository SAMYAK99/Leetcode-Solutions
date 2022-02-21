class Solution {
public:

    string getPermutation(int n, int k) {
        
        int fact = 1 ;
        vector<int> arr ; 
        
        // Computing all the factorials from 1 to n
        for(int i=1 ;i<n ;i++){
            fact = fact * i ; 
            arr.push_back(i) ; 
        }
        
        arr.push_back(n) ; 
        
        string ans = "";
        k-- ; 
        
         while(true) {
            // Calculating first index of permutation 
            ans = ans + to_string(arr[k / fact]); 
             
            // Removing the first index we find  
            arr.erase(arr.begin() + k / fact); 
             
            if(arr.size() == 0) {
                break; 
            }
             
            // Reducing the factorial 
            k = k % fact; 
            fact = fact / arr.size();
        }
        
        return ans; 
    }
};