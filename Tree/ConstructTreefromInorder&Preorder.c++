/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)mp[inorder[i]]=i;
        int p=preorder.size();
        int i=inorder.size();
        TreeNode* root=Tree(preorder,0,p-1,inorder,0,i-1,mp);
        return root;
    }
    TreeNode* Tree(vector<int>& preorder,int preStart,int preEnd, vector<int>& inorder,int inStart,int inEnd,map<int,int> &mp)
    {
        if(preStart>preEnd || inStart >inEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int in=mp[root->val];
        int prein=in-inStart;
        root->left=Tree(preorder,preStart+1,preStart+prein,inorder,inStart,in-1,mp);
        root->right=Tree(preorder,preStart+prein+1,preEnd,inorder,in+1,inEnd,mp);
        return root;
    }
};
