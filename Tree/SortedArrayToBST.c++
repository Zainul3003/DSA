class Solution {
public:
    TreeNode* merger(int l,int h,vector<int>& nums)
    {
        if(h<l)return NULL;
        int m=l+(h-l)/2;
        TreeNode* root=new TreeNode(nums[m]);
        root->left=merger(l,m-1,nums);
        root->right=merger(m+1,h,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        int n=nums.size()-1;
        if(n==0)return NULL;
        return merger(0,n,nums);
    }
};
//////////////////////////////////////////////////


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
    TreeNode* merger(ListNode *head,ListNode *tail)
    {
        if(head==tail)return NULL;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=tail and fast->next!=tail)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode *root=new TreeNode(slow->val);
        root->left=merger(head,slow);
        root->right=merger(slow->next,tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head==NULL)return NULL;
       // if(head->next=NULL)return new TreeNode(head->val);
        return merger(head,NULL);
    }
};
