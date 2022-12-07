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
    void solve(TreeNode* root,int x,vector<int> &path,vector<vector<int>> &ans){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            if(x-root->val==0)
                ans.push_back(path);
            return;
        }
        if(root->left){
            path.push_back(root->left->val);
            solve(root->left,x-root->val,path,ans);
            path.pop_back();
        }
        if(root->right){
            path.push_back(root->right->val);
            solve(root->right,x-root->val,path,ans);
            path.pop_back();
        }

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        vector<int>path;
        path.push_back(root->val);
        solve(root,targetSum,path,ans);
        return ans;
    }
};