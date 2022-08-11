	    vector<int> dis(n,1e9);
	    for(int i=0;i<n-1;i++)
	    {
	        for(auto edge:edges)
	        {
	                int u=edge[0];
			int v=edge[1];
			int wt=edge[2];
			if(dis[v]>dis[u]+wt)
			{
			    dis[v]=dis[u]+wt;
			}
	        }
	    }
	    for(auto edge:edges)
	    {
	        int u=edge[0];
    	        int v=edge[1];
    	        int wt=edge[2];
    	        if(dis[v]>dis[u]+wt)
    	        {
    	            return 1;
    	        }
	    }
	    return 0;
