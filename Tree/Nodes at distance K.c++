class Solution {
public:
    void make_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            root=q.front();
            q.pop();
            if(root->left)
            {
                parent[root->left]=root;
                q.push(root->left);
            }
            if(root->right)
            {
                parent[root->right]=root;
                q.push(root->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        if(!root)return {};
        unordered_map<TreeNode*,TreeNode*> parent;
        make_parent(root,parent);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int dis=0;
        while(!q.empty())
        {
            int n=q.size();
            if(dis==k)break;
            dis++;
            for(int i=0;i<n;i++)
            {
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left && !vis[cur->left])
                {
                    q.push(cur->left);
                    vis[cur->left]=true;
                }
                if(cur->right && !vis[cur->right])
                {
                    q.push(cur->right);
                    vis[cur->right]=true;
                }
                if(parent[cur] && !vis[parent[cur]])
                {
                    q.push(parent[cur]);
                    vis[parent[cur]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            ans.push_back(cur->val);
        }
        return ans;
    }
};
