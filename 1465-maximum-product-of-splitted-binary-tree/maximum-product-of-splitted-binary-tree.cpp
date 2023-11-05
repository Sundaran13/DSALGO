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
    int mod=1e9+7;
    long long ans=0,totalsum=0;
    int solver(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int currsum=root->val+solver(root->left)+solver(root->right);
        ans=max(ans,(totalsum-currsum)*currsum);
        return currsum;
    }
    int maxProduct(TreeNode* root) {
        totalsum=solver(root);
        solver(root);
        return ans%mod;
    }
};