/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    /*
    -> Key is to put the use the middle element of the sorted array as the root node
    */
    
    TreeNode* buildBST (vector<int> arr , int start , int end ){
        
        if(start > end)
            return NULL ;
        
        int mid  = (start + end ) / 2 ;
        
        // Inserting a new value to the root with the constructor
        TreeNode* root = new TreeNode(arr[mid]);
        
        root->left =  buildBST(arr , start , mid-1) ; 
        root->right =  buildBST(arr , mid+1 , end) ; 
        
        return root ;
        
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
       TreeNode* tree ; 
       tree =  buildBST(nums , 0 , nums.size()-1) ; 
        
        return tree ; 
        
    }
};