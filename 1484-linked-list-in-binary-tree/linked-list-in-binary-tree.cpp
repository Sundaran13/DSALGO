/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int size(ListNode* head){
        int cnt=0;
        while(head->next!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    map<pair<ListNode*,TreeNode*>,bool> dp;
    bool solver(ListNode* head,TreeNode* root){
        if(head==NULL){
            return true;
        }
        if(root==NULL){
            return false;
        }
        if(dp.count({head,root})){
            return dp[{head,root}];
        }
        return dp[{head,root}]=head->val==root->val and (solver(head->next,root->left) or solver(head->next,root->right));
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL){
            return false;
        }
        return solver(head,root) or isSubPath(head,root->left) or isSubPath(head,root->right);
    }
};