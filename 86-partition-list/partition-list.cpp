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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left=new ListNode(NULL);
        ListNode* point=left;
        ListNode* temp=head;
        while(temp){
            if(temp->val<x){
                ListNode* new1=new ListNode(temp->val);
                ListNode* point1=new1;
                point->next=point1;
                point=point->next;
            }
            temp=temp->next;
        }
        ListNode* right=new ListNode(NULL);
        ListNode* right1=right;
        ListNode* point2=right;
        ListNode* temp1=head;
        while(temp1){
            if(temp1->val>=x){
                ListNode* new1=new ListNode(temp1->val);
                ListNode* point1=new1;
                point2->next=point1;
                point2=point2->next;
            }
            temp1=temp1->next;
        }
        point->next=right1->next;
        return left->next;
    }
};