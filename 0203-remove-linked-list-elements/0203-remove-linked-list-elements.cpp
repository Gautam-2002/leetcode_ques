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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return head;
        if(head->val==val){
            while(head!=NULL && head->val==val){
                ListNode* node = head;
                head=head->next;
                delete node;
            }
            if(head==NULL)return head;
        }
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->next!=NULL && temp->next->val==val){
                ListNode* node = temp->next;
                temp->next=node->next;
                delete node;
            }
            else
                temp=temp->next;
        }
        return head;
    }
};