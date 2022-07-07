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
    -> Remove Duplicates from Unsorted List
    */
    
    ListNode* deleteDuplicates(ListNode* head) {
        
         auto curr = head ; 
         auto prev = curr ;
       
      // Using set to check and remove duplicates
       set<int> s ;
       
       while(curr){
           // If an element is alredy present
           if(s.count(curr -> val)){
                prev -> next = curr -> next ;
                delete curr ;
           }
           // First time element is coming
           else{
               s.insert(curr -> val) ;
               prev = curr ; 
           }
           
           // not using curr->next as we are deleting current 
           curr = prev -> next ;
       }
       
       return head ;
        
    }
};