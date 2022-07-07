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
    -> We are going to sort the list with MERGE SORT
    -> First divide the array in 2 halves and find the middle element with fast & SLOW Pointers
     eg : 1 -> 3 -> 6 -> 2 -> 7 -> NULL
         h1 = 1 -> 3 -> NULL
         h2 = 6 -> 2 -> 7 -> NULL
         apply merge sort on h1 and h2
    */
    
    
    ListNode* merge(ListNode* h1 , ListNode* h2){
      
        // if either list is empty
        if(h1 == NULL)
            return h2 ;
        if(h2 == NULL)
            return h1 ;
        
        if(h1 -> val < h2 -> val){
            h1->next =  merge(h1->next,h2);
            return h1;
        }
        else{
            h2->next = merge(h1,h2->next);
            return h2;
        }
    }
    
    
    
    ListNode* sortList(ListNode* head) {
        
        //Base Case
        if(head == NULL || head->next == NULL)
            return head ;
        
        auto fast = head ;
        auto slow = head ;
        auto prev = slow ; // Used for dividing the linked list
        
        // Used for finding the middle point
        while(fast != NULL && fast->next != NULL){
          
            prev = slow ;
            slow = slow -> next ;
            fast = fast -> next -> next ;
        }
        
        prev->next  = NULL ; // seprating the first linked list from second one 
        auto h1 = sortList(head) ;
        auto h2 = sortList(slow) ;
        
        return merge(h1,h2);
        
    }
};