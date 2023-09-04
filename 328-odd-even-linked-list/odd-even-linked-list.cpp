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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL or head->next==NULL or head->next->next==NULL){
            return head;
        }
        ListNode* odd = new ListNode(head->val);
        ListNode* even = new ListNode(head->next->val);
        ListNode* oddptr=odd;
        ListNode* evenptr=even;
        ListNode* ptr=head->next->next;
        int cnt=2;
        while(ptr){
            cnt++;
            if(cnt%2==0){
                ListNode* n=new ListNode(ptr->val);
                evenptr->next=n;
                evenptr=evenptr->next;
            }
            else{
                ListNode* n=new ListNode(ptr->val);
                oddptr->next=n;
                oddptr=oddptr->next;
            }
            if(ptr->next==NULL){
                oddptr->next=even;
            }
            ptr=ptr->next;
        }
        return odd;
    }
};