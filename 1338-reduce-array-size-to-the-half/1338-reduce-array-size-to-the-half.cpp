class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n = arr.size();
        unordered_map<int,int>mp;
        
        for(int i=0 ;i<n ;i++){
            mp[arr[i]]++;
        }
        
        vector<int> freq;
        for(auto it : mp){
            freq.push_back(it.second);
        }
        
        sort(freq.begin(),freq.end(),greater<int>());
        int ans = 0 ;
        
        int target = n/2;
        for(int i=0 ; i<freq.size();i++){
            n -= freq[i];
            ans++;
            if(n <= target)
                break;
        }
        
        return ans;
    }
};