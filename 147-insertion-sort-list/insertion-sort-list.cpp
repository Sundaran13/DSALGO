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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode *pre=dummy,*curr=head;
        while(curr){
            if(curr->next and curr->next->val<curr->val){
                while(pre->next and pre->next->val<curr->next->val){
                    pre=pre->next;
                }
                ListNode * temp=pre->next;
                pre->next=curr->next;
                curr->next=curr->next->next;
                pre->next->next=temp;
                pre=dummy;
            }
            else{
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};