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
    bool isLeaf(TreeNode* root){
        if(!root->left && !root->right){
            return true;
        }
        return false;
    }
    void solve(TreeNode* root,vector<int> path,vector<vector<int>>&ans,int ts){
        if(root==NULL)return;
        path.push_back(root->val);
        if(isLeaf(root)){
            if(ts-root->val==0){
                ans.push_back(path);
            }
            return;
        }
        solve(root->left,path,ans,ts-root->val);
        solve(root->right,path,ans,ts-root->val);        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        vector<int>path;
        path.push_back(root->val);
        if(isLeaf(root)){
            if(targetSum-root->val==0){
                ans.push_back(path);
            }
        }
        solve(root->left,path,ans,targetSum-root->val);
        solve(root->right,path,ans,targetSum-root->val);
        return ans;
    }
};