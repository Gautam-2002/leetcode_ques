/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark_parent(unordered_map<TreeNode*,TreeNode*> &mp,TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                mp[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                mp[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;//to track parent
        mark_parent(mp,root);
        
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int lvl = 0;
        while(!q.empty()){
            int size = q.size();
            if(lvl++ == k)break;
            for(int i =0;i<size;i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(mp[current] && !visited[mp[current]]){
                    q.push(mp[current]);
                    visited[mp[current]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            ans.push_back(current->val);
        }
        return ans;
    }
};