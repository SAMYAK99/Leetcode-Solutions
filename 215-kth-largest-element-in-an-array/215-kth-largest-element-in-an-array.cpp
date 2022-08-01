class Solution {
public:
    
    /*
    Time : O(nlogk)
    Space : O(1)
    */
    
    int findKthLargest(vector<int>& nums, int k) {
        
         
    // Implement min heap
    priority_queue<int> pq;
        for(int i= 0; i<nums.size() ;i++){
            pq.push(nums[i]);
        }
        
      
        int val ; 
        while(k--){
            val = pq.top();
            // cout << pq.top() << " " ;
            pq.pop() ;
        }
        
        return val;
    }
};