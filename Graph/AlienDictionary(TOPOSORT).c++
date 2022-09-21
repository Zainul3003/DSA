class Solution{
    private:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    vector<int> ans;
	    for(int i=0;i<V;i++)
	    {
	         for(auto it:adj[i])
	            {
	                indegree[it]++;
	            }
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
    public:
    string findOrder(string dict[], int N, int K) 
    {
        vector<int> adj[K];
        for(int i=0;i<N-1;i++)
        {
            string s=dict[i];
            string t=dict[i+1];
            int l=min(s.size(),t.size());
            for(int j=0;j<l;j++)
            {
                if(s[j]!=t[j])
                {
                    adj[s[j]-'a'].push_back(t[j]-'a');
                    break;
                }
            }
        }
            vector<int> anss=topoSort(K,adj);
            string ans="";
            for(auto it:anss)
            {
                ans=ans+char(it+'a');
            }
            return ans;
    }
};
