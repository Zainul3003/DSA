int findCeil(Node* root, int x) 
{
    if(root == NULL)return -1;
    int Ceil=-1;
    while(root!=NULL)
    {
        if(root->data==x)return x;
        else if(root->data > x)
        {
            Ceil=root->data;
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    return Ceil;
}
