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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* cur1 = headA ;
        ListNode* cur2 = headB ;   
        
        while(cur1 != cur2){
            
           // Reverse the HEAD assignment 
            if(cur1 == NULL)
                cur1 = headB;
            else
                cur1 = cur1 -> next ;
           
           // Reverse the HEAD assignment 
            if(cur2 == NULL)
                cur2 = headA;
            else
                cur2 = cur2 -> next ;
            
        }
        
        return cur1 ; 
    }
};