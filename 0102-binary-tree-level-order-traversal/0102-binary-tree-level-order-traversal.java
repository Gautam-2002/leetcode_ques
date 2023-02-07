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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if(root==null)return ans;
        List<Integer> lvl = new ArrayList<>();
        Queue<TreeNode> que = new LinkedList<>();
        que.add(root);
        que.add(null);
        while(!que.isEmpty()){
            TreeNode temp = que.peek();
            que.poll();
            
            if(temp==null){
                ans.add(lvl);
                lvl = new ArrayList<>();
                if(!que.isEmpty())
                que.add(null);
            }
            else{
                // System.out.print(temp.val+" * "+que.peek());
                lvl.add(temp.val);
                if(temp.left!=null)que.add(temp.left);
                if(temp.right!=null)que.add(temp.right);
            }
        }
        return ans;
    }
}