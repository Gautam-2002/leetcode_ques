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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        int idx=size-n;
        if(size==1 && n==1){
            // cout<<"11";
            delete head;
            return NULL;
        }
        if(n==size){
            // cout<<"n";
            ListNode* ans = head->next;
            delete head;
            return ans;
        }
        int i = 0;
        temp = head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            // cout<<"l";
            if(i==idx){
                // cout<<"while";
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
                return head;
            }
            i++;
            prev = temp;
            temp = temp->next;
        }
        // cout<<"d";
        return NULL;
    }
};