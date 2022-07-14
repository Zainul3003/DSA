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
    ListNode* rev(ListNode* head)
    {
        if(head==NULL)return head;
        ListNode* cur=head;
        ListNode* pre=NULL,*nxt=NULL;
        while(cur!=NULL)
        {
            nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) 
    {
        if(head->next==NULL)return true;
        ListNode * slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=rev(slow);
        fast=head;
        while(slow!=NULL)
        {
            if(slow->val !=fast->val)return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};
