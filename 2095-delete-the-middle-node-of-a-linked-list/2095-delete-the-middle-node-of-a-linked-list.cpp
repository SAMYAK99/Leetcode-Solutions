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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next == NULL)
            return NULL ; 
        
        // sp : slowPointer
        // fp : fastPointer
        
        auto sp = head ;
        auto fp = head ;
        auto prev = sp ;
        
        while(fp != NULL && fp->next != NULL){
            prev = sp ;
            sp = sp -> next ;
            fp = fp -> next -> next ; 
        }
        
        // connecting prev and next node 
        prev -> next = sp -> next ; 
        delete sp ; 
        
        return head ;
        
        
    }
};