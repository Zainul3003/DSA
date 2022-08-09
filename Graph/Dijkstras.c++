vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector <int> dis(V,1e9);
        //priority_queue for pair of distance ,node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,S});
        dis[S]=0;
        while(!pq.empty())
        {
            int node=pq.top().second;
            int cd=pq.top().first;
            pq.pop();
            for(auto it:adj[node])
            {
                if(dis[node]+it[1] < dis[it[0]])
                {
                    dis[it[0]]=dis[node]+it[1];
                    pq.push({dis[it[0]],it[0]});
                }
            }
        }
        return dis;
    }
