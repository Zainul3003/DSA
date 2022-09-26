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
