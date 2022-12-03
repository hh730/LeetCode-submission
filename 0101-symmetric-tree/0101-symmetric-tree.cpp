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
    bool isSymmetricHelper(TreeNode* root1,TreeNode*root2){
        if(root1==NULL&&root2==NULL){
            return true;
        }
        if(root1==NULL&&root2!=NULL){
            return false;
        }
        if(root1!=NULL&&root2==NULL){
            return false;
        }
        if(root1->val!=root2->val){
            return false;
        }
        bool isLeft=isSymmetricHelper(root1->left,root2->right);
        bool isRight=isSymmetricHelper(root1->right,root2->left);
        return isLeft&&isRight;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return isSymmetricHelper(root->left,root->right);
        // if(root->left->val!=root->right->val){
        //     return false;
        // }
        // bool isLeftSymmetric=isSymmetric(root->left);
        // bool isRightSymmetric=isSymmetric(root->right);
        // return isLeftSymmetric&&isRightSymmetric;
    }
};