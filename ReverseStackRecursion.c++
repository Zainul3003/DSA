    void insert(int ele,stack<int> &st)
    {
        if(st.empty())
        {
            st.push(ele);
            return;
        }
        int n=st.top();
        st.pop();
        insert(ele,st);
        st.push(n);
    }
    void rev(stack<int> &st)
    {
        if(st.empty())
        {
            return;
        }
        int ele=st.top();
        st.pop();
        rev(st);
        insert(ele,st);
    }
