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
    ListNode* partition(ListNode* head, int x) {
        
        // 2 seprate list for containing value lesser than x and value grteater than x
         ListNode node1(0), node2(0);
        
        // p1 , p2 will point to head of node1 and node2 resp
        ListNode *p1 = &node1, *p2 = &node2;
        
    while (head) {
        if (head->val < x){
            p1->next = head;
            p1 = p1 -> next ; 
        }
        else{
            p2->next = head;
            p2 = p2 -> next ;
        }
        head = head->next;
    }
        
    p2->next = NULL; // 2 nd list ponited to null
    p1->next = node2.next; // connecting pointer of 1st list to the start of new list
        
    return node1.next;
    }
};