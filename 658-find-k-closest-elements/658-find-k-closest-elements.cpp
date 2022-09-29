class Solution {
public:
    
    /*
    Brute Force : Use max Heap
    2 Pointer apprach
    */
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
          vector<int>  ans ;
         
        int i=0 , j = arr.size()-1;
        
        /*
        Closest elements will be consecutive
        */
        
        while(j-i >= k){
            if(x-arr[i] <= arr[j] - x)
                j--;
            else
                i++;
        }
        
        for( ; i<=j ; i++){
            ans.push_back(arr[i]);
        }
        
        return ans ;
       
    }
};