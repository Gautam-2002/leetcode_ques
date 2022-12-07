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
    
    public ListNode reverse(ListNode head){
        if(head==null || head.next==null)return head;
        ListNode prev = null;
        ListNode curr = head;
        while(curr != null){
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    
    public ListNode add(ListNode h1, ListNode h2){
        ListNode head = new ListNode(-1);
        ListNode tail = head;
        
        if(h1==null && h2 == null)return head;
        
        int c = 0;
        
        while(h1!=null || h2!=null || c!=0){
            int val1=0,val2=0;
            
            if(h1!=null)val1 = h1.val;
            if(h2!=null)val2 = h2.val;
            
            int sum = val1 + val2 + c;
            int dig = sum%10;
            
            tail.next = new ListNode(dig);
            tail=tail.next;
            
            c = sum/10;
            if(h1!=null)h1 = h1.next;
            if(h2!=null)h2 = h2.next;
            display(head.next);
        }
        return head.next;
    }
    
    public void display(ListNode head){
        ListNode temp = head;
        while(temp!=null){
            System.out.print(temp.val);
            System.out.print('-');
            temp = temp.next;
        }
        System.out.println();
    }
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // ListNode h1 = reverse(l1);
        // ListNode h2 = reverse(l2);
        
        ListNode ans = add(l1,l2);
        display(ans);
        // ans = reverse(ans);
        display(ans);
        return ans;        
    }
}