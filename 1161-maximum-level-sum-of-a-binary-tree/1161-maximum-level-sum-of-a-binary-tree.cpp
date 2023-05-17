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