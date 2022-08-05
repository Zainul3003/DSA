//PREORDER////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        if(root==NULL)return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            auto temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right)st.push(temp->right);
            if(temp->left)st.push(temp->left);
        }
        return ans;
    }
};

////////////////POSTORDER///////////////////////////////////////////////
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        if(!root)return ans;
        stack<TreeNode*> st;
        stack<int> s;
        st.push(root);
        while(!st.empty())
        {
            root=st.top();
            s.push(root->val);
            st.pop();
            if(root->left)st.push(root->left);
            if(root->right)st.push(root->right);
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};


/////////////////////////////////////////INORDER..............................................
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        if(!root)return ans;
        stack<TreeNode*> st;
        TreeNode* cur=root;
        while(1)
        {
            if(cur!=NULL)
            {
                st.push(cur);
                cur=cur->left;
            }
            else
            {
                if(st.empty())break;
                cur=st.top();
                st.pop();
                ans.push_back(cur->val);
                cur=cur->right;
            }
        }
        return ans;
    }
};
