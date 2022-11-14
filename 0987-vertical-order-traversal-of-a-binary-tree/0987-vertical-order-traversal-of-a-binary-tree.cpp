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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int v=p.second.first;
            int h=p.second.second;
            nodes[v][h].insert(node->val);
            if(node->left){
                q.push({node->left,{v-1,h+1}});
            }
            if(node->right){
                q.push({node->right,{v+1,h+1}});
            }
        }
        for(auto q:nodes){
            vector<int> col;
            for(auto p:q.second){
                col.insert(col.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        //recursive
//     int min = INT_MAX;
//     int max = INT_MIN;
//   void helper(TreeNode* root, unordered_map<int,vector<pair<int,int>>> &m, int i, int h){
//         if(root==NULL)return;
//         m[i].push_back(make_pair(h,root->val));
//         if(i<min)min=i;
//         if(i>max)max=i;
//         helper(root->left,m,i-1,h+1);
//         helper(root->right,m,i+1,h+1);
//     }

//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         unordered_map<int,vector<pair<int,int>>> m;
//         helper(root,m,0,0);
//         vector<vector<int>> ans;
//         for(int i=min;i<=max;i++){
//             sort(m[i].begin(),m[i].end());
//             vector<int> v;
//             for(int j=0;j<m[i].size();j++){
//                 v.push_back(m[i][j].second);
//             }
//             ans.push_back(v);
//         } 
//         return ans;
    }
};