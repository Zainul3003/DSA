class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<4)return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int l=j+1,h=n-1;
                long t1=target-nums[i],t=t1-nums[j];
                while(l<h)
                {
                    if(nums[l]+nums[h]<t)l++;
                    else if(nums[l]+nums[h]>t)h--;
                    else
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        ans.push_back(temp);
                        while(l<h && nums[l]==nums[l+1])l++;
                        while(l<h && nums[h]==nums[h-1])h--;
                        l++;
                        h--;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1])++j;
            }
             while(i+1<n && nums[i]==nums[i+1])++i;
        }
        return ans;
    }
};
