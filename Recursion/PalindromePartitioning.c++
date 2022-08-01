class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> ds;
        int n=s.size();
        f(0,n,s,ds,ans);
        return ans;
    }
    void f(int ind,int n,string &s,vector<string> &ds,vector<vector<string>> &ans)
    {
        if(ind==n)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<n;i++)
        {
            if(isPalindrome(ind,i,s))
            {
                string st=s.substr(ind,i-ind+1);
                ds.push_back(st);
                f(i+1,n,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    bool isPalindrome(int l,int h,string &s)
    {
        while(l<h)
        {
            if(s[l++]!=s[h--])return false;
        }
        return true;
    }
};
