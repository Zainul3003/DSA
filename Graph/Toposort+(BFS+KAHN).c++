vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])indegree[it]++;
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++)if(!indegree[i])q.push(i);
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it:adj[node])
	        {
	            indegree[it]--;
	            if(!indegree[it])q.push(it);
	        }
	    }
	    return ans;
	}
