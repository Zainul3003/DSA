class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        set<vector<int>> st;
        unordered_map<int,int> mp;
        for(auto a:nums)mp[a]++;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]--;
            for(int j=i+1;j<n;j++)
            {
                mp[nums[j]]--;
                if(mp[-nums[i]-nums[j]]>0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(-nums[i]-nums[j]);
                    temp.push_back(nums[j]);
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                mp[nums[j]]++;
            }
            mp[nums[i]]++;
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || (i>0 && nums[i-1]!=nums[i]))
            {
                int l=i+1,h=n-1,sum=-nums[i];
                while(l<h)
                {
                    if(nums[l]+nums[h]==sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);
                        ans.push_back(temp);
                        while(l<h && nums[l]==nums[l+1])l++;
                        while(l<h && nums[h]==nums[h-1])h--;
                        l++;h--;
                    }
                    else if(nums[l]+nums[h] <sum)l++;
                    else h--;
                }
            }
        }
        return ans;
    }
};
