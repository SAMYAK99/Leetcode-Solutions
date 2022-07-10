class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
       /*
        Ideally, every even index should contain the first occurrence of the element and odd index should contain the second occurrence of the previous identical element. If there is an element in the array(with no duplicate) that means there will be distortion in this behavior in some part of the array. The distortion will start from the index where the single element element occurs. Use Binary search to check if the middle element follows the ideal behavior. If yes then the single element occurs to the right of the middle element. If not, it means that the single element lies to the left of the middle index. That’s how we reduce the search space.
       
       */
        
        
        int high = nums.size()-1;
        int low = 0;
        int mid;
        
        //Boundary cases : If first or last element is unique element
        if(high==0)
            return nums[0];
        else if(nums[0]!=nums[1])
            return nums[0];
        else if(nums[high]!=nums[high-1])
            return nums[high];

        // Binary Search
        while(low<=high)
        {
            mid = low + (high-low)/2;
            //Unique element condition
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                return nums[mid];
            
            // Ideally because first number starts with even index and next with odd index
            if(((mid%2)==0 && nums[mid]==nums[mid+1])
               ||  ((mid%2)==1 && nums[mid]==nums[mid-1]))
                low = mid+1;
            else
                high = mid-1;
            
        }
        return -1;
    }
};