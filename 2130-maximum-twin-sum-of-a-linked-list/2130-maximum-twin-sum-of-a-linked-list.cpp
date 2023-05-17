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
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* head0 = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return head0;
    }
    
    int pairSum(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return 0;
        ListNode* mid = getMid(head);
        ListNode* h1 = mid;
        ListNode* p1=head;
        ListNode* p2=reverse(h1);
        int maxTwin = 0;
        while(p1!=NULL && p2 !=NULL){
            int sum = p1->val + p2->val;
            if(maxTwin < sum)
                maxTwin = sum;
            p1=p1->next;
            p2=p2->next;
        }
        return maxTwin;        
    }
};