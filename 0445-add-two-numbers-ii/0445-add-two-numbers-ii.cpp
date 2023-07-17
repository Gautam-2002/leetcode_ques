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
    ListNode* rev(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = rev(l1);
        ListNode* h2 = rev(l2);
        
        ListNode* ans = new ListNode(-1);
        ListNode* tail = ans;
        
        ListNode *t1=h1;
        ListNode *t2 = h2;
        
        int sum=0 , carry=0;
        
        while(t1!=NULL && t2!=NULL){
            sum = t1->val + t2->val + carry;
            carry = sum/10;
            
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            
            t1 = t1->next;
            t2 = t2->next;
            
        }
        while(t1!=NULL){
            sum = t1->val + carry;
            carry = sum/10;
            
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            
            t1 = t1->next;
        }
        while(t2!=NULL){
            sum = t2->val + carry;
            carry = sum/10;
            
            tail->next = new ListNode(sum%10);
            tail = tail->next;

            t2 = t2->next;
        }
        if(carry != 0){
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        ListNode* res = ans->next;
        delete ans;
        
        return rev(res);
    }
};