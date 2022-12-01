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
    // int height(TreeNode* root){
    //     if(root==NULL){
    //         return 0;
    //     }
    //     int leftHeight=height(root->left);
    //     int rightHeight=height(root->right);
    //     return 1+max(leftHeight,rightHeight);
    // }
    
    //Better approach
    
    pair<int,int> heightDiameter(TreeNode* root){
        if(root==NULL){
            pair<int,int>ans;
            ans.first=0;
            ans.second=0;
            return ans;
        }
        pair<int,int>leftAns=heightDiameter(root->left);
        pair<int,int>rightAns=heightDiameter(root->right);
        int leftDia=leftAns.first;
        int leftHeight=leftAns.second;
        int rightDia=rightAns.first;
        int rightHeight=rightAns.second;
        int height=1+max(leftHeight,rightHeight);
        int dia=max(leftHeight+rightHeight,max(leftDia,rightDia));
        pair<int,int>ans;
        ans.first=dia;
        ans.second=height;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // if(root==NULL){
        //     return 0;
        // }
        // int leftDiameter=diameterOfBinaryTree(root->left);
        // int rightDiameter=diameterOfBinaryTree(root->right);
        // int lh=height(root->left);
        // int rh=height(root->right);
        // return max(lh+rh,max(leftDiameter,rightDiameter));
        
        //better approach
        
        pair<int,int>ans=heightDiameter(root);
        return ans.first;
    }
};