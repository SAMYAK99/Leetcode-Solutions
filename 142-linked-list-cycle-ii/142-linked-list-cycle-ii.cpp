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
    ListNode *detectCycle(ListNode *head) {
        
        //Base Case
        if(head== NULL || head->next == NULL)
            return NULL; 
        
         ListNode* slow = head ;
         ListNode* fast =  head ;
        
         // Detecting loop in Linked list
         while(fast != NULL && fast->next!=NULL){
             slow = slow->next ;
             fast = fast->next->next ;
            
             // If loop is there
             if(slow == fast){
                 slow = head ; 
                 
                 // Keep looping until there next element is equal
                 while(slow != fast ){
                     slow = slow->next ;
                     fast = fast->next ; 
                 }
                 return fast;
             }
         }
        
        return NULL ;
        
    }
};