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
    int checkBalanced(TreeNode* root,bool& flag){
        if(root==NULL){
            return 0;
        }
        int leftHeight=checkBalanced(root->left,flag);
        int rightHeight=checkBalanced(root->right,flag);
        if(abs(rightHeight-leftHeight)>1){
            flag=false;
        }
        return 1+max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool flag=true;
        checkBalanced(root,flag);
        return flag;
    }
};