/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        ListNode temp = node.next;
        int v = node.val;
        node.val = temp.val;
        temp.val = v;
        node.next = temp.next;
    }
}