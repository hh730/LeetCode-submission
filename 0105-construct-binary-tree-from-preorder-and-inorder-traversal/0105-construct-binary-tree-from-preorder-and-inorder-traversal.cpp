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
    TreeNode * construct(vector<int>preorder,vector<int>inorder,int preStart,int preEnd,int inStart,int inEnd){
        if(preStart>preEnd||inStart>inEnd){
            return NULL;
        }
        int val=preorder[preStart];
        TreeNode*p=new TreeNode(val);
        int k=0;
        for(int i=inStart;i<=inEnd;i++){
            if(inorder[i]==val){
                k=i;
                break;
            }
        }
        int lft=k-inStart;
        p->left=construct(preorder,inorder,preStart+1,preStart+lft,inStart,k-1);
        p->right=construct(preorder,inorder,preStart+lft+1,preEnd,k+1,inEnd);
        return p;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart=0;
        int preEnd=preorder.size()-1;
        int inStart=0;
        int inEnd=inorder.size()-1;
        TreeNode*root=construct(preorder,inorder,preStart,preEnd,inStart,inEnd);
        return root;
    }
};