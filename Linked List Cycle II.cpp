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
    ListNode *detectCycle(ListNode *head) {
        if( !head ) return NULL;
        
        auto a = head, b = head;
        
        if( !b->next || !b->next->next ) return NULL;
        
        b = b->next->next;
        a = a->next;
        
        while( a != b ) {
            a = a->next;
            if( !b->next || !b->next->next ) return NULL;
            b = b->next->next;
        }
        
        a = head;
        
        while( a != b ) {
            a = a->next;
            b = b->next;
        }
        
        return a;
    }
};
