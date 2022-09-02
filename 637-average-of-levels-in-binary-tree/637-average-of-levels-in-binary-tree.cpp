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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        
         if(!root)
            return  ans;
        
        
        queue<TreeNode*> q;
        q.push(root);
        
        double tmp = 0 ; 
        int cnt = 0 ;
        while(!q.empty()){
            int currsize = q.size(); 
			 cnt = currsize ; 
            
              while(currsize > 0){
                  
                  auto t = q.front();
                  tmp += t->val;
                  currsize--;
                  q.pop();
            
                  if(t->left != NULL)
                    q.push(t->left);
                  if(t->right != NULL)
                    q.push(t->right) ;
                  
              }
            
            ans.push_back(tmp/cnt) ; 
            tmp = 0 ; 
        }
        
        return ans ; 
        
    }
};