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
    void solve(TreeNode* root,long long ts,vector<int>&path,int &ans){
        if(root==NULL)return;
        path.push_back(root->val);
        
        if(root->left)
            solve(root->left,ts,path,ans);
        if(root->right)
            solve(root->right,ts,path,ans);
        int n = path.size()-1;
        for(int i=n;i>=0;i--){
            if(ts-path[i]==0){
                ans++;
                // break;
            }
            ts-=path[i];
        }
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        vector<int> path;
        long long t = targetSum;
        solve(root,t,path,cnt);
        return cnt;
    }
};