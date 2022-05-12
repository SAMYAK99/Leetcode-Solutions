class Solution {
public:
    
    void solve(vector<int>& nums , set<vector<int>>&s , vector<int> tmp){
        
        if(tmp.size() == nums.size()){
            s.insert(tmp);
            return ; 
        }
        
         for(int i=0;i<nums.size();i++){
            if(nums[i]!=11){            // check if the element is already included
                int j=nums[i];
                nums[i]=11;           // marking the current calls
                tmp.push_back(j);      // store it in the temporary vector
                solve(nums,s,tmp);  //recursively call to complete the permutations
                nums[i]=j;      // backtrack 
                tmp.pop_back();
            }
        }
    }
        
        
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans ; 
        set<vector<int>> s ; 
        
        solve(nums,s,{});
        
        for(auto i : s)
            ans.push_back(i);
        
        return ans ; 
    }
};