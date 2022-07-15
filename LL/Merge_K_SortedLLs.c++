class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        if(K==0)return NULL;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<K;i++)
        {
            Node* temp=arr[i];
            while(temp!=NULL)
            {
                pq.push(temp->data);
                temp=temp->next;
            }
        }
        Node* dummy=new Node(-1);
        Node* head=dummy;
        while(!pq.empty())
        {
            Node* node=new Node(pq.top());
            pq.pop();
            head->next=node;
            head=node;
        }
        return dummy->next;
    }
};
