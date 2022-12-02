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
    int maxPathDown(TreeNode*root,int&maxSum){
        if(root==NULL){
            return 0;
        }
        int leftAns=max(0,maxPathDown(root->left,maxSum));
        int rightAns=max(0,maxPathDown(root->right,maxSum));
        maxSum=max(maxSum,leftAns+rightAns+root->val);
        return max(leftAns,rightAns)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        maxPathDown(root,maxSum);
        return maxSum;
    }
};