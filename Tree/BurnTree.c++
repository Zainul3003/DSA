class Solution {
  private:
    void make_parent(Node* root,unordered_map<Node*,Node*> &parent,Node* &target,int t)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            root=q.front();
            q.pop();
            if(root->data==t)target=root;
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
  public:
    int minTime(Node* root, int t) 
    {
        if(!root)return 0;
        Node* target=NULL;
        unordered_map<Node*,Node*> parent;
        make_parent(root,parent,target,t);
        unordered_map<Node*,bool> vis;
        queue<Node*> q;
        q.push(target);
        vis[target]=true;
        int ans=0;
        while(!q.empty())
        {
            int n=q.size();
            ans++;
            for(int i=0;i<n;i++)
            {
                Node* cur=q.front();
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
        // not considering node itself
        return ans-1;
    }
