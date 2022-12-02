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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(p==root||q==root){
            return root;
        }
        TreeNode*lcaLeft=lowestCommonAncestor(root->left,p,q);
        TreeNode*lcaRight=lowestCommonAncestor(root->right,p,q);
        if(lcaLeft&&lcaRight){
            return root;
        }
        if(lcaLeft){
            return lcaLeft;
        }
        return lcaRight;
    }
};