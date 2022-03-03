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
    -> Make root to the elements of preorder traversals
    -> Map for storing inorder elements with its particular range
    -> New root && First elemnt of pre will be our root
    */
    
    TreeNode* constructTree(vector<int>& preorder, unordered_map<int, int>&mp, int start, int end, int &prevIndex){
        
        // Base Case
        if(start>end)
            return NULL;
        
    
        TreeNode* root=new TreeNode(preorder[prevIndex]);
        
        int currIndex = mp[preorder[prevIndex]];
        prevIndex++;
        root->left=constructTree(preorder, mp, start, currIndex-1, prevIndex);
        root->right=constructTree(preorder, mp, currIndex+1, end, prevIndex);
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=preorder.size(), prevIndex=0;
        unordered_map<int, int>mp;
        
        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]]=i;
        
        return constructTree(preorder, mp, 0, n-1, prevIndex);
        
        
    }
};