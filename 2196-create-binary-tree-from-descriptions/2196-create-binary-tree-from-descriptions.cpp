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
    TreeNode* createBinaryTree(vector<vector<int>>& tree) {
        unordered_map<int,pair<TreeNode*,int>>m;
        for(int i=0;i<tree.size();i++){
            int parent = tree[i][0];
            int child = tree[i][1];
            int left = tree[i][2];
            TreeNode* Parent = NULL;
            TreeNode* Child = NULL;
            if(m.find(parent)==m.end()){
                Parent = new TreeNode(parent);
                m[parent]={Parent,0};
            }else{
                Parent = m[parent].first;
            }
            if(m.find(child)==m.end()){
                Child = new TreeNode(child);
                m[child] = {Child,1} ;
            }else{
                Child = m[child].first;
                m[child].second = 1;
            }
            if(left == 1){
                Parent->left = Child;
            }else Parent->right = Child;
        }
        for(auto x:m){
            if(x.second.second == 0){
                return x.second.first;
            }
        }
        return NULL;
    }
};