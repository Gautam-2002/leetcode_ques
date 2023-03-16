/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1==null)return list2;
        if(list2==null)return list1;
        ListNode head=null;
        ListNode tail=null;

        while(list1!=null && list2!=null){
            if(list1.val<=list2.val){
                if(head==null){
                    head=list1;
                    tail=list1;
                    list1=list1.next;
                }
                else{
                    tail.next=list1;
                    tail=list1;
                    list1=list1.next;
                }
            }
            else{
                if(head==null){
                    head=list2;
                    tail=list2;
                    list2=list2.next;
                }
                else{
                    tail.next=list2;
                    tail=list2;
                    list2=list2.next;
                }
            }
        }
        if(list1!=null)tail.next=list1;
        if(list2!=null)tail.next=list2;

        return head;
    }
    public ListNode middleNode(ListNode head) {
        if(head==null || head.next==null)return head;
        ListNode slow=head;
        ListNode fast=head.next;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    public ListNode sortList(ListNode head) {
        if(head==null || head.next==null)return head;
        
        ListNode mid = middleNode(head);
        ListNode headb = mid.next;
        mid.next=null;
        ListNode a = sortList(head);
        ListNode b = sortList(headb);

        ListNode ans = mergeTwoLists(a,b);
        return ans;
    }
}