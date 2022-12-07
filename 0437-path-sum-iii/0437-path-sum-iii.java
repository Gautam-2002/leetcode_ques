class Solution {
    public int pathSum(TreeNode root, int targetSum) {
        if(root==null){
            return 0;
        }
        int x = selfsum(root,targetSum);
        int y = pathSum(root.left,targetSum);
        int z = pathSum(root.right,targetSum);
        
        return x+y+z;
    }
    public int selfsum(TreeNode root,long ts){
        if(root==null)return 0;
        
        int ans=0;
        if(ts-root.val==0){
            ans++;
        }
        int l = selfsum(root.left,ts-root.val);
        int r = selfsum(root.right,ts-root.val);
        
        return ans+l+r;        
    }
}