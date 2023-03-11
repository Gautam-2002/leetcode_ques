/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* node;
    // solve is like inorder as inorder of bst is sorted
    TreeNode* solve(int s,int e){
        if(s > e)
            return NULL;
        int mid = s + (e-s)/2;
        TreeNode* left = solve(s,mid-1);
        
        TreeNode* root = new TreeNode(node->val);
        root->left = left;
        node = node->next;
        
        TreeNode* right = solve(mid+1,e);
        root->right = right;
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        int len = 0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        node = head;
        return solve(0,len-1);
    }
};
