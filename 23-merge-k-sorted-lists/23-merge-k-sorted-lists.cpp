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

  /*
     IDEA : Merge k sorted arrays using Min Heap
     time complexity: O(nlog2k)
     space complexity: O(k) (for using priority queue)
    */

//compare function for priority queue
class Compare{
public:
    bool operator() (const ListNode* n1, const ListNode* n2){
        return (n1->val) > (n2->val);
    }
};


class Solution {
public:
 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         
         if(lists.size() == 0)
             return NULL ;
        
        // min heap
        priority_queue<ListNode* , vector<ListNode*> , Compare> pq;
        
        // pushing every first charachter of all list in heap
        for(int i=0 ;i<lists.size();i++){
            if(lists[i] != NULL)
                pq.push(lists[i]);
        }
        
        // Storing Previous Pointer so we can connect previous and next node
        ListNode* prev = NULL ;
        ListNode* head = NULL ;
        
        // MIN HEAP
        while(!pq.empty()){
            
            ListNode* node = pq.top();
            pq.pop();
            
            // For the first pointer
            if(prev == NULL){
                head = node;
            }
            // for others
            else{
                prev->next = node;
            }
            
            
            prev = node;
            
            // Pushing other node of same LINKED_LIST in Heap
            if(node->next != NULL){
                pq.push(node->next);
            }
            
        }
        
        return head ; 
           
        
    }
};