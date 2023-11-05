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
    #define nocam 0
    #define hascam 2
    #define noneed 1
    int ans=0;
    int solver(TreeNode* root){
        if(!root)return noneed;
        int l=solver(root->left);
        int r=solver(root->right);
        if(l==nocam or r==nocam){
            ans++;
            return hascam;
        }
        else if(l==hascam or r==hascam){
            return noneed;
        }
        else{
            return nocam;
        }
    }
    int minCameraCover(TreeNode* root) {
        if(solver(root)==nocam)ans++;
        return ans;
    }
};