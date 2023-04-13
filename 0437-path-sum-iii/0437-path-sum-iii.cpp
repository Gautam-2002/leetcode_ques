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
    int solve(TreeNode* root,int ts,long long prefix,unordered_map<long long,int> &memo){
        if(root==nullptr)return 0;
        
        int ans = 0;
        prefix += root->val;
        ans += memo[prefix-ts];
        memo[prefix]++;
        
        ans += solve(root->left,ts,prefix,memo);
        ans += solve(root->right,ts,prefix,memo);
        
        memo[prefix]--;
        
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return 0;
        unordered_map<long long,int> memo;
        memo[0]=1;
        return solve(root,targetSum,0,memo);
    }
};