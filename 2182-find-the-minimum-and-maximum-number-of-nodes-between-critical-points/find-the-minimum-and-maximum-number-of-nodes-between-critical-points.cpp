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
    bool iscritical(ListNode* prev, ListNode* node){
        if(prev->val<node->val and node->val>node->next->val)return true;
        if(prev->val>node->val and node->val<node->next->val)return true;
        return false;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mn=INT_MAX,first_crit=-1,prev_crit=INT_MIN,idx=1;
        ListNode* ptr=head->next,*prev=head;
        while(ptr->next){
            if(iscritical(prev,ptr)){
                if(prev_crit>INT_MIN)mn=min(mn,idx-prev_crit);
                if(first_crit==-1)first_crit=idx;
                prev_crit=idx;
            }
            idx++;
            prev=prev->next;
            ptr=ptr->next;
        }
        if(mn==INT_MAX)return {-1,-1};
        return {mn,prev_crit-first_crit};
    }
};