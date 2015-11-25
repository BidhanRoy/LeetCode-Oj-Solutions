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
    ListNode* swapPairs(ListNode* head) {
        ListNode* ret=(head && head->next)?head->next:head, *prev=NULL;
        
        while(head && head->next){
            ListNode* nextV=head->next;
            if(prev)
                prev->next=nextV;
            head->next=nextV->next;
            nextV->next=head;
            prev=head;
            head=head->next;
        }
        
        return ret;
    }
};
