//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	/*
	look after 2 conditions : 
	  increasing + maximum sum
	  arr[i] > arr[j]  +  dp[i] < dp[i] + arr[j]
	  
	
	*/	

	public:
	int maxSumIS(int arr[], int n)  {  
	   
	   if(n == 0)
	    return 0;
	   
	   if(n == 1)
	     return arr[0];
	     
	   // For keeping track of maximum sum  : maximum sum increasing sequ
	   vector<int> msis(n);
	   
	   // Intialization
	   for(int i=0 ;i<n ;i++)
	     msis[i] = arr[i] ;
	     
	   int ans = 0 ; 
	   
	   for(int i=1 ; i<n ;i++){
	       for(int j=0 ;j<i ;j++){
	           if(arr[i] > arr[j] and msis[i] < msis[j] + arr[i])
	             msis[i] = msis[j] + arr[i];
	       }
	   }
	   
	   ans = *max_element(msis.begin(),msis.end());
	   
	   //for(int  i=0 ;i<n ;i++)
	   //  cout << dp[i] << " ";
	   
	   return ans ; 
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends