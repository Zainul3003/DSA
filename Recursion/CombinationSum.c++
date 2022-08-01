class Solution {
public:
    void solve(int i,int target,int n,vector<int> &a,vector<int> &ds,vector<vector<int>> &ans)
    {
        if(i==n)
        {
            if(target==0)
             {
                 ans.push_back(ds);
             }
             return;
        }
         
        if(a[i]<=target)
        {
            ds.push_back(a[i]);
            solve(i,target-a[i],n,a,ds,ans);
            ds.pop_back();
        }
        solve(i+1,target,n,a,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        //sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        solve(0,target,n,candidates,ds,ans);
        return ans;
    }
};

//---------------------------------------------------------------------------



class Solution {
public:
    void solve(int ind,int target,int n,vector<int> &a,vector<int> &ds,vector<vector<int>> &ans)
    {
         if(target==0)
         {
             ans.push_back(ds);
             return;
         }
        for(int i=ind;i<n;i++)
        {
            if(a[i]>target)break;
            ds.push_back(a[i]);
            solve(i,target-a[i],n,a,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        solve(0,target,n,candidates,ds,ans);
        return ans;
    }
};
