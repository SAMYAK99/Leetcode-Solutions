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
public:
   
    // Reverse a Linked List
    ListNode* reverse(ListNode* ptr) {
    ListNode* pre=NULL;
    ListNode* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
     return pre;
  }
    
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* fast = head ; 
        ListNode* slow = head ; 
        
        // If Head is null or contains 1 element
        if(head==NULL||head->next==NULL)
            return true;
     
        
    // Finding the middle of the linked list
     while(fast->next!=NULL&&fast->next->next!=NULL) {
         slow = slow->next;
         fast = fast->next->next;
     }
        
     // Reverse the next half of the linked list   
     slow->next = reverse(slow->next);
        
     // Move middle to one step ahead   
     slow = slow->next;
     ListNode* dummy = head;
        
     // keep on comparing start and middle+1    
     while(slow!=NULL) {
         if(dummy->val != slow->val)
             return false;
         
         dummy = dummy->next;
         slow = slow->next;
     }
        
     return true;   
        
    }
};