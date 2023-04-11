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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int hl = q.front().second.first;
            int vl = q.front().second.second;
            q.pop();
            mp[hl][vl].insert(node->val);
            
            if(node->left)
                q.push({node->left,{hl-1,vl+1}});
            if(node->right)
                q.push({node->right,{hl+1,vl+1}});
        }
        for(auto i:mp){
            vector<int> temp;
            for(auto j:i.second){
                // sort(j.second().begin(),j.second.end());
                // ans.push_back(j.second);
                temp.insert(temp.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(temp);
        }
        // for(int i=0;i<ans.size();i++){
        //     sort(ans[i].begin(),ans[i].end());
        // }
        return ans;
    }
};