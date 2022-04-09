class Solution {
public:
    
  static bool sortbysecdesc(const pair<int,int> &a,
                   const pair<int,int> &b){
       return a.second>b.second;
}
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans ; 
        map<int,int> mp; 
        
        for(int i=0 ;i<nums.size();i++)
            mp[nums[i]]++; 
    
        vector<pair<int,int>> vpp ;
        
        for(auto m : mp){
           vpp.push_back({m.first,m.second});
        }
        
        sort(vpp.begin(),vpp.end(),sortbysecdesc);
    
        
        for(auto it = vpp.begin() ; it!= vpp.end() ;it++){
            ans.push_back(it->first);
            if(ans.size() == k)
                break ; 
        }
            
        return ans ;
    }
};