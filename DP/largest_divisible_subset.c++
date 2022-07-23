class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),hash(n);
        int maxi=1;
        int lastIndex=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int pre=0;pre<i;pre++)
            {
                if(nums[i]%nums[pre]==0 && 1+dp[pre]>dp[i])
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
