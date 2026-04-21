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
    void inorder(TreeNode* root,vector<TreeNode*>&vec){
        if(!root) return;
        inorder(root->left,vec);
        vec.push_back(root);
        inorder(root->right,vec);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>vec;
        inorder(root,vec);
        int first=-1,second=-1;
        for(int i=0;i<vec.size()-1;i++){
            if(vec[i]->val>vec[i+1]->val){
                first = i;
                break;
            }
        }
        cout<<first;
       second = first + 1; // Default for adjacent swaps
        for (int i = first + 1; i < vec.size(); i++) {
            if (vec[i]->val < vec[first]->val) {
                second = i;
            }
        }

        int temp = vec[first]->val;
        vec[first]->val = vec[second]->val;
        vec[second]->val= temp;       
    }
};