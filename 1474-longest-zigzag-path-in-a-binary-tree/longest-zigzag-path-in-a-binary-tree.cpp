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
    //int pathlen=0;
    int maxpath=0;
    void solver(TreeNode* root,bool left,bool right,int pathlen){
        if(root==NULL){
            return ;
        }
        if(left){
            solver(root->left,false,true,pathlen+1);
            solver(root->right,true,false,1);
        }
        else if(right){
            solver(root->right,true,false,pathlen+1);
            solver(root->left,false,true,1);

        }
        maxpath=max(maxpath,pathlen);
    }
    int longestZigZag(TreeNode* root) {
        solver(root,true,false,0);
        solver(root,false,true,0);
        return maxpath;
    }
};