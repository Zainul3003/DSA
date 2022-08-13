class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(!root)return "";
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            if(cur==NULL)ans.append("N,");
            else ans.append(to_string(cur->val)+',');
            if(cur!=NULL)
            {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data.size()==0)return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="N")
            {
                node->left=NULL;
            }
            else
            {
                node->left=new TreeNode(stoi(str));
                q.push(node->left);
            }
            getline(s,str,',');
            if(str=="N")
            {
                node->right=NULL;
            }
            else
            {
                node->right=new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};
