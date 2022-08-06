bool isleaf(Node *node)
    {
        if(node->left==NULL && node->right==NULL)return true;
        return false;
    }
    void left(Node *root,vector<int> &ans)
    {
        Node *cur=root->left;
        while(cur)
        {
            if(!isleaf(cur))ans.push_back(cur->data);
            if(cur->left)cur=cur->left;
            else cur=cur->right;
        }
    }
    void leaf(Node* root,vector<int> &ans)
    {
        if(isleaf(root))ans.push_back(root->data);
        if(root->left)leaf(root->left,ans);
        if(root->right)leaf(root->right,ans);
    }
    void right(Node *root,vector<int> &ans)
    {
        vector<int> temp;
        Node *cur=root->right;
        while(cur)
        {
            if(!isleaf(cur))temp.push_back(cur->data);
            if(cur->right)cur=cur->right;
            else cur=cur->left;
        }
       int n=temp.size();
       for(int i=n-1;i>=0;--i)ans.push_back(temp[i]);
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(!root)return ans;
        if(!isleaf(root))ans.push_back(root->data);
        left(root,ans);
        leaf(root,ans);
        right(root,ans);
        return ans;
    }
