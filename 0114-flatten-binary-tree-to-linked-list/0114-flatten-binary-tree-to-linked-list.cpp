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
    void helper(TreeNode*root,vector<TreeNode*>&pre){
        if(root==NULL){
            return;
        }
        pre.push_back(root);
        helper(root->left,pre);
        helper(root->right,pre);
        return;
    }
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            return;
        }
        vector<TreeNode*>pre;
        TreeNode*newRoot=root;
        helper(root,pre);
        for(int i=0;i<pre.size();i++){
            root->left=NULL;
            root->right=pre[i];
            root=root->right;
        }
        root=newRoot;
        return;
    }
};