vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        if(!root)return ans;
        map<int,int> nodes;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            pair<Node*,int> temp=q.front();
            q.pop();
            Node* node=temp.first;
            int x=temp.second;
            nodes[x]=node->data;
            if(node->left)q.push({node->left,x-1});
            if(node->right)q.push({node->right,x+1});
        }
        for(auto it:nodes)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
