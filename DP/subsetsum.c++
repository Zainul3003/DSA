class Solution{   
public: 
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,0));
        for(int i=0;i<n;i++)dp[i][0]=1;
        dp[0][arr[0]]=1;
        for(int i=1;i<n;i++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool nottake=dp[i-1][target];
                bool take=false;
                if(target>=arr[i])take=dp[i-1][target-arr[i]];
                dp[i][target]=nottake or take;
            }
        }
        return dp[n-1][sum];
    }
};
