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
    public int solve(String s){
        int n = s.length();
        int x = 1;
        int res = 0;
        for(int i=n-1;i>=0;i--){
            int a = 1;
            if(s.charAt(i)=='1'){
                a*=x;
                res+=a;
            }
            
            // System.out.print(res+"*");
            x*=2;
        }
        return res;
    }
    public int getDecimalValue(ListNode head) {
        String s = new String("");
        ListNode temp = head;
        while(temp!=null){
            s+=temp.val;
            temp=temp.next;
        }
        int ans = solve(s);
        return ans;
    }
}