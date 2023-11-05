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
    vector<int> solver(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        vector<int> leftsubtree=solver(root->left);
        vector<int> rightsubtree=solver(root->right);
        vector<int> options(2,0);
        options[0]=root->val+leftsubtree[1]+rightsubtree[1];
        options[1]=max(leftsubtree[0],leftsubtree[1])+max(rightsubtree[0],rightsubtree[1]);
        return options;
    }
    int rob(TreeNode* root) {
        vector<int> res=solver(root);
        return max(res[0],res[1]);
    }
};