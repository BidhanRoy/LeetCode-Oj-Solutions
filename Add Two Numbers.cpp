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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if( l2 && !l1 ) l1 = new ListNode(0);
        ListNode *ret = l1;
        int carry = 0;
        while( l1 ) {
            
            if( l1 && l2 ) {
                
                int now = l1->val + l2->val + carry;
                carry = now / 10;
                now %= 10;
                
                l1->val = now;
                
                if( !l1->next && (carry || l2->next) ) l1->next = new ListNode(0);
                
                l1 = l1->next;
                l2 = l2->next;
            }
            else if( l1 ) {
                
                int now = l1->val + carry;
                carry = now / 10;
                now %= 10;
                
                l1->val = now;
                
                if( !l1->next && carry ) l1->next = new ListNode(0);
                l1 = l1->next;
            }
            
        }
        
        return ret;
    }
};
