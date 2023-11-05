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
class Nodevalue{
public:
    int minNode,maxNode,maxSum;
    Nodevalue(int minNode,int maxNode,int maxSum){
        this->minNode=minNode;
        this->maxNode=maxNode;
        this->maxSum=maxSum;
    }
};
class Solution {
public:
    int sum=0;
    Nodevalue solver(TreeNode* root){
        if(root==NULL)return Nodevalue(INT_MAX,INT_MIN,0);
        auto left=solver(root->left);
        auto right=solver(root->right);
        if(left.maxNode<root->val and right.minNode>root->val){
            sum=max(sum,root->val+left.maxSum+right.maxSum);
            return Nodevalue(min(root->val,left.minNode),max(root->val,right.maxNode),root->val+left.maxSum+right.maxSum);
        }
        return Nodevalue(INT_MIN,INT_MAX,max(left.maxSum,right.maxSum));
    }
    int maxSumBST(TreeNode* root) {
        solver(root);
        return sum>0 ? sum : 0;
    }
};