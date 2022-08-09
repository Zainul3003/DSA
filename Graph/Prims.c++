Brute we use to find mininum of key of not visited node so it takes quadratic complexity that is simplified by log N od the priority queue.

int spanningTree(int V, vector<vector<int>> adj[])
    {
        int key[V];
        bool MST[V];
        int parent[V];
        for(int i=0;i<V;i++)key[i]=INT_MAX,MST[i]=false,parent[i]=-1;
        //min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        key[0]=0;
        parent[0]=-1;
        pq.push({0,0});
        while(!pq.empty())
        {
            int u=pq.top().second;
            pq.pop();
            MST[u]=true;
            for(auto it:adj[u])
            {
                int v=it[0];
                int w=it[1];
                if(MST[v]==false && w<key[v])
                {
                    key[v]=w;
                    parent[v]=u;
                    pq.push({key[v],v});
                }
            }
        }
        for(int i=1;i<V;i++)cout<<parent[i]<<"___>"<<i<<endl;
        int sum=0;
        for(int i=0;i<V;i++)sum+=key[i];
        return sum;
    }
