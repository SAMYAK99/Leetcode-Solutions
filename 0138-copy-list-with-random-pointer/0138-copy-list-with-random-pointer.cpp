/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    /*
    Roadblocks : We can't traverse the random pointers similary
    Hence we use a hashmap to get the link of next and random pointers
    */
    
    
    Node* copyRandomList(Node* head) {
        
       unordered_map<Node* , Node*> mp;
       Node* ptr = head ;
        
        // mapping the nodes and its copying values
        /*
        7 -> 7
        13 -> 13
        */
        
        while(ptr){
            mp[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        
        ptr = head ;
        
        /*
        Making connection of nodes of next and random pointers
         random[b] -> d
         mp[random[b]] -> mp[d]
        */
        
        while(ptr){
            // mp[ptr] : copy of ptr
            // making the connections of copy of ptr -> ptr
            mp[ptr] -> next = mp[ptr->next];
            mp[ptr] -> random = mp[ptr->random];
            ptr = ptr->next;
        }
        
        return mp[head] ; 
    }
};