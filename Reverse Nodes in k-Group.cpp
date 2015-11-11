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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ret=NULL, *pstart=NULL;
        while(head) {
            ListNode *prev=NULL, *start = head;
            
            auto tt=head;
            int cc = k;
            while(tt && cc){
                cc--;
                tt=tt->next;
            }
            if(cc){
                if(!ret) ret = head;
                else pstart->next = head;
                break;
            }
            
            int tk = k;
            while(head && tk--) {
                auto temp = head->next;
                head->next = prev;
                prev = head;
                head = temp;
            }
            if(!ret) ret = prev;
            else pstart->next = prev;
            pstart=start;
        }
        
        return ret;
    }
};
