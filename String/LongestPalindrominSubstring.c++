Odd even length all substr method O(N2) and O(1) space
string longestPalin (string s)
    {
       int n=s.size();
       int start=0,max=1;
       for(int i=1;i<n;i++)
       {
           int l=i-1;
           int r=i;
           while(l>=0 and r<n and s[l]==s[r])
           {
               if(r-l+1> max)
               {
                   max=r-l+1;
                   start=l;
               }
               l--;
               r++;
           }
           l=i-1;
           r=i+1;
           while(l>=0 and r<n and s[l]==s[r])
           {
               if(r-l+1> max)
               {
                   max=r-l+1;
                   start=l;
               }
               l--;
               r++;
           }
       }
       return s.substr(start,max);
 }
//////////////////////////////////////////////////////////////////
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n=s.size();
        if(n==1)return s;
        vector<vector<int>> dp(n,vector<int>(n,0));
        int len=1,start=0;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                start=i;
                len=2;
            }
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(s[i]==s[j] and dp[i+1][j-1]==1)
                {
                    dp[i][j]=1;
                    if(k > len)
                    {
                        len=k;
                        start=i;
                    }
                }
            }
        }
        cout<<len<<endl;
        return s.substr(start,len);
    }
};
