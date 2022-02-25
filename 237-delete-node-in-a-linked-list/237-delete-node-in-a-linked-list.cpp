/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        // copying the next value in current node
        node->val = node->next->val;
        
        // Deleting the current node link  
	    node->next = node->next->next;
        
    }
};