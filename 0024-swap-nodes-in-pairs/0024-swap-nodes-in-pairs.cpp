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
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmp = head;
        while(tmp!=NULL){
            if(tmp->next!=NULL){
                swap(tmp->val,tmp->next->val);
                if(tmp->next->next!=NULL){
                    tmp = tmp->next->next;
                }
                else{
                    break;
                }
            } 
            else{
                break;
            }
        }
        return head;
    }
};