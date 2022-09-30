class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
           vector<vector<int>> res ;
        
         for(int i= 0 ; i<intervals.size() ;i++){
             
             // If new interval is at the last : Ignore now and add it later
             if(intervals[i][1] < newInterval[0]){
                 res.push_back(intervals[i]) ;
              }
               
            // If the range of new Interval is at the start     
             else if(intervals[i][0] > newInterval[1]){
                 res.push_back(newInterval);
                 newInterval = intervals[i];
             }
                 
            // If new interval lies in the range of other intervals 
             else if(intervals[i][0] <= newInterval[1] || intervals[i][1] >= newInterval[0]){
                 newInterval[0] = min(intervals[i][0],newInterval[0]);
                 newInterval[1] = max(intervals[i][1],newInterval[1]);
             }
         }
        
        res.push_back(newInterval);
        
        return res ;
    }
};