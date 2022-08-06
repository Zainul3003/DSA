class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(!root)return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=1;
        while(!q.empty())
        {
            int n=q.size();
            int mm=q.front().second;
            int first,last;
            for(int i=0;i<n;i++)
            {
                auto temp=q.front();
                q.pop();
                long long cur=temp.second-mm;
                TreeNode* node=temp.first;
                if(i==0)first=cur;
                if(i==n-1)last=cur;
                if(node->left)q.push({node->left,cur*2+1});
                if(node->right)q.push({node->right,cur*2+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};
