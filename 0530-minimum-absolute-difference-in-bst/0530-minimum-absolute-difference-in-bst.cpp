class Solution {
public:
//     O(N*N)----time
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
// class Solution {
// public:
//     O(N)----time
//     int minDifference = INT_MAX;
//     // Initially, it will be null.
//     TreeNode* prevNode;
        
//     void inorderTraversal(TreeNode* node) {
//         if (node == NULL) {
//             return;
//         }
        
//         inorderTraversal(node->left);
//         // Find the difference with the previous value if it is there.
//         if (prevNode != NULL) {
//             minDifference = min(minDifference, node->val - prevNode->val);
//         }
//         prevNode = node;
//         inorderTraversal(node->right);
//     }
    
//     int getMinimumDifference(TreeNode* root) {
//         inorderTraversal(root);
//         return minDifference;
//     }
// };