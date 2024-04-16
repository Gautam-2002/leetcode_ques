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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* t = new TreeNode(val);
            t->left = root;
            root = t;
            return root;
        }
        solve(root,val,depth,1);
        return root;
    }
    void solve(TreeNode* root, int n ,int d, int lvl){
        if(root==nullptr || lvl >= d)return;
        if(lvl == d-1){
            TreeNode *t1=NULL,*t2=NULL;
            if(root->left)
                t1 = root->left;
            if(root->right)
                t2 = root->right;
            root->left = new TreeNode(n);
            root->right = new TreeNode(n);
            if(t1)
                root->left->left = t1;
            if(t2)
                root->right->right = t2;
            return;
        }
        solve(root->left,n,d,lvl+1);
        solve(root->right,n,d,lvl+1);
    }
};