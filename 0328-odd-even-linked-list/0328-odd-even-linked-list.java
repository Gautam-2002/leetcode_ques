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
    public ListNode oddEvenList(ListNode head) {
        ListNode temp = head;
        ArrayList<Integer> l1 = new ArrayList<Integer>();
        ArrayList<Integer> l2 = new ArrayList<Integer>();
        int j=0;
        while(temp!=null){
            if((j)%2==0){
                l1.add(temp.val);
            }
            if((j)%2!=0){
                l2.add(temp.val);
            }
            temp=temp.next;
            j++;
        }temp=head;
        for(int i=0;i<l1.size();i++){
            temp.val=l1.get(i);
            temp=temp.next;
        }
        for(int i=0;i<l2.size();i++){
            temp.val=l2.get(i);
            temp=temp.next;
        }
        return head;
    }
}