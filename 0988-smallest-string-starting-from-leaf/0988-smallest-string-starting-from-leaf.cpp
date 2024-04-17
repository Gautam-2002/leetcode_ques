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
    string ans = "";
    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        return ans;
    }
    string alf(int n){
        string arr[] = {"a","b","c","d",
                    "e","f","g","h",
                    "i","j","k","l",
                    "m","n","o","p",
                    "q","r","s","t",
                    "u","v","w","x",
                    "y","z"};
        return arr[n];
    }
    void solve(TreeNode* root,string curr){
        if(root==nullptr)return;
        
        curr = alf(root->val) + curr;
        
        if(!root->left && !root->right){
            if(ans == "" || ans > curr)ans = curr;         
        }
        if(root->left)solve(root->left,curr);
        if(root->right)solve(root->right,curr);  
    }
};