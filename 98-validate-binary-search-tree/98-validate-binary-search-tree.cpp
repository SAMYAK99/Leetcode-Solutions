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
    * For every node we will give a particular range and if any element which doesn't lies
     int this range will not be a bst
    */
    
      // Checking the node values in a specific range 
    bool temp(TreeNode *root,TreeNode *l,TreeNode *r){
    
       if(root == NULL)
           return true ;
        
       if(l != NULL and root->val <= l->val)
           return false;
        
       if(r != NULL and root->val >= r->val)
           return false;
        
        return temp(root->left , l , root) and temp(root->right , root, r) ; 
    }
    
    
    bool isValidBST(TreeNode* root) {
        
        return temp(root , NULL ,NULL) ;
    }
};