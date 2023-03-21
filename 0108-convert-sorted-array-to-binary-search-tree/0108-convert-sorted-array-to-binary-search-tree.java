/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode solve(int[] nums,int s,int e){
        if(s>e)return null;
        
        int mid = s+(e-s)/2;
        TreeNode lft = solve(nums,s,mid-1);
        
        TreeNode root = new TreeNode(nums[mid]);
        root.left = lft;
        
        TreeNode right = solve(nums,mid+1,e);
        root.right = right;
        
        return root;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        return solve(nums,0,nums.length-1);
    }
}