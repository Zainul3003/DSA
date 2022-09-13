class Solution {
public:
    int trap(vector<int>& height)
    {
        int ans=0;
        int maxRight=0,maxLeft=0;
        int l=0,h=height.size()-1;
        while(l<=h)
        {
            if(height[l]<=height[h])
            {
                if(maxLeft<=height[l])
                {
                    maxLeft=height[l];
                }
                else
                {
                    ans+=maxLeft-height[l];
                }
                l++;
            }
            else
            {
                if(maxRight<=height[h])
                {
                    maxRight=height[h];
                }
                else
                {
                    ans+=maxRight-height[h];
                }
                h--;
            }
        }
        return ans;
    }
};

///////////////////////////////////////////////////////////

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0]=height[0];
        suffix[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            prefix[i]=max(height[i],prefix[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=max(height[i],suffix[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(min(prefix[i],suffix[i])-height[i]);
        }
        return ans;
    }
};
