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
    long long dfs(TreeNode* root){
        if(root==NULL)return 0;
        long long x = root->val;
        long long y = dfs(root->left);
        long long z = dfs(root->right);
        return (x+y+z);
    }
    long long maxmul(TreeNode* root,long long total,long long &ans){
        if(root==NULL)return 0;
        long long subtree = 0;
        subtree += maxmul(root->left,total,ans);
        subtree += maxmul(root->right,total,ans);
        subtree += root->val;
        if(subtree*(total-subtree)>ans)
            ans = subtree*(total-subtree);
        return subtree;
    }
    int maxProduct(TreeNode* root) {
        // if(root==NULL)return 0;
        long long total = dfs(root);
        long long ans = 0;
        maxmul(root,total,ans);
        return (ans%1000000007);
    }
};