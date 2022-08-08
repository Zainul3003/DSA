//DFS////////////////////////////////////
private:
    bool DFS(int node,vector<int> adj[],vector<int> &vis,vector<int> &ans)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            DFS(it,adj,vis,ans);
        }
        ans.push_back(node);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            DFS(i,adj,vis,ans);
	        }
	    }
	    reverse(ans.begin(),ans.end());
	    //for(auto i:ans)cout<<i<<" ";
	    return ans;
	}
