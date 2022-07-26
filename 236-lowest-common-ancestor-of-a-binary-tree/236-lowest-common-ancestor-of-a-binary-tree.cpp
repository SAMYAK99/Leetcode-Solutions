/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        
        // Base Case
        if(root == NULL || root == p || root == q)
            return root;
        
        // Inorder Traversal
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        // If either p or q  is Found on traversal
        if(left == NULL)  
            return right;
        
        else if(right == NULL)
            return left;
        
        // If both p and q are found : both are non null
        else
            return root ; 
        
    }
};


  /*
  -> Complexity :-
     Time Complexity O(n)
     Space Complexity O(1)             
  */