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
    
    /*
    Swapping 2 nodes is similar to reversing them
    Swap only first 2 nodes and rest recursion will swap them
    */
    
    ListNode* swapPairs(ListNode* head) {
     
        // Base case
        if(head == NULL)
            return NULL ;
        
        // Reversing 2 nodes
        ListNode* curr = head ;
        ListNode* prev = NULL ;
        ListNode* nex = NULL ;
        
        // Using a cnt counter to make sure only 2 nodes are swapped
        int cnt = 0 ;
        while(curr != NULL and cnt < 2){
            nex = curr -> next ;
            curr->next = prev ;
            prev = curr ;
            curr = nex;
            cnt++;
        }
        
        head->next = swapPairs(nex) ;
        
        // Previous will be pointing towards the new head
        return prev ; 
       
    }
};