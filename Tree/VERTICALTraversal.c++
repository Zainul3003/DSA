class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(!root)return ans;
        
        //storing values of nodes in multiset AT location (x,y) using double map
        map<int,map<int,multiset<int>>> nodes;
        
        //queue for traversing BFS manner Treenode* and pair to access x any y cordinates
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        //inserting root and (0,0) cordinate initialy
        q.push({root,{0,0}});
        
        //level order traversal
        while(!q.empty())
        {
            //extract front of the queue
            auto it=q.front();
            q.pop();
            
            //current node
            TreeNode* node=it.first;
            
            //x-y of the current node
            int x=it.second.first,y=it.second.second;
            
            //pushing the vales in our multiset using 2D maps
            nodes[x][y].insert(node->val);
            
            //insert next node in the queue as BFS
            if(node->left)q.push({node->left,{x-1,y+1}});
            if(node->right)q.push({node->right,{x+1,y+1}});
        }
        for(auto it:nodes)
        {
            vector<int> temp;
            for(auto x:it.second)
            {
                temp.insert(temp.end(),x.second.begin(),x.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
