class Solution {
public:
    
    /*
    Use of k : We can utilize our egg again if it does not break
    To Find : Minimum no. of attemepts in Worst Case(maxm)
    
    
    Optimized : 
    Binary Search(1-k-1) + Brute Force(on remaining)
    */
    
     /*
        Here we have k eggs and n floor
        if we drop from i  (i=1 to n):
         i) egg break , now we remain k-1 eggs and i-1 floor beacase after
            i floor all the eggs will also break
        ii) egg not break , now we remain k eggs and n-i floor because 
            before i (included) all eggs will be remain
      */
    

    
    // Memoization with Optimization : 
    // We will use binary search instead linear serach 
    
    //Time: O(n*k*logn), Space: O(n*k)
    int solve(int k, int n, vector<vector<int>>& memo){
        if(n == 0 || n == 1) return n;  //if no. of floor 0 , 1 return n:
        if(k == 1) return n;               // if 1 egg return number of floo
        
        if(memo[k][n] != -1) 
            return memo[k][n];
        
        int mn = INT_MAX, low = 0, high = n, temp = 0;
        
        while(low<=high){
            
            int mid = (low + high)/2;
            
            /*representing both the choices with memo
            First one, if the egg will break, no. of eggs will decreased and we have to
            down from that floor.
            Second one, if the egg will not break, no. of eggs will not decreased and we
            have to go above form that floor.*/
            
            int left = solve(k-1, mid-1, memo);
            int right = solve(k, n-mid, memo);
            
            temp = 1 + max(left, right);
            
            //since we need more temp value in worst case, so need to go above
            if(left < right) 
                low = mid+1;
            else 
                high = mid-1;     //move to the downward
    
            mn = min(mn, temp); //minimum number of attempts
        }
        return memo[k][n] = mn;
       
    }
    
    int superEggDrop(int k, int n) {
        
       vector<vector<int>> memo(k+1 , vector<int> (n+1 ,-1)); 
       return solve(k,n,memo);
    }
};