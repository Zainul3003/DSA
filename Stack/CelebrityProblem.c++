int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i=0;i<n;i++)st.push(i);
        while(st.size()>1)
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(M[a][b]==1)st.push(b);
            else st.push(a);
        }
        int ans=st.top();
        int zero=0,one=0;
        for(int i=0;i<n;i++)if(M[ans][i]==0)zero++;
        
        if(zero!=n)return -1;
        
        for(int i=0;i<n;i++)if(M[i][ans]==1)one++;
        
        if(one!=n-1)return -1;
        
        return ans;
    }
