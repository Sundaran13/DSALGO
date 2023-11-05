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
    vector<TreeNode*> solver(int start,int end){
        vector<TreeNode*> ans;
        if(start>end){
            ans.push_back(NULL);
            return ans;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*>leftsubtree=solver(start,i-1);
            vector<TreeNode*>rightsubtree=solver(i+1,end);
            for(int j=0;j<leftsubtree.size();j++){
                for(int k=0;k<rightsubtree.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left=leftsubtree[j];
                    root->right=rightsubtree[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solver(1,n);
    }
};