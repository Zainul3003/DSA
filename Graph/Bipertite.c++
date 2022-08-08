DFS----------------------

class Solution {
public:
    bool DFS(int node,vector<vector<int>>& graph,vector<int> &color)
    {
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                if(DFS(it,graph,color))return true;
            }
            else if(color[node]==color[it])return true;
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=1;
                if(DFS(i,graph,color))return false;
            }
        }
        return true;
    }
};


BFS-----------------------------------------------------------------
bool isBipartite(int n, vector<int>adj[])
	{
	    int color[n];
	    memset(color,-1,sizeof(color));
	    queue<int> q;
	    for(int i=0;i<n;i++)
	    {
	        if(color[i]==-1)
	        {
	            q.push(i);
        	    color[i]=1;
        	    while(!q.empty())
        	    {
        	        int node=q.front();
        	        q.pop();
        	        for(auto it:adj[node])
        	        {
        	            if(color[it]==-1)
        	            {
        	                color[it]=1-color[node];
        	                q.push(it);
        	            }
        	            else if(color[it]==color[node])return false;
        	        }
	            }
	        }
    	}
	    return true;
	}
