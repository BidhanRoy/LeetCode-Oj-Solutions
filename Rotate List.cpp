class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {

        if( head == NULL ) return head;

        int size = 0;

        ListNode *now = head;

        while( true ) {
            size++;
            if( now->next == NULL ) {
                now->next = head;
                break;
            }
            now = now->next;
        }

        k %= size;

        now = head;

        for( int i = 0; i < size - k - 1; i++ ) {
            now = now->next;
        }

        ListNode *ret = now;
        ret = ret->next;

        now->next = NULL;

        return ret;

    }
};
