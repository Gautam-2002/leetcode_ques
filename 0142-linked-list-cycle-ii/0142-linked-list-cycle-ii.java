/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head==null || head.next==null)return null;
        ListNode slow = head;
        ListNode fast = head;
        while(fast!=null && slow!=null){
            slow=slow.next;
            fast=fast.next;
            if(fast!=null)
                fast=fast.next;
            if(slow==fast)
                break;
        }
        if(slow==null || fast==null)
            return null;
        if(fast==head && slow==head)
            return head;
        slow=head;
        while(slow.next!=fast.next){
            slow=slow.next;
            fast=fast.next;
        }
        return slow.next;
    }
}