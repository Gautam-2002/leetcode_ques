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
    ListNode* swapNodes(ListNode* head, int k) {
        int len = 0;
        ListNode* tmp = head;
        while(tmp!=NULL){
            len++;
            tmp=tmp->next;
        }
        int beg = 0, end = len;
        ListNode* x = NULL;
        ListNode* y = NULL;
        tmp = head;
        while(tmp!=NULL){
            if(++beg == k){
                x = tmp;
            }
            if(end-- == k){
                y = tmp;
            }
            if(x!=NULL && y!= NULL){
                break;
            }
            tmp = tmp->next;
        }
        int t = x->val;
        x->val = y->val;
        y->val = t;
        return head;
    }
};