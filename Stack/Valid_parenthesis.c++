class Solution {
public:
    bool isValid(string s) 
    {
        if(s[0]==')' || s[0]=='}' || s[0]==']')return false;
        stack<char> st;
        for(char x:s)
        {
            if(!st.empty() and ( (x==')' && st.top()=='(')|| (x=='}' && st.top()=='{')|| (x==']' && st.top()=='[')))st.pop();
            else st.push(x);
        }
        return !(st.size());
    }
};
