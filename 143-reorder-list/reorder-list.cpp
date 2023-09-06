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
    void reorderList(ListNode* head) {
        if(!head or !head->next or !head->next->next)return ;
        stack<ListNode*> my_stack;
        ListNode* ptr=head;
        int size=0;
        while(ptr){
            my_stack.push(ptr);
            size++;
            ptr=ptr->next;
        }
        ListNode* pptr=head;
        for(int i=0;i<size/2;i++){
            ListNode* ele=my_stack.top();
            my_stack.pop();
            ele->next=pptr->next;
            pptr->next=ele;
            pptr=pptr->next->next;
        }
        pptr->next=nullptr;
    }
};