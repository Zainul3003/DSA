class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st;
        for(int obj:asteroids)
        {
            if(obj>0)
            {
                st.push(obj);
            }
            else
            {
                while(!st.empty() && st.top()>0 && st.top()<-obj)st.pop();
                if(!st.empty() && st.top()==-obj)st.pop();
                else if(!st.empty() && st.top()>-obj);
                else st.push(obj);
            }
        }
        vector<int> ans(st.size());
        int k=st.size()-1;
        while(k>=0)
        {
            ans[k--]=st.top();
            st.pop();
        }
        return ans;
    }
};
