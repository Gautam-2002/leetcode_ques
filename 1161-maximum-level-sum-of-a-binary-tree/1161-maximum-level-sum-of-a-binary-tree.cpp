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
    int maxLevelSum(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int sum=0;
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp==NULL){
                ans.push_back(sum);
                sum=0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                sum+=tmp->val;
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
        }
        pair<int,int> res={INT_MIN,-1};
        for(int i=0;i<ans.size();i++){
            if(ans[i]>res.first){
                res = {ans[i],i+1};
            }
        }
        return res.second;
    }
};

// class Solution {
// public:
//     void dfs(TreeNode* node, int level, vector<int>& sumOfNodesAtLevel) {
//         if (node == nullptr) {
//             return;
//         }

//         if (sumOfNodesAtLevel.size() == level) {
//             sumOfNodesAtLevel.push_back(node->val);
//         } else {
//             sumOfNodesAtLevel[level] += node->val;
//         }

//         dfs(node->left, level + 1, sumOfNodesAtLevel);
//         dfs(node->right, level + 1, sumOfNodesAtLevel);
//     }

//     int maxLevelSum(TreeNode* root) {
//         vector<int> sumOfNodesAtLevel;
//         dfs(root, 0, sumOfNodesAtLevel);

//         int maxSum = INT_MIN;
//         int ans = 0;

//         for (int i = 0; i < sumOfNodesAtLevel.size(); i++) {
//             if (maxSum < sumOfNodesAtLevel[i]) {
//                 maxSum = sumOfNodesAtLevel[i];
//                 ans = i + 1;
//             }
//         }

//         return ans;
//     }
// };


// class Solution {
// public:
//     int maxLevelSum(TreeNode* root) {
//         int maxSum = INT_MIN;
//         int ans = 0, level = 0;

//         queue<TreeNode*> q;
//         q.push(root);

//         while (!q.empty()) {
//             level++;
//             int sumAtCurrentLevel = 0;
//             // Iterate over all the nodes in the current level.
//             for (int sz = q.size(); sz > 0; --sz) {
//                 TreeNode* node = q.front();
//                 q.pop();
//                 sumAtCurrentLevel += node->val;

//                 if (node->left != nullptr) {
//                     q.push(node->left);
//                 }
//                 if (node->right != nullptr) {
//                     q.push(node->right);
//                 }
//             }

//             if (maxSum < sumAtCurrentLevel) {
//                 maxSum = sumAtCurrentLevel;
//                 ans = level;
//             }
//         }

//         return ans;
//     }
// };