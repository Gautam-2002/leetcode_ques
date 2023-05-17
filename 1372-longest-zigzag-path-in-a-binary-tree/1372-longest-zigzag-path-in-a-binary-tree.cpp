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
    int maxpath = 0;
    void dfs(TreeNode* node,bool goleft,int steps){
        if(node==NULL)
            return;
        
        maxpath = max(maxpath,steps);
        
        if(goleft){
            dfs(node->left,false,steps+1);
            dfs(node->right,true,1);
        }
        if(!goleft){
            dfs(node->right,true,steps+1);
            dfs(node->left,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,false,0);
        dfs(root,true,0);
        return maxpath;
    }
};


// TLE CODE :
// class Solution {
// public:
//     int solve(TreeNode* root,int dir){
//         if(root==NULL)return 0;
        
//         int a=1,b=1;
//         if(dir!=0){
//             a += solve(root->left,0);
//         }
//         if(dir!=1){
//             b += solve(root->right,1);
//         }
//         return max(a,b);
//     }
//     int longestZigZag(TreeNode* root) {
//         int x = max(solve(root->left,0),solve(root->right,1));
//         int y=0,z=0;
//         if(root->left)
//             y = longestZigZag(root->left);
//         if(root->right)
//             z = longestZigZag(root->right);
//         int ans = max(x,max(y,z));
//         return ans;
//     }
// };