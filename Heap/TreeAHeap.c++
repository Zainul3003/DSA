class Solution {
  public:
    int count(struct Node* root)
    {
        if(root==NULL)return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool isCBT(struct Node* root,int i,int n) 
    {
        if(root==NULL)return true;
        if(i>=n)return false;
        return isCBT(root->left,2*i+1,n)&&isCBT(root->right,2*i+2,n) ;
    }
    bool isheap(struct Node* root) 
    {
        if(root==NULL)return true;
        if(root->left)
        {
            if(root->left->data > root->data)return false;
        }
        if(root->right)
        {
            if(root->right->data > root->data)return false;
        }
        return isheap(root->left)&& isheap(root->right) ;
    }
    bool isHeap(struct Node* root) 
    {
        int n=count(root);
        if(isCBT(root,0,n) && isheap(root))return true;
        return false;
    }
};
