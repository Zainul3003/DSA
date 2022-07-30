class Solution
{
    public:
    void solve(stack<int>&st,int c,int n)
    {
        if(c==(n/2))
        {
            st.pop();
            return;
        }
        int element=st.top();
        st.pop();
        solve(st,c+1,n);
        st.push(element);
    }
    void deleteMid(stack<int>&s, int n)
    {
        solve(s,0,n);
    }
};
