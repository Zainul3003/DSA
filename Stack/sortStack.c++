void insert(stack<int> &st,int x)
{
    if(st.empty() || st.top()<x)
    {
        st.push(x);
        return;
    }
    int ele=st.top();
    st.pop();
    insert(st,x);
    st.push(ele);
}
void sortStack(stack<int> &s)
{
	if(s.empty())return ;
   int element=s.top();
   s.pop();
   sortStack(s);
   insert(s,element);
}
