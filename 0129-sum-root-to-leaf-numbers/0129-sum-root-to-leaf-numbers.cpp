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
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
    int solve(TreeNode* root, int v){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr){
            return v*10 + root->val;
        }
        
        int x = solve(root->left, v*10 + root->val);
        int y = solve(root->right, v*10 + root->val);
        // cout<<x<<"*"<<y<<endl;
        return x+y;
    }
};