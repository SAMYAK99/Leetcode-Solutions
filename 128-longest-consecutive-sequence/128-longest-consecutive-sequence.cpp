class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    
       unordered_set<int> hashSet ;
        for(auto it : nums)
            hashSet.insert(it);
        
        int longestStreak = 0 ;
        for(int num : nums){
            
            // If a number lesser than current exist in the set or not ? 
            if(!hashSet.count(num-1)){
                int currentNum = num;
                int currentStreak = 1 ;
                
                // checking if next number exist or not
                while(hashSet.count(currentNum+1)){
                    currentNum++;
                    currentStreak++;
                }
                
                longestStreak = max(longestStreak,currentStreak);
            }
        }
        
        return longestStreak ;
        
    }
};