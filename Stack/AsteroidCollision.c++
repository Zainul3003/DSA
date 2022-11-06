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
                while(!st.empty() && st.top()>0 && st.top()<-obj)st.pop();  // right moving destroyed
                if(!st.empty() && st.top()==-obj)st.pop();  //both desroyed
                else if(!st.empty() && st.top()>-obj);   //dont add in stack as left moving destroyed
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
