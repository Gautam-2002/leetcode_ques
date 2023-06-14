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
    int dfs(TreeNode* root,int data){{
        if(root==NULL)return INT_MAX;
        int a = INT_MAX;
        int b = a;
        if(root->left){
            a = dfs(root->left,data);
        }
        if(root->right){
            b = dfs(root->right,data);
        }
        return min(abs(root->val-data),min(a,b));
    }
        
    }
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL)return INT_MAX;
        int w = dfs(root->left,root->val);
        int x = dfs(root->right,root->val);
        int y = getMinimumDifference(root->left);
        int z = getMinimumDifference(root->right);
        return min(min(w,x),min(y,z));
    }
};