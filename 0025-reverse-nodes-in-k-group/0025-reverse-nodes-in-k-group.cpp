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
    
    int lengthOfLL (ListNode* head){
        
        int cnt = 0 ;
        ListNode* tmp = head ;
        while(tmp != NULL){
            tmp = tmp -> next ;
            cnt ++ ;
        }
        
        return cnt ;
    }
    
    ListNode* reverseLL(ListNode* head , int k , int length){
        
        // Base Case
        if(length < k)
            return head;
        
        ListNode* prev = NULL;
        ListNode* nex = head ;
        ListNode* curr = head ;
        
        int cnt = 0 ;
        
        // Reversing nth k nodes
        while(curr != NULL and cnt < k){
            nex = curr -> next ; 
            curr -> next = prev ;
            prev = curr ;
            curr = nex ;
            cnt++;
        }
        
        // If other k nodes left
        if(nex != NULL)
        head->next = reverseLL(nex , k , length - k);
        
        return prev ;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
    
        int len = lengthOfLL(head);
        
        return reverseLL(head , k , len) ;
        
    }
};