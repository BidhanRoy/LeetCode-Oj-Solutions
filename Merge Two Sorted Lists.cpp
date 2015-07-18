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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        
        ListNode *ret = NULL, *head = NULL;
        
        while( l1 != NULL && l2 != NULL ) {
            if( l1->val < l2->val ) {
                if( ret == NULL ) ret = l1, head = l1;
                else ret->next = l1, ret = l1;
                l1 = l1->next;
            }
            else {
                if( ret == NULL ) ret = l2, head = l2;
                else ret->next = l2, ret = l2;
                l2 = l2->next;
            }
        }
        
        while( l1 != NULL ) {
            if( ret == NULL ) ret = l1 , head = l1;
            else ret->next = l1, ret = l1;
            l1 = l1->next;
        }
        
        while( l2 != NULL ) {
            if( ret == NULL ) ret = l2 , head = l2;
            else ret->next = l2, ret = l2;
            l2 = l2->next;
        }
        
        return head;
        
    }
};
