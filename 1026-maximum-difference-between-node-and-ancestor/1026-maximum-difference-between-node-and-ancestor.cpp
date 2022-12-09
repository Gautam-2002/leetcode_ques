/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diff(TreeNode* root,int val){
        if(root==NULL)return 0;
        int d = abs(root->val-val);
        int a= diff(root->left,val);
        int b = diff(root->right,val);
        return max(d,max(a,b));
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)return 0;
        int val=root->val;
        int y = 0,z=0;
        if(root->left){
            int a = maxAncestorDiff(root->left);
            y=diff(root->left,val);
            y=max(a,y);
        }
        if(root->right){
            int a = maxAncestorDiff(root->right);
            z=diff(root->right,val);
            z=max(a,z);
        }
        return max(y,z);
    }
};