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
    TreeNode* solver(vector<int>&A,int &i,int bound){
        if(i==A.size() or A[i]>bound){
            return NULL;
        }
        TreeNode* node= new TreeNode(A[i++]);
        node->left=solver(A,i,node->val);
        node->right=solver(A,i,bound);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solver(preorder,i,INT_MAX);
    }
};