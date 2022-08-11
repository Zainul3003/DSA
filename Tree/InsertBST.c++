class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(!root)return new TreeNode(val);
        if(val<root->val)root->left=insertIntoBST(root->left,val);
        if(val>root->val)root->right=insertIntoBST(root->right,val);
        return root;
    }
};

-----------------------------------------------------------------------------------


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root==NULL)return new TreeNode(val);
        TreeNode* cur=root;
        while(1)
        {
            if(cur->val >= val)
            {
                if(cur->left !=NULL)
                {
                    cur=cur->left;
                }
                else
                {
                    cur->left=new TreeNode(val);
                    break;
                }
            }
            else
            {
                if(cur->right !=NULL)
                {
                    cur=cur->right;
                }
                else
                {
                    cur->right=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
