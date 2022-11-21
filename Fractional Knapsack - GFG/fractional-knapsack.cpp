//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    // Comparator Function for Sorting
    static bool compare(Item a, Item b){
        double r1 = double(a.value) / double(a.weight) ; 
        double r2 = double(b.value) / double(b.weight) ; 
        
        return r1 > r2 ; 
    }
    
    double fractionalKnapsack(int W, Item arr[], int n){
        
        double ans = 0.0 ;
        
        // Sorting acc. to Value by Weight Ratio grredly
        sort(arr,arr+n,compare);
        
        int currentWeight = 0 ; 
        
        for(int i=0 ; i<n ;i++){
            if(currentWeight + arr[i].weight <= W){
                currentWeight += arr[i].weight ;
                ans += arr[i].value;
            }
            else{
                int remWeight = W - currentWeight ;
                ans +=  ((double) remWeight) / ((double)arr[i].weight) * (double(arr[i].value))  ;
                break;
            }
        }
        
        return ans ;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends