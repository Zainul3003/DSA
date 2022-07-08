class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        int carry=0;
        while(l1 || l2 || carry)
        {
            int sum=0;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            ListNode* node=new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
            carry=sum/10;
        }
        return ans->next;
    }
};
