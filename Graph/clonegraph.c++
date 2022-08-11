class Solution {
public:
    unordered_map<Node* , Node*> mp;
    Node* cloneGraph(Node* node)
    {
        if(node==NULL)return node;
        if(mp.find(node)==mp.end())
        {
            mp[node]=new Node(node->val);
            for(auto it:node->neighbors)
            {
                mp[node]->neighbors.push_back(cloneGraph(it));
            }
        }
        return mp[node];
    }
};
//BFS==================================
class Solution {
public:
    unordered_map<Node* , Node*> mp;
    Node* cloneGraph(Node* node)
    {
        if(node==NULL)return node;
        queue<Node*> q;
        q.push(node);
        mp[node]=new Node(node->val);
        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();
            for(auto it:temp->neighbors)
            {
                if(mp.find(it)==mp.end())
                {
                    mp[it]=new Node(it->val);
                    q.push(it);
                }
                mp[temp]->neighbors.push_back(mp[it]);
            }
                
        }
        return mp[node];
    }
};
