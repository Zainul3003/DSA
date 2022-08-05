class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int diff=INT_MAX;
        for(int i=0;i<n-2;i++)
        {
            int l=i+1,h=n-1,sum=target-nums[i];
            while(l<h)
            {
                if(abs(sum-nums[l]-nums[h])<diff)
                {
                    diff=abs(sum-nums[l]-nums[h]);
                    ans=nums[i]+nums[l]+nums[h];
                }
                if(nums[l]+nums[h]==sum)return target;
                else if(nums[l]+nums[h]<sum)l++;
                else h--;
            }
        }
        return ans;
    }
};
