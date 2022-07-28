int getMaxArea(vector<int> &arr, int n)
    {
        int maxA=0;
        stack<int> st;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && ( i==n || arr[st.top()]>=arr[i]))
            {
                int h=arr[st.top()];
                st.pop();
                int wid;
                if(st.empty())wid=i;
                else wid=i-st.top()-1;
                maxA=max(maxA,h*wid);
               
            }
            st.push(i);
        }
        return maxA;
    }
    int maxArea(int M[MAX][MAX], int n, int m) 
    {
        int ans=0;
        vector<int> h(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j])h[j]++;
                else h[j]=0;
            }
            ans=max(ans,getMaxArea(h,m));
        }
        return ans;
    }
