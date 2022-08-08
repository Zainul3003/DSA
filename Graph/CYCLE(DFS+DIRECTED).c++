class Solution {
public:
    bool cycle(int node,vector<int> adj[],vector<int> &vis,vector<int> &dfs)
    {
        vis[node]=1;
        dfs[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(cycle(it,adj,vis,dfs)==true)return true;
            }
            else if(vis[it]==1 and dfs[it]==1)return true;
        }
        dfs[node]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) 
    {
        int e=prerequisites.size();
        vector<int> adj[n];
        for(int i=0;i<e;i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> vis(n,0),dfs(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(cycle(i,adj,vis,dfs)==true)return false;
            }
        }
        return true;
    }
};
