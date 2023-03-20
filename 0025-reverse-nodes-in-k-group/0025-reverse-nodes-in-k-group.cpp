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
    ListNode* rev(ListNode* head,ListNode* kplus1){
        ListNode* prev=NULL;
        ListNode* curr= head;
        while(curr!=kplus1){
            ListNode* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)return NULL;
        ListNode* temp = head;
        for(int i = 0;i<k;i++){
            if(temp==NULL)
                return head;
            temp= temp->next;
        }
        ListNode* ans = rev(head,temp);
        head->next = reverseKGroup(temp,k);
        return ans;
        
    }
};