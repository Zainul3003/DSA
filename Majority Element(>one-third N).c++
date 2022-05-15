class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n=nums.size();
        int candidate1=INT_MIN,candidate2=INT_MIN,vote1=0,vote2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==candidate1)
            {
                vote1++;
            }
            else if(nums[i]==candidate2)
            {
                 vote2++;
            }
            else if(vote1==0)
            {
                candidate1=nums[i];
                vote1=1;
            }
            else if(vote2==0)
            {
                candidate2=nums[i];
                vote2=1;
            }
            else
            {
                vote1--;
                vote2--;
            }
        }
        vector<int> ans;
        int count1=0,count2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==candidate1)count1++;
            if(nums[i]==candidate2)count2++;
        }
        if(count1> n/3)ans.push_back(candidate1);
        if(count2> n/3)ans.push_back(candidate2);
        return ans;
    }
};
