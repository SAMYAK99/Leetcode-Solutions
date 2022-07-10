class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Brute Force : Combined both array an find medians
        
        int n = nums1.size() ;
        int m = nums2.size();
        
        int size = n+m ;
        int arr[size+1] ; 
        int l = 0 ,i=0,j=0 ;
        
        while(i<n && j<m){
            if(nums1[i] <= nums2[j]){
                arr[l++] = nums1[i++];
            }
            else{
                arr[l++] = nums2[j++];
            }
        }
        
        if(i<n){
            while(i<n)
                arr[l++] = nums1[i++];
        }
        
        if(j<m){
            while(j<m)
                arr[l++] = nums2[j++];
        }
        
        if(size % 2 == 0)
           return double (arr[(size/2) - 1]  + arr[size/2]) / 2 ;
        else
           return arr[size/2];
    }
};