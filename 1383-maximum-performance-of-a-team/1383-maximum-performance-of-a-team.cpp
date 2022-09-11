class Solution {
public:

    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
      
        
        // storing {efficiency,speed} in vector of pairs
        vector<pair<int,int>> vpp ;
        for(int i=0 ;i<n ;i++){
            vpp.push_back({efficiency[i],speed[i]});
        }
        
        // sorting as per effecniency
        sort(vpp.begin(),vpp.end());
        
        // min heap for stroing at max k elements
        priority_queue<int,vector<int>,greater<int>> pq ; 
        
        long ans = 0 ; 
        long sum = 0 ; 
        
        // Traversing back from the greater effeciency
        for(int i=n-1 ;i>=0 ;i--){
           sum += vpp[i].second ;
            
            pq.push(vpp[i].second);
            
            // keeping at max k elements
            if(pq.size() > k) {
                sum-=pq.top() ;
                 pq.pop();
            }
            
            // vpp[i].first will always contains minimum as it is sorted in increasing order
            ans = max ( ans , (sum * vpp[i].first)) ; 
        }
        
       
        return ans%1000000007 ; 
        
        
    }
};