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
    Brute Force : O(n^2)
    Fix a node and move towards all the node in the tree

    Optimezed : Use a hashmap to store all freq with their count sum
    */
    
    long long total = 0 ; 
    map<long,long> mp ;
    
    
    int pathSum(TreeNode* root, int targetSum) {
        
        if(!root)
            return total;
        
        findPathSum(root,targetSum , 0);
      
        
        return total ;
        
    }
    
    void findPathSum(TreeNode *root , int targetSum ,long long currentSum){
        
        if(!root)
            return ;
        
         //Path sum from root
        currentSum += root->val ; 
        
        
        if(currentSum == targetSum)
            total++;
        
         //checking whether any target sum path present in the path from 
        // root to the current node
        if(mp.find(currentSum - targetSum) != mp.end())
            total +=   mp[currentSum - targetSum];
        
       mp[currentSum]++;
        
        findPathSum(root->left , targetSum , currentSum);
        findPathSum(root->right ,targetSum , currentSum);
        
        // After visiting the left and right subtree, we have to reduce this
        // path sum count from map since we are leaving this path
          mp[currentSum]--;
    }
};