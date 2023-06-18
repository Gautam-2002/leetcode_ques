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
    ListNode* getMid(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL){
            slow=slow->next;
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
            }
        }
        return slow;
    }
    
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return NULL;
        }
        ListNode* toDel = getMid(head);
        ListNode* iterator = head;
        
        while(iterator->next != toDel){
            iterator = iterator->next;
        }
        iterator->next = toDel->next;
        delete toDel;
        return head;
    }
};