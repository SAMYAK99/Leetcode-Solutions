class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0 ; 
        int high = nums.size()-1 ; 
        
        while(low < high){
            
            // If there is no rotation : array is sorted
            if(nums[low] < nums[high])
                return nums[low] ; 
            
            int  mid = ( low + high ) /2 ;
            
            // Case 2. The value in the middle of the list is greater than the leftmost and rightmost values in the list.
            
            if(nums[mid] > nums[high])
                low = mid + 1 ; 
            
            // Case 3. The value in the middle of the list is less than the leftmost and rightmost values in the list.
            
            else
                high = mid ; 
        }
        
        return nums[low] ; 
    }
};