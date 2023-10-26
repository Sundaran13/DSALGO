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
    bool solver(TreeNode* root,long long minval,long long  maxval){
        if(root==NULL){
            return true;
        }
        if(root->val<=minval or root->val>=maxval){
            return false;
        }
        return solver(root->left,minval,root->val) and solver(root->right,root->val,maxval);
    }
    bool isValidBST(TreeNode* root) {
        return solver(root,LLONG_MIN,LLONG_MAX);
    }
};