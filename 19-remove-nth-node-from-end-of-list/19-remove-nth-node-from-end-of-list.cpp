/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    /*
     between the fast and slow pointers, there is a gap of n nodes. Now, just Iterate and increment both the pointers till fast reaches the last node. The gap between fast and slow is still of n nodes, meaning that slow is nth node from the last node (which currently is fast).
    */
    
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
     auto slow = head , fast = head ; 
        
        // Placing fast pointer to nth pos from start
        while(n--)
            fast = fast -> next ;
        
        // if fast is already null, it means we have to delete 
        // head itself. So, just return next of head
        if(fast == NULL)
             return head->next;
        
        // iterate till fast reaches the last node of list
        while(fast->next != NULL){
            fast = fast-> next;
            slow = slow -> next ;
        }
        
        // Remove nth node from last
        slow->next = slow->next->next;
        
        return head ;
            
    }
};