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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(h1!=NULL && h2!=NULL){
            if(h1->val < h2->val){
                if(head==NULL){
                    head = h1;
                    tail = head;
                }
                else{
                    tail->next = h1;
                    tail=h1;
                }
                h1 = h1->next;
            }
            else{
                if(head==NULL){
                    head=h2;
                    tail=head;
                }
                else{
                    tail->next=h2;
                    tail=h2;
                }
                h2 = h2->next;
            }
        }
        if(h1!=NULL){
            tail->next = h1;
        }
        if(h2!=NULL){
            tail->next = h2;
        }
        return head;
    }
};