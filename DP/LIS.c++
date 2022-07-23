USING RECURSION AND MEMOZATION
-------------------------------------------------------------------
class Solution {
public:
    int f(int index,int pre_index,vector<int>& nums,int n,vector<vector<int>> &dp)
    {
        if(index==n)return 0;
        if(dp[index][pre_index+1]!=-1)return dp[index][pre_index+1];
        int length=0+f(index+1,pre_index,nums,n,dp);
        if(pre_index==-1 || nums[index]>nums[pre_index])
        {
            length=max(length,1+f(index+1,index,nums,n,dp));
        }
        return dp[index][pre_index+1]=length;
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,n,dp);
    }
};
--------------------binary search-------------------------
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(temp.back()<nums[i])temp.push_back(nums[i]);
            else
            {
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return temp.size();
    }
};
//==========================================================
top down
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int pre=i-1;pre>=-1;pre--)
            {
                int l=dp[i+1][pre+1];
                if(pre==-1 || nums[i]>nums[pre])
                {
                    l=max(l,1+dp[i+1][i+1]);
                }
                dp[i][pre+1]=l;
            }
        }
        return dp[0][0];
    }
};
//------------------------------------------------------------------
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> dp(n,1),hash(n);
        int maxi=1;
        int lastIndex=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int pre=0;pre<i;pre++)
            {
                if(nums[i]>nums[pre] 1+dp[pre]>dp[i])
                {
                    dp[i]=1+dp[pre];
                    hash[i]=pre;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex)
        {
            lastIndex=hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
