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
    bool hasCycle(ListNode *head) {
        
        if( !head ) return false;
        
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        if( !p2->next || !p2->next->next ) return false;
        
        p2 = p2->next->next;
        
        while( p1 != p2 ) {
            if( !p1->next ) return false;
            p1 = p1->next;
            if( !p2->next || !p2->next->next ) return false;
            p2 = p2->next->next;
        }
        
        return true;
    }
};
