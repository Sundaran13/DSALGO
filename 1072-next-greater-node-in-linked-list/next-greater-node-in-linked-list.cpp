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
class Solution {
public:
    int getcount(ListNode* head){
        int res=0;
        while(head){
            head=head->next;
            res++;
        }
        return res;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        int n=getcount(head);
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        int i=0;
        while(head){
            while(!st.empty() and st.top().first<head->val){
                int idx=st.top().second;
                st.pop();
                ans[idx]=head->val;
            }
            st.push({head->val,i++});
            head=head->next;
        }
        return ans;
    }
};