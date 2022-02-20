class Solution {
public:
    
    bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b){
    return (a.second < b.second);
}
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
         vector<vector<int>> ans ;
          vector<pair<int , int> >  dist ; 
          int n = points.size() ;
        
          for(int i=0 ;i<n ; i++){
              int tmp = 0 ; 
              for(int j=0 ;j<2 ;j++){
               tmp += points[i][j]*points[i][j] ; 
             }
              dist.push_back({tmp , i}) ; 
          }
        
       sort(dist.begin(), dist.end());
        
        for(int i=0 ; i<k ;i++){
            int idx = dist[i].second ; 
            vector<int> tmp ;
             tmp.push_back(points[idx][0]) ; 
            tmp.push_back(points[idx][1]) ; 
            // cout << tmp[i]<< endl ;
            ans.push_back(tmp) ;  
            // cout << endl ;
        }
        
        return ans ; 
        
    }
};