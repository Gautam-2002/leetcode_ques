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
    void solve(TreeNode* root, int &ans,bool f){
        if(root==NULL)return;
        if(!root->left && !root->right && f){
            ans+=root->val;
        }
        solve(root->left,ans,true);
        solve(root->right,ans,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        if(root==NULL)return ans;
        solve(root->left,ans,true);
        solve(root->right,ans,false);
        return ans;
    }
};