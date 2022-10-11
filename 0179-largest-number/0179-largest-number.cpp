class Solution {
public:
    
   
    static bool comp (string s1 , string s2){
        
      string first = s1 + s2 ;
      string second = s2 + s1 ;
        
        int i =0 ;
        
        while(first[i] and second[i]){
            if(first[i] > second[i])
                return true;
            else if(second[i] > first[i])
                return false;
            
            i++;
        }
        
        return false; 
         
    }
    
    string largestNumber(vector<int>& nums) {
        
       int n = nums.size(); 
       vector<string> num;
        
        for(int i=0 ; i<n ;i++)
            num.push_back(to_string(nums[i]));
        
        sort(num.begin(),num.end(),comp);
        
        string ans ;
        
        int flag = -1; 
        
      
        
        for(int i=0 ; i<n ;i++){
            ans += num[i];
            if(num[i] != "0")
                flag = 1;
        }
        
        if(flag == -1)
            return "0";
        else
            return ans ;
        
    }
};