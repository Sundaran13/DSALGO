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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* root=new ListNode(0);
        root->next=head;
        unordered_map<int,ListNode*>mp;
        mp[0]=root;
        int ac=0;
        while(head!=NULL){
            ac+=head->val;
            if(mp.find(ac)!=mp.end()){
                ListNode* prev=mp[ac];
                ListNode* start=prev;

                int aux=ac;
                while(prev!=head){
                    prev=prev->next;
                    aux+=prev->val;
                    if(prev!=head)mp.erase(aux);
                }
                start->next=head->next;
            }
            else{
                mp[ac]=head;
            }
            head=head->next;
        }
        return root->next;
    }
};