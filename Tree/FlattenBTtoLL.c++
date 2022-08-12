class Solution {
public:
    void flatten(TreeNode* root) 
    {
        stack<TreeNode*> st;
        if(root)st.push(root);
        while(!st.empty())
        {
            TreeNode* cur=st.top();
            st.pop();
            if(cur->right)st.push(cur->right);
            if(cur->left)st.push(cur->left);
            if(!st.empty())
            {
                cur->right=st.top();
            }
            cur->left=NULL;
        }
    }
};


//////////////////////////////////////////////////////////////////////
Node *pre=NULL;
    void flatten(Node *root)
    {
        if(!root)return;
        flatten(root->right);
        flatten(root->left);
        root->right=pre;
        root->left=NULL;
        pre=root;
    }
