/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
 Follow the path as per binary search tree and if both nodes  can't decide where to go (split : one left and other right) then that will be our answer
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
     // Base Case
      if (!root)
            return NULL;
        
        int curr = root->val ; 
		if (p->val < curr  && q->val < curr)
            return lowestCommonAncestor(root->left, p, q);
        
		else if (p->val > curr && q->val > curr)
            return lowestCommonAncestor(root->right, p, q);
	
        
        //In Divergence : One smaller and other Greater
        return root ; 
      
    }
};

/*
Time Complexity : O(h)
Space Complexity : O(1)
*/