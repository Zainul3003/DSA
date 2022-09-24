class Solution {
public:
    string countAndSay(int n)
    {
        if(n==1)return "1";
        if(n==2)return "11";
        string ans="11";
        for(int i=3;i<=n;i++)
        {
            ans+='#';
            string t="";
            int cnt=1;
            for(int j=1;j<ans.size();j++)
            {
                if(ans[j-1]!=ans[j])
                {
                    t+=to_string(cnt);
                    t+=ans[j-1];
                    cnt=1;
                }
                else
                {
                    cnt++;
                }
            }
            ans=t;
        }
        return ans;
    }
};
