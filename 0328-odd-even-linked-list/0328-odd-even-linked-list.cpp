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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1);
        ListNode* even = new ListNode(-1);
        ListNode* oddHead = odd;
        ListNode* evenHead = even;
        
        ListNode* iterator = head;
        
        int num = 1;
        
        while(iterator != NULL){
            ListNode* toDel = iterator;
            if((num++) & 1){
                odd->next = new ListNode(iterator->val);
                odd = odd->next;
            }
            else{
                even->next = new ListNode(iterator->val);
                even = even->next;
            }
            iterator = iterator->next;
            delete toDel;
        }
        odd->next = evenHead->next;
        odd = oddHead->next;
        delete oddHead;
        
        return odd;
    }
};