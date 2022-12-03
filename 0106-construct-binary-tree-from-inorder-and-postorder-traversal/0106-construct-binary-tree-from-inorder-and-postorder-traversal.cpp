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
    TreeNode * construct(vector<int>inorder,vector<int>postorder,int inStart,int inEnd,int postStart,int postEnd){
        if(postStart>postEnd||inStart>inEnd){
            return NULL;
        }
        int val=postorder[postEnd];
        TreeNode*p=new TreeNode(val);
        int k=0;
        for(int i=inStart;i<=inEnd;i++){
            if(val==inorder[i]){
                k=i;
                break;
            }
        }
        int left=k-inStart;
        p->left=construct(inorder,postorder,inStart,k-1,postStart,postStart+left-1);
        p->right=construct(inorder,postorder,k+1,inEnd,postStart+left,postEnd-1);
        return p;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postStart=0;
        int postEnd=postorder.size()-1;
        int inStart=0;
        int inEnd=inorder.size()-1;
        TreeNode*root=construct(inorder,postorder,inStart,inEnd,postStart,postEnd);
        return root;
    }
};