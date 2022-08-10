class Solution {
  public:
    void BFS(int node,vector<int> adj[],vector<int>&vis)
    {
        queue<int> q;
        q.push(node);
        vis[node]=1;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto it:adj[u])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) 
    {
        int ans=0;
        vector<int> vis(V+1,0);
        vector<int> adl[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(i!=j && adj[i][j]==1)
                {
                    adl[i].push_back(j);
                    adl[j].push_back(i);
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                ans++;
                BFS(i,adl,vis);
            }
        }
        return ans;
    }
};
