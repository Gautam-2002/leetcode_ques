// /**
//  * Definition for a binary tree node.
//  * public class TreeNode {
//  *     int val;
//  *     TreeNode left;
//  *     TreeNode right;
//  *     TreeNode() {}
//  *     TreeNode(int val) { this.val = val; }
//  *     TreeNode(int val, TreeNode left, TreeNode right) {
//  *         this.val = val;
//  *         this.left = left;
//  *         this.right = right;
//  *     }
//  * }
//  */
// class Solution {
//     public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
//         List<List<Integer>> ans = new ArrayList<List<Integer>>();
//         if(root==null)return ans;
//         Queue<TreeNode> q = new LinkedList<TreeNode>();
//         q.add(root);
//         boolean lr = true;
//         while(!q.isEmpty()){
//             int size = q.size();
//             System.out.println(size);
//             List<Integer> level = new ArrayList<Integer>(size);
//             for(int i = 0; i < size;i++){
//                 System.out.println(lr);
//                 int idx = lr ? i : size-i-1;
//                 System.out.println(idx);
//                                 System.out.println("q : "+q);

//                 TreeNode temp = q.peek();
//                 q.poll();
//                 level.set(idx,temp.val);
//                 if(temp.left!=null){
//                     q.add(temp.left);
//                 }
//                 if(temp.right!=null){
//                     q.add(temp.right);
//                 }
//             }
//             lr = !lr;
//             ans.add(level);
//         }
//         return ans;
//     }
// }

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if(root==null)return ans;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        boolean lr = true;
        while(!q.isEmpty()){
            int size = q.size();
            List<Integer> level = new ArrayList<Integer>(size);

            for(int i = 0; i < size;i++){
                int idx = lr ? i : size-i-1;

                TreeNode temp = q.peek();
                q.poll();
                if(lr){
                    level.add(temp.val);
                }else{
                    level.add(0, temp.val);
                }
                
                if(temp.left!=null){
                    q.add(temp.left);
                }
                if(temp.right!=null){
                    q.add(temp.right);
                }
            }
            lr = !lr;
            ans.add(level);
        }
        return ans;
    }
}